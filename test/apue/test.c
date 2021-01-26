#include <stdio.h>

int main(int argc, char *argv[])
{
    char c;
    scanf("%c", &c);
    printf("%c", c - 'a' + 'A');
    return 0;
}
