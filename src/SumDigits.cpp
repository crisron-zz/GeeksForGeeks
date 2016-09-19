// http://www.geeksforgeeks.org/how-can-we-sum-the-digits-of-a-given-number-in-single-statement/
#include <iostream>
#include <cassert>

using namespace std;

int findSumOfDigits( int n ) {
    int sum = 0;
    for( ; n; sum += n % 10, n /= 10 );
    return sum;
}

int main() {
    int n;

    n = 0;
    assert( findSumOfDigits( n ) == 0 );

    n = 1;
    assert( findSumOfDigits( n ) == 1 );

    n = 15;
    assert( findSumOfDigits( n ) == 6 );

    n = 985;
    assert( findSumOfDigits( n ) == 22 );

    cout << "\033[1;32m==========ALL TESTS PASSED==========\033[0m" << endl;
    return 0;
}

