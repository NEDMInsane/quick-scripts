#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BUF_SIZE 1024

void scan_for_network(char[]);

int main(){
    char buffer[MAX_BUF_SIZE];

    scan_for_network(buffer);
    //printf("SSID:\t%s\n", buffer);


    return 0;
}

void scan_for_network(char buffer[]){
    FILE *fp;
    
    fp = popen("sudo wpa_cli scan_results", "r");
    if(fp == NULL){
        perror("popen");
        exit(EXIT_FAILURE);
    }

    while(fgets(buffer, sizeof(&buffer), fp) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';
        printf("SSID:\t%s\n", buffer);
    }

    pclose(fp);
}