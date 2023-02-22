#include <iostream>

using namespace std;

void print_chars(int amount, char character) {
    for (int i = 0; i < amount; i++)
        cout << character;
}

void print_tree_line(int level, int levels) {
    print_chars(levels - level - 1, ' ');
    print_chars(2 * level + 1, '*');
    cout << endl;
}

void print_tree(int levels, int skipped = 0) {
    for (int i = skipped; i < levels; i++) {
        print_tree_line(i, levels);
    }
}

int main() {
    int levels = 6;
    int skipped = 2;

    print_tree(levels, skipped);
    cout << endl;

    return 0;
}