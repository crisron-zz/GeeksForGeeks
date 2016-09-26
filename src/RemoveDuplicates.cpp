// http://www.geeksforgeeks.org/remove-all-duplicates-from-the-input-string/
#include <iostream>
#include <string>
#include <cassert>

#define MAX_CHARS 256

using namespace std;

void removeDuplicates( string& str ) {
    bool hash[ MAX_CHARS ] = { 0 };
    for( int i = 0; i < str.length(); i++ ) {
        if( hash[ str[ i ] - 0 ] ) { // str[ i ] has already occurred
            str.erase( i, 1 );
            i--;
        } else {
            hash[ str[ i ] - 0 ] = 1;
        }
    }
}

int main() {
    string str;

    str = "abcdef";
    removeDuplicates( str );
    assert( str == "abcdef" );

    str = "ababab";
    removeDuplicates( str );
    assert( str == "ab" );

    str = "abbfbabdbbabf";
    removeDuplicates( str );
    assert( str == "abfd" );

    str = "487&*)\"ff";
    removeDuplicates( str );
    assert( str == "487&*)\"f" );

    str = "58285828106";
    removeDuplicates( str );
    assert( str == "582106" );

    str = "";
    removeDuplicates( str );
    assert( str == "" );

    str = "5383gkjks45.}[[!$#.";
    removeDuplicates( str );
    assert( str == "538gkjs4.}[!$#" );

    cout << "\033[1;32m==========ALL TESTS PASSED==========\033[0m" << endl;

    return 0;
}

