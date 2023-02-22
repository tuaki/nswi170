#include <iostream>

using namespace std;

void print_stars(int amount) {
    for (int i = 0; i < amount; i++)
        cout << "*";
}

int main() {
    int stars = 5;

    print_stars(stars);
    cout << endl;

    return 0;
}