#include <iostream>

using namespace std;

void printArray( int pascal[], int n ) {
    for( int i = 0; i <= n; ++i ) {
        cout << pascal[ i ] << " ";
    }
    cout << endl;
}

void printPascal( int n ) {
    int pascal[ n ];
    pascal [ 0 ] = 1;
    cout << pascal[ 0 ] << endl;
    for( int i = 1; i < n; ++i ) {
        for( int j = i; j >= 0; j-- ) {
            if( !j || i == j ) {
                pascal[ j ] = 1;
            } else {
                pascal[ j ] = pascal[ j ] + pascal[ j - 1 ];
            }
        }
        printArray( pascal, i );
    }
}

int main() {
    int n;
    cin >> n;
    printPascal( n );
    return 0;
}
