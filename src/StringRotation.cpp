// http://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other-or-not/
#include <iostream>
#include <string>
#include <cassert>

#define MAX_CHARS 256

using namespace std;

bool areRotations( const string& a, const string& b ) {
    if( a.length() != b.length() ) {
        return false;
    }
    int hashA[ MAX_CHARS ] = { 0 }, hashB[ MAX_CHARS ] = { 0 };
    for( int i = 0; i < a.length(); ++i ) {
        hashA[ a[ i ] - 0 ]++;
    }
    for( int i = 0; i < b.length(); ++i ) {
        hashB[ b[ i ] - 0 ]++;
    }
    for( int i = 0; i < MAX_CHARS; ++i ) {
        if( hashA[ i ] != hashB[ i ] ) {
            return false;
        }
    }
    return true;
}

int main() {
    string a, b;

    a = "";
    b = "";
    assert( areRotations( a, b ) );

    a = "star";
    b = "";
    assert( !areRotations( a, b ) );

    a = "";
    b = "start";
    assert( !areRotations( a, b ) );

    a = "start";
    b = "artst";
    assert( areRotations( a, b ) );

    a = "start";
    b = "artist";
    assert( !areRotations( a, b ) );

    a = "start";
    b = "star";
    assert( !areRotations( a, b ) );

    cout << "\033[1;32m==========ALL TESTS PASSED==========\033[0m" << endl;
    return 0;
}

