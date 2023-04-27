#include <stdio.h>
#include <assert.h>

#define MAX_CELSIUS_THRESHOLD 300 //Req missing: What should be the MIN/MAX temperature thresholds for returning a "not-ok" status?

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    int result;
    if (celcius > MAX_CELSIUS_THRESHOLD) 
    {
        result = 500;
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    } 
    else 
    {
        result = 200;
    }
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return result;
}

float convertFarenheitToCelcius(float farenheit) {
    return (farenheit - 32) * 5 / 9;
}

void alertInCelcius(float farenheit) {
    float celcius = convertFarenheitToCelcius(farenheit);
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(400.5);
    assert(alertFailureCount == 0);
    alertInCelcius(303.6);
    assert(alertFailureCount == 0);
    alertInCelcius(571.9);
    assert(alertFailureCount == 0);
    alertInCelcius(572);
    assert(alertFailureCount == 0);
    alertInCelcius(572.1);
    assert(alertFailureCount == 1);
    alertInCelcius(932);
    assert(alertFailureCount == 2);
    alertInCelcius(0);
    assert(alertFailureCount == 2);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}