#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x;
    char* pChar;
    pChar = &x;
    *pChar = getchar();
    printf("Letra %c", x);
    return 0;
}
