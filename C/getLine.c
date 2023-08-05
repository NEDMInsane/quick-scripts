#include<stdio.h>

#define MAXLINE 5000

int getLine(char line[], int lenth);

int main(){
    char line[MAXLINE];
    int len;

    while((len = getLine(line, MAXLINE)) > 0){
        printf("%s", line);
    }
    return 0;
}

int getLine(char line[], int limit){
    int i, c;

    for(i = 0; i < limit - 1 && (c = getchar()) != '\n' && c != EOF; ++i){
        line[i] = c;
    }

    if(c == '\n'){
        line[i] = '\n';
        ++i;
    }

    line[i] = '\0';
    return i;
}