#include <iostream>

using namespace std;

void printStars(int amount) {
    for (int i = 0; i < amount; i++)
        cout << "*";
}

int main() {
    int stars = 5;

    printStars(stars);
    cout << endl;

    return 0;
}