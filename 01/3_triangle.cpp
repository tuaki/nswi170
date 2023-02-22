#include <iostream>

using namespace std;

void print_stars(int amount) {
    for (int i = 0; i < amount; i++)
        cout << "*";

    cout << endl;
}

void print_triangle(int levels) {
    for (int i = 0; i < levels; i++) {
        print_stars(i + 1);
    }
}

int main() {
    int levels = 4;

    print_triangle(levels);
    cout << endl;

    return 0;
}