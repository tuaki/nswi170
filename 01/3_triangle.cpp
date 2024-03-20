#include <iostream>

using namespace std;

void printStars(int amount) {
    for (int i = 0; i < amount; i++)
        cout << "*";
}

void printTriangle(int levels) {
    for (int i = 0; i < levels; i++) {
        printStars(i + 1);
        cout << endl;
    }
}

int main() {
    int levels = 4;

    printTriangle(levels);
    cout << endl;

    return 0;
}