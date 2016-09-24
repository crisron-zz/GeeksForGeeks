#include <iostream>
#include <cassert>

#include "MathUtils.h"

using namespace std;

double pow( double a, int b ) {
    // Handle negative powers
    if( b < 0 ) {
        return pow( 1.0 / a, -b );
    }
    if( !b ) {
        return 1;
    }
    double temp = pow( a, b / 2 );
    // Power is odd
    if( b % 2 ) {
        return ( temp * temp * a );
    }
    return ( temp * temp );
}

int main() {
    double a, c;
    int b;
    
    a = 1;
    b = 0;
    c = 1;
    assert( pow( a, b ) == c );

    a = 0;
    b = 5;
    c = 0;
    assert( pow( a, b ) == c );

    a = 4;
    b = 1;
    c = 4;
    assert( pow( a, b ) == c );

    a = 5;
    b = 5;
    c = 3125;
    assert( pow( a, b ) == c );

    a = -4;
    b = 6;
    c = 4096;
    assert( pow( a, b ) == c );

    a = -5;
    b = 3;
    c = -125;
    assert( pow( a, b ) == c );

    a = 8;
    b = -4;
    c = 0.000244140625;
    assert( isEqual( pow( a, b ) , c ) );

    a = -9;
    b = -3;
    c = -0.00137174;
    assert( isEqual( pow( a, b ) , c ) );

    cout << "\033[1;32m==========ALL TESTS PASSED==========\033[0m" << endl;
    return 0;
}

