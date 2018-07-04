#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int i = 0,n;
    char line[50];
    FILE *fileNamePointer;

    fileNamePointer = fopen("in.dat","r");
    fgets(line,50,fileNamePointer);
    char size = line[0];
    n = size - '0';
    char **file_names = malloc(n * (sizeof(char *))); 
    

    while(fgets(line,50,fileNamePointer)){
        file_names[i] = malloc(50 * sizeof(char));
        strcpy(file_names[i],line);
        i++;
    }
    
    
    
    for(i = 0;i<n;i++){
        free(file_names[i]);
    }
    free(file_names);
    
}