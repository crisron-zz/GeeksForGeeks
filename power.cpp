#include <cstdio>

float power( float x, int n ) {
    if( !n ) {
        return 1;
    }
    float temp = power( x, n / 2 );
    if( n % 2 ) {
        if( n > 0 ) {
            return x * temp * temp;
        } else {
            return temp * temp / x;
        }
    }
    return temp * temp;
}

int main() {
    float x = 5.2;
    int n = -2;
    printf( "%f\n", power( x, n ) );
    return 0;
}
