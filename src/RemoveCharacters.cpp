// http://www.geeksforgeeks.org/remove-characters-from-the-first-string-which-are-present-in-the-second-string/
#include <iostream>
#include <cstring>
#include <cassert>

#define MAX_CHARS 256

using namespace std;

void removeCharacters( char a[], const char b[] ) {
    int lenA = strlen( a );
    int lenB = strlen( b );
    if( !lenA || !lenB ) {
        return;
    }
    bool hash[ MAX_CHARS ] = { 0 };
    for( int i = 0; i < lenB; ++i ) {
        hash[ b[ i ] - 0 ] = 1;
    }
    int j = 0;
    for( int i = 0; i < lenA; ++i ) {
        if( !hash[ a[ i ] - 0 ] ) {
            a[ j++ ] = a[ i ];
        }
    }
    a[ j ] = '\0';
}

int main() {
    {
        char a[] = "";
        char b[]  = "";
        removeCharacters( a, b );
        assert( !strcmp( a, "" ) );
    }

    {
        char a[] = "astor";
        char b[] = "";
        removeCharacters( a, b );
        assert( !strcmp( a, "astor" ) );
    }

    {
        char a[] = "";
        char b[] = "cody";
        removeCharacters( a, b );
        assert( !strcmp( a, "" ) );
    }

    {
        char a[] = "astor";
        char b[] = "cody";
        removeCharacters( a, b );
        assert( !strcmp( a, "astr" ) );
    }

    {
        char a[] = "astor.]\\";
        char b[] = "rasto\\";
        removeCharacters( a, b );
        assert( !strcmp( a, ".]" ) );
    }

    {
        char a[] = "cristiano";
        char b[] = "fjalkjkcjkjrkkikkssjtjkian";
        removeCharacters( a, b );
        assert( !strcmp( a, "o" ) );
    }

    {
        char a[] = "apple";
        char b[] = "c";
        removeCharacters( a, b );
        assert( !strcmp( a, "apple" ) );
    }

    {
        char a[] = "banana";
        char b[] = "anb";
        removeCharacters( a, b );
        assert( !strcmp( a, "" ) );
    }

    cout << "\033[1;32m==========ALL TESTS PASSED==========\033[0m" << endl;
    return 0;
}

