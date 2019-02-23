/**
    When 'o' or 'x' is put on a head of a number, it'll be an octal or
   hexadecimal.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void reverse(char *str);
void bin(int x, char *str, int siz);
void hex(int x, char *str, int siz);
void oct(int x, char *str, int siz);

static const char HEX[] = "0123456789ABCDEF";
// 反転
void reverse(char *str)
{
    char *head = str;
    char *tail = str + 1;

    if (*head == '\0') {
        return;
    }
    //
    while (*tail) {
        tail++;
    }
    tail--;
    //
    while (head < tail) {
        char temp = *head;
        *head     = *tail;
        *tail     = temp;
        //
        head++;
        tail--;
    }
}
// 2進
void bin(int x, char *str, int siz)
{
    char *tmp = str;
    do {
        *str++ = HEX[x & 0x01];
        x >>= 1;
        siz--;
    } while (siz != 0);
    *str = '\0';
    reverse(tmp);
}
// 8進
void oct(int x, char *str, int siz)
{
    char *tmp = str;
    do {
        *str++ = HEX[x & 0x07];
        x >>= 3;
        siz--;
    } while (siz != 0);
    *str = '\0';
    reverse(tmp);
}
// 16進
void hex(int x, char *str, int siz)
{
    char *tmp = str;
    do {
        *str++ = HEX[x & 0x0F];
        x >>= 4;
        siz--;
    } while (siz != 0);
    *str = '\0';
    reverse(tmp);
}
//
#define BITSIZ (sizeof(int) * CHAR_BIT)
//
int main(int agc, char *agv[])
{
    if (agc != 2) {
        return 1;
    }
    // Cardinal number judgment.
    char *agp  = agv[1];
    int   base = 10;
    switch (*agp) {
    case 'o':
    case 'O':
        base = 8;
        agp++;
        break;
    case 'x':
    case 'X':
        base = 16;
        agp++;
        break;
    }
    //
    int N = (int)strtol(agp, 0, base);
    if (N == 0) {
        return 2;
    }
    //
    printf("read N=  %d\n", N);
    //
    char str[67];
    str[66] = '\0';
    //
    bin(N, str, BITSIZ);
    puts(str);
    //
    //
    hex(N, str, BITSIZ / 4);
    puts(str);
    //
    oct(N, str, BITSIZ / 3);
    puts(str);
    //
    return 0;
}
