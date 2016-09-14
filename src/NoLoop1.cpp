// http://www.geeksforgeeks.org/how-will-you-print-numbers-from-1-to-200-without-using-loop/
#include <iostream>

using namespace std;

void recursive() {
    static int i = 1;
    if( i > 100 ) {
        return;
    }
    cout << i << endl;
    i++;
    recursive();
}

int main() {
    recursive();
    return 0;
}

