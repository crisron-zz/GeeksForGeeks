#include <iostream>
#include <cassert>

using namespace std;

bool isPowerOf2( int n ) {
    return ( n && !( n & ( n - 1 ) ) );
}

int nextPowerOf2( int n ) {
    if( !n ) {
        return 1;
    }
    if( isPowerOf2( n ) ) {
        return n;
    }
    while( !isPowerOf2( n ) ) {
        n = n & ( n - 1 );
    }
    n <<= 1;
    return n;
}

int main() {
    int n, output;
    // Tests
    n = 0;
    output = nextPowerOf2( n );
    assert( output == 1 );
    
    n = 1;
    output = nextPowerOf2( n );
    assert( output == 1 );

    n = 2;
    output = nextPowerOf2( n );
    assert( output == 2 );

    n = 5;
    output = nextPowerOf2( n );
    assert( output == 8 );

    n = 17;
    output = nextPowerOf2( n );
    assert( output == 32 );
    
    cout << "All tests passed" << endl;

    return 0;
}
