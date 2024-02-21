#include <iostream>

using namespace std;

void printChars(int amount, char character) {
    for (int i = 0; i < amount; i++)
        cout << character;
}

void printTreeLine(int level, int levels) {
    printChars(levels - level - 1, ' ');
    printChars(2 * level + 1, '*');
    cout << endl;
}

void printTree(int levels, int skipped = 0) {
    for (int i = skipped; i < levels; i++) {
        printTreeLine(i, levels);
    }
}

int main() {
    int levels = 6;
    int skipped = 2;

    printTree(levels, skipped);
    cout << endl;

    return 0;
}