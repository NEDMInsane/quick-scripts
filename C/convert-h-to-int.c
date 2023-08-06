#include<stdio.h>

/* This program takes in a char array that is a hexadecimal number and converts it to
    an integer. This is exercise 2-3 in The C Programming Language i beleive this is
    what the exercise is trying to get at.*/

int htoi(char[]);

int main(){
    int i_hex = 0x01a;
    char hex[5];
    hex[0] = '0';
    hex[1] = 'x';
    hex[2] = '0';
    hex[3] = '1';
    hex[4] = 'a';

    printf("%d\t", i_hex);
    printf("%d\n", htoi(hex));
    return 0;
}

int htoi(char hexa[]){
    int i, h;

    h = 0;
    if(hexa[0] == '0' && hexa[1] == 'x' || hexa[0] == '0' && hexa[1] == 'X')
        for(i = 2; hexa[i] >= '0' && hexa[i] <= '9' || hexa[i] >= 'a' && hexa[i] <= 'f' || hexa[i] >= 'A' && hexa[i] <= 'F'; ++i){
            if(hexa[i] >= '0' && hexa[i] <= '9')
                h = 16 * h + (hexa[i] - '0');
            else if(hexa[i] >= 'a' && hexa[i] <= 'f')
                h = 16 * h + (hexa[i] - 'a' + 10);
            else if(hexa[i] >= 'A' && hexa[i] <= 'F')
                h = 16 * h + (hexa[i] - 'A' + 10);
        }
    
    return h;
}