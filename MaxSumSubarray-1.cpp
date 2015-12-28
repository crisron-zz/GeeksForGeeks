#include <cstdio>

#define MAX 1000000

int main() {
    int i, a[ MAX + 2 ], n;
    scanf( "%d", &n );
    for( i = 0; i < n; ++i ) {
        scanf( "%d", &a[ i ] );
    }
    int curMax = a[ 0 ];
    int maxSoFar = a[ 0 ];
    for( i = 1; i < n; ++i ) {
        curMax = max( a[ i ], curMax + a[ i ] );
        maxSoFar = max( curMax, maxSoFar );
    }
    printf( "%d\n", maxSoFar );
    return 0;
}

