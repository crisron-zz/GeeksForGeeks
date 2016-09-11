#include <iostream>
#include <string>
#include <cassert>

#define MAX_CHARS 256

using namespace std;

char maxOccuringChar( string s ) {
    int hash[ MAX_CHARS ] = {};
    for( int i = 0; i < s.length(); ++i ) {
        hash[ s[ i ] - 0 ]++;
    }
    
    int max = 0;
    char res;
    for( int i = 0; i < MAX_CHARS; ++i ) {
        if( hash[ i ] > max ) {
            max = hash[ i ];
            res = i;
        }
    }
    return res;
}

int main() {
    string s;

    s = "test";
    assert ( maxOccuringChar( s ) == 't' );

    s = "gljelr2929";
    assert( maxOccuringChar( s ) == '2' );

    s = "3[{94\\\\\\,</";
    assert( maxOccuringChar( s ) == '\\' );

    cout << "\033[1;32m==========ALL TESTS PASSED==========\033[0m" << endl;
    return 0;
}

