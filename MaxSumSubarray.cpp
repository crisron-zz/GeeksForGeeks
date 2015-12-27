#include <cstdio>

#define MAX 1000000

int main() {
    int i, a[ MAX + 2 ], n;
    scanf( "%d", &n );
    for( i = 0; i < n; ++i ) {
        scanf( "%d", &a[ i ] );
    }
    int maxEndingHere = 0; // Look for all positive continuous segments of the array
    int maxSoFar = 0; // Keep track of max sum continuous segments among all positive continuous segments
    for( i = 0; i < n; ++i ) {
        maxEndingHere += a[ i ];
        if( maxEndingHere < 0 ) {
            maxEndingHere = 0;
        } else if( maxEndingHere > maxSoFar ) {
            maxSoFar = maxEndingHere;
        }
    }
    printf( "%d\n", maxSoFar );
    return 0;
}
