#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
const int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
const int numberOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]);
const int totalColors = numberOfMajorColors * numberOfMinorColors;

void TestCorrectPairNumber(int pairNumber) {
    static int correctPairNumberIdx = 1;
    assert(pairNumber == correctPairNumberIdx++);
    assert(pairNumber <= totalColors);
    assert(pairNumber != 0);
}

int GetPairNumberFromIndexes(int majorIdx, int minorIdx) {
    return (majorIdx * numberOfMajorColors) + (minorIdx + 1);
}

int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < numberOfMajorColors; i++) {
        for(j = 0; j < numberOfMinorColors; j++) {
            printf("%d\t%s\t%s\n", GetPairNumberFromIndexes(i, j), majorColor[i], minorColor[i]);
            TestCorrectPairNumber(GetPairNumberFromIndexes(i, j));
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == totalColors);
    printf("All is well (maybe!)\n");
    return 0;
}