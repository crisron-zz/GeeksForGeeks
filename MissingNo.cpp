#include <cstdio>

#define MAX 1000000

int main() {
    int i, n, a[ MAX + 2 ];
    int XOR = 0; // xor is a reserved word in C++
    scanf( "%d", &n );
    for( i = 0; i < ( n - 1 ); ++i ) {
        scanf( "%d", &a[ i ] );
        XOR ^= a[ i ];
    }
    for( i = 1; i <= n; ++i ) {
        XOR ^= i;
    }
    printf( "%d\n", XOR );
    return 0;
}
