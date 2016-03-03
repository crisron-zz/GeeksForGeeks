#include <iostream>

#define MAX 1000000

using namespace std;

void printSubset( int subset[], int count ) {
    for( int i = 0; i < count; ++i ) {
        cout << subset[ i ] << " ";
    }
    cout << endl;
}

bool subsetSumUtil( int arr[], int n, int targetSum,
                    int subset[], int count, int curSum ) {
    if( curSum == targetSum ) {
        printSubset( subset, count );
        return true;
    }
    if( ( !n && targetSum ) || ( curSum > targetSum ) ) {
        return false;
    }
    subset[ count ] = arr[ n - 1 ];
    bool takeThis = subsetSumUtil( arr, n - 1, targetSum,
                                   subset, count + 1, curSum + arr[ n - 1 ] );
    bool dontTakeThis = subsetSumUtil( arr, n - 1, targetSum,
                                       subset, count, curSum );
    return ( takeThis || dontTakeThis );
}

void subsetSum( int arr[], int n, int sum ) {
    int subset[ MAX ];
    subsetSumUtil( arr, n, sum, subset, 0, 0 );
}

int main() {
    int arr[ MAX ], n;
    cin >> n;
    for( int i = 0; i < n; ++i ) {
        cin >> arr[ i ];
    }
    int sum;
    cin >> sum;
    subsetSum( arr, n, sum );
    return 0;
}
