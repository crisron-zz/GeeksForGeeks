#include <iostream>

using namespace std;

void printPascal(int n)
{
    for (int line = 0; line < n; line++)
    {
        int C = 1;  // used to represent C(line, i)
        for (int i = 1; i <= line + 1; i++)  
        {
            printf("%d ", C);  // The first value in a line is always 1
            C = C * (line - i + 1) / i;  
        }
        printf("\n");
    }
}

int main() {
    int n;
    cin >> n;
    printPascal( n );
    return 0;
}
