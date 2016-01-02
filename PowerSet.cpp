#include <cstdio>
#include <cmath>

#define MAX 1000000

int main() {
    int set[ MAX + 2 ];
    int i, n;
    scanf( "%d", &n );
    for( i = 0; i < n; ++i ) {
        scanf( "%d", &set[ i ] );
    }
    int elementsInPowerset = pow( 2, n );
    int index, j;
    for( i = 0; i < elementsInPowerset; ++i ) {
        printf( "{ " );
        index = 0;
        j = i;
        while( j ) {
            if( j & 1 ) {
                printf( "%d ", set[ index ] );
            }
            j >>= 1;
            index++;
        }
        printf( "}\n" );
    }
    return 0;
}
