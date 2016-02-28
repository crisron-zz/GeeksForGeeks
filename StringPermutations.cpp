#include <iostream>
#include <cstring>

#define MAX 1000000

using namespace std;

void swap( char arr[], int a, int b ) {
    char tmp = arr[ a ];
    arr[ a ] = arr[ b ];
    arr[ b ] = tmp;
}

void _permute( char arr[], int n, int idx ) {
    if( idx == n - 1 ) {
        cout << arr << endl;
        return;
    }
    for( int i = idx; i < n; ++i ) {
        swap( arr, idx, i );
        _permute( arr, n, idx + 1 );
        swap( arr, idx, i );
    }
}

void permute( char arr[] ) {
    int n = strlen( arr );
    if( !n ) {
        return;
    }
    _permute( arr, n, 0 );
}

int main() {
    char arr[ MAX ];
    cin >> arr;
    permute( arr );
    return 0;
}
