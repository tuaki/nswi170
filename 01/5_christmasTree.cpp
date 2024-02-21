#include <iostream>

using namespace std;

const char* ORNAMENT = "@";

void printChars(int amount, char character) {
    for (int i = 0; i < amount; i++)
        cout << character;
}

void printCenteredTreeLine(int starIndex, int zeroIndexPadding, bool ornament) {
    printChars(zeroIndexPadding - starIndex - (ornament ? 1 : 0), ' ');
    if (ornament)
        cout << ORNAMENT;

    printChars(2 * starIndex + 1, '*');

    if (ornament)
        cout << ORNAMENT;

    cout << endl;
}

void printSegment(int levels, int initialStarIndex, int zeroIndexPadding, int ornaments, int ornamentPosition) {
    for (int i = 0; i < levels; i++) {
        ornamentPosition++;
        printCenteredTreeLine(i + initialStarIndex, zeroIndexPadding, ornamentPosition == ornaments);
        ornamentPosition = ornamentPosition % ornaments;
    }
}

void printChristmasTree(int segments, int segmentHeight, int ornaments) {
    int zeroIndexPadding = (segments - 1) + (segmentHeight - 1);
    if (segments * segmentHeight % ornaments == 0)
        zeroIndexPadding++;

    int ornamentPosition = 0;
    for (int i = 0; i < segments; i++) {
        printSegment(segmentHeight, i, zeroIndexPadding, ornaments, ornamentPosition);
        ornamentPosition = (ornamentPosition + segmentHeight) % ornaments;
    }
}

int main() {
    int segments = 5;
    int segmentHeight = 3;
    int ornaments = 4;

    printChristmasTree(segments, segmentHeight, ornaments);
    cout << endl;

    return 0;
}