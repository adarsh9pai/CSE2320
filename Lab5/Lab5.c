#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main(){

    int NumberOfVertices = 0, i, j, k;
    scanf("%d", &NumberOfVertices);

    int EdgeArray[NumberOfVertices][NumberOfVertices];

    for(i = 0; i < NumberOfVertices; i++){
        for(j = 0; j < NumberOfVertices; j++){
            EdgeArray[i][j] = -1; //Initializing
        }
    }

    int tail, head, x = 1;

    while(x == 1){
        scanf("%d %d", &tail, &head);
        if(tail == -1 && head == -1){
            x = 0;
        }
        EdgeArray[tail][head] = head;
    }

    /* Warshall */

    for(j = 0; j < NumberOfVertices; j++){
        for(i = 0; i < NumberOfVertices; i++){
            if(EdgeArray[i][j] != -1){
                for(k = 0; k < NumberOfVertices; k++){
                    if(EdgeArray[i][k] != -1 && EdgeArray[j][k] != -1){
                        EdgeArray[i][k] = EdgeArray[i][j];
                    }
                }
            }
        }   
    }
  
    

    return 0;

}