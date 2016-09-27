#include <iostream>
#include <string>
#include <cassert>

#define MAX_CHARS 256

using namespace std;

void findDuplicates( const string& str, string& dup ) {
    int hash[ MAX_CHARS ] = { 0 };
    for( int i = 0; i < str.length(); ++i ) {
        if( hash[ str[ i ] - 0 ] == 1 ) {
            dup += str[ i ];
        }
        hash[ str[ i ] - 0 ]++;
    }
}

int main() {
    string str, dup;

    str = "aaaaaa";
    dup = "";
    findDuplicates( str, dup );
    assert( dup == "a" );

    str = "abcdef";
    dup = "";
    findDuplicates( str, dup );
    assert( dup == "" );

    str = "ababab";
    dup = "";
    findDuplicates( str, dup );
    assert( dup == "ab" );

    str = "abbfbabdbbabf";
    dup = "";
    findDuplicates( str, dup );
    assert( dup == "baf" );

    str = "487&*)\"ff";
    dup = "";
    findDuplicates( str, dup );
    assert( dup == "f" );

    str = "58285828106";
    dup = "";
    findDuplicates( str, dup );
    assert( dup == "852" );

    str = "";
    dup = "";
    findDuplicates( str, dup );
    assert( dup == "" );

    str = "5383gkjks45.}[[!$#.";
    dup = "";
    findDuplicates( str, dup );
    assert( dup == "3k5[." );

    cout << "\033[1;32m==========ALL TESTS PASSED==========\033[0m" << endl;

    return 0;
}

