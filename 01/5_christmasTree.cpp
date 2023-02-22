#include <iostream>

using namespace std;

const char* ORNAMENT = "@";

void print_chars(int amount, char character) {
    for (int i = 0; i < amount; i++)
        cout << character;
}

void print_centered_tree_line(int starIndex, int zeroIndexPadding, bool ornament) {
    print_chars(zeroIndexPadding - starIndex - (ornament ? 1 : 0), ' ');
    if (ornament)
        cout << ORNAMENT;

    print_chars(2 * starIndex + 1, '*');

    if (ornament)
        cout << ORNAMENT;

    cout << endl;
}

void print_segment(int levels, int initialStarIndex, int zeroIndexPadding, int ornaments, int ornamentPosition) {
    for (int i = 0; i < levels; i++) {
        ornamentPosition++;
        print_centered_tree_line(i + initialStarIndex, zeroIndexPadding, ornamentPosition == ornaments);
        ornamentPosition = ornamentPosition % ornaments;
    }
}

void print_christmas_tree(int segments, int segmentHeight, int ornaments) {
    int zeroIndexPadding = (segments - 1) + (segmentHeight - 1);
    if (segments * segmentHeight % ornaments == 0)
        zeroIndexPadding++;

    int ornamentPosition = 0;
    for (int i = 0; i < segments; i++) {
        print_segment(segmentHeight, i, zeroIndexPadding, ornaments, ornamentPosition);
        ornamentPosition = (ornamentPosition + segmentHeight) % ornaments;
    }
}

int main() {
    int segments = 5;
    int segmentHeight = 3;
    int ornaments = 4;

    print_christmas_tree(segments, segmentHeight, ornaments);
    cout << endl;

    return 0;
}