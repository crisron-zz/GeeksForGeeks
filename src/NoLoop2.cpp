// http://www.geeksforgeeks.org/how-will-you-print-numbers-from-1-to-200-without-using-loop/

#include <iostream>

using namespace std;

class X {
    static int i;
    public:
        X() {
            cout << i << endl;
            i++;
        }
};

int X::i = 1;

int main() {
    X arr[ 100 ] __attribute__((unused)); // Suppress -Wunused-variable
    return 0;
}

