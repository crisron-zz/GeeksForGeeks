#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

#define MAX_CHARS 256

using namespace std;

void findDuplicates( string& str, string& dup ) {
    sort( str.begin(), str.end() );
    for( int i = 1; i < str.length(); ++i ) {
        if( str[ i ] == str[ i - 1 ] ) {
            if( dup[ dup.length() - 1 ] != str[ i ] ) {
                dup += str[ i ];
            }
        }
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
    assert( dup == "abf" );

    str = "487&*)\"ff";
    dup = "";
    findDuplicates( str, dup );
    assert( dup == "f" );

    str = "58285828106";
    dup = "";
    findDuplicates( str, dup );
    assert( dup == "258" );

    str = "";
    dup = "";
    findDuplicates( str, dup );
    assert( dup == "" );

    str = "5383gkjks45.}[[!$#.";
    dup = "";
    findDuplicates( str, dup );
    assert( dup == ".35[k" );

    cout << "\033[1;32m==========ALL TESTS PASSED==========\033[0m" << endl;

    return 0;
}

