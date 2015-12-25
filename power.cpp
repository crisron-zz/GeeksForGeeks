#include <cstdio>

int power( int x, int n ) {
    if( !n ) {
        return 1;
    }
    int temp = power( x, n / 2 );
    if( n % 2 ) {
        return x * temp * temp;
    }
    return temp * temp;
}

int main() {
    int x = 5;
    int n = 2;
    printf( "%d\n", power( x, n ) );
    return 0;
}
