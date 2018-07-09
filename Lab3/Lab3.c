#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){

    int i = 0, SubsequenceTargets[3];
    char *InitLine = malloc( 100 * sizeof(char)), line[20];
    fgets(InitLine,100,stdin);
    SubsequenceTargets[0] = atoi(strtok(InitLine," "));

    for(i = 0; i < 2; i++){
        SubsequenceTargets[i+1] = atoi(strtok(NULL," "));
    }

    int *InputArray = malloc( SubsequenceTargets[0] * sizeof(char));

    for(i = 0; i < SubsequenceTargets[0]; i++){
        fgets(line,20,stdin);
        InputArray[i] = atoi(line);
    }
    


    printf("%d %d %d\n",SubsequenceTargets[0],SubsequenceTargets[1],SubsequenceTargets[2]);
    for(i = 0; i < SubsequenceTargets[0]; i++){
        printf("%d\n",InputArray[i]);
    }

    free(InitLine);
    free(InputArray);
}
