#include <iostream>
using namespace std;

void func(int &x, int &y) {
    x = x + 5;
    y = y + 10;
    cout << "Inside function: x=" << x << " y=" << y << endl;
}

int main() {
    int a = 10, b = 20;
    cout << "Before call: a=" << a << " b=" << b << endl;

    func(a, b);

    cout << "After call: a=" << a << " b=" << b << endl;

    return 0;
}
