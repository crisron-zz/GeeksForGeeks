// http://www.geeksforgeeks.org/remove-all-duplicates-from-the-input-string/
#include <iostream>
#include <cstring>
#include <cassert>

#define MAX_CHARS 256
#define MAX 100

using namespace std;

void removeDuplicates( char* str ) {
    bool hash[ MAX_CHARS ] = { 0 };
    int len = strlen( str );
    int j = 0;
    for( int i = 0; i < len; i++ ) {
        if( !hash[ str[ i ] - 0 ] ) { // str[ i ] has not already occurred
            str[ j ] = str[ i ];
            hash[ str[ i ] - 0 ] = 1;
            j++;
        }
    }
    str[ j ] = '\0';
}

int main() {
    char str1[] = "aaaaaa";
    removeDuplicates( str1 );
    assert( !strcmp( str1, "a" ) );

    char str2[] = "abcdef";
    removeDuplicates( str2 );
    assert( !strcmp( str2, "abcdef" ) );

    char str3[] = "ababab";
    removeDuplicates( str3 );
    assert( !strcmp( str3, "ab" ) );

    char str4[] = "abbfbabdbbabf";
    removeDuplicates( str4 );
    assert( !strcmp( str4, "abfd" ) );

    char str5[] = "487&*)\"ff";
    removeDuplicates( str5 );
    assert( !strcmp( str5, "487&*)\"f" ) );

    char str6[] = "58285828106";
    removeDuplicates( str6 );
    assert( !strcmp( str6, "582106" ) );

    char str7[] = "";
    removeDuplicates( str7 );
    assert( !strcmp( str7, "" ) );

    char str8[] = "5383gkjks45.}[[!$#.";
    removeDuplicates( str8 );
    assert( !strcmp( str8, "538gkjs4.}[!$#" ) );

    cout << "\033[1;32m==========ALL TESTS PASSED==========\033[0m" << endl;

    return 0;
}

