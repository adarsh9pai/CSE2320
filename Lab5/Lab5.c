/*
    Name: Adarsh Yogesh Pai
    CSE 2320 001 Dr. Weems
    Lab 5
    Omega Command: gcc ayp0167_Lab5.c -o program
    UTA ID: 1001530167
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define PLACHOLDER_NUMBER INT_MAX
#define NEGATIVE_PLACEHOLDER_NUMBER -1
#define NEW_LINE printf("\n")
#define BORDER printf("-------------------------------\n")


void ConsoleInput(int NumberOfVertices, int EdgeArray[NumberOfVertices][NumberOfVertices], int A[NumberOfVertices][NumberOfVertices]);
void AssignToGraph(int NumberOfVertices,int i, int j, int A[NumberOfVertices][NumberOfVertices]);
void ConsoleOutput(int NumberOfVertices, int EdgeArray[NumberOfVertices][NumberOfVertices], int A[NumberOfVertices][NumberOfVertices]);

int main(){
    int NumberOfVertices = 0;
    scanf("%d", &NumberOfVertices);
    int EdgeArray[NumberOfVertices][NumberOfVertices];
    int A[NumberOfVertices][NumberOfVertices];
    int x = 1, y, i, j, k;
    ConsoleInput(NumberOfVertices, EdgeArray, A);

    /* Warshall's Algorithm */
    for(j = 0; j < NumberOfVertices; j++){
        for(i = 0; i < NumberOfVertices; i++){
            if(EdgeArray[i][j] != NEGATIVE_PLACEHOLDER_NUMBER){
                for(k = 0; k < NumberOfVertices; k++){
                    if(EdgeArray[i][k] == NEGATIVE_PLACEHOLDER_NUMBER && EdgeArray[j][k] != NEGATIVE_PLACEHOLDER_NUMBER){
                        EdgeArray[i][k] = EdgeArray[i][j];
                    }
                }
            }
            if(EdgeArray[i][j] != NEGATIVE_PLACEHOLDER_NUMBER && EdgeArray[j][i] != NEGATIVE_PLACEHOLDER_NUMBER){
                AssignToGraph(NumberOfVertices, i, j, A);
            }
        }
        for(x = 0; x < NumberOfVertices; x++){
            printf("%3d ",x);
            for(y = 0; y < NumberOfVertices; y++){
                printf("%3d ",EdgeArray[x][y]);
            }
            NEW_LINE;
            }
        BORDER;
    }

    ConsoleOutput(NumberOfVertices, EdgeArray, A);
 
    return 0;
}

void ConsoleInput(int NumberOfVertices, int EdgeArray[NumberOfVertices][NumberOfVertices], int A[NumberOfVertices][NumberOfVertices]){
    int i, j, tail, head, x = 1;
    for(i = 0; i < NumberOfVertices; i++){
        for(j = 0; j < NumberOfVertices; j++){
            EdgeArray[i][j] = NEGATIVE_PLACEHOLDER_NUMBER; //Since Edge is going to be 0 or more than 0
        }
    }
    for(i = 0; i < NumberOfVertices; i++){
        for(j = 0; j < NumberOfVertices; j++){
            A[i][j] = PLACHOLDER_NUMBER;
        }
        A[i][i] = i;
    }

    while(x == 1){
        scanf("%d %d", &tail, &head);
        if(tail == NEGATIVE_PLACEHOLDER_NUMBER && head == NEGATIVE_PLACEHOLDER_NUMBER){
            break;
        }
        EdgeArray[tail][head] = head;
    }
}

void AssignToGraph(int NumberOfVertices,int i, int j, int A[NumberOfVertices][NumberOfVertices]){
    if(A[i][i] > A[j][j]){
        A[i][i] = A[j][j];
    }
    if(A[j][j] > A[i][i]){
        A[j][j] = A[i][i];
    }
}

void ConsoleOutput(int NumberOfVertices, int EdgeArray[NumberOfVertices][NumberOfVertices], int A[NumberOfVertices][NumberOfVertices]){
    int x, y, z, a;
    for(x = 0; x < NumberOfVertices; x++){
        if(A[x][x] == x){ // Leader found
            printf("Vertex %d is a Leader.\n", x);
        }
        else{
            printf("Vertex Path to Leader is: ");
            for(z = x; z != A[x][x]; z = EdgeArray[z][A[x][x]]){
                printf("%d ", z);
            }
            printf("%d", A[x][x]);
            printf("\nVertex Path from Leader is: ");
            for(z = A[x][x]; z != x; z = EdgeArray[z][x]){
                printf("%d ", z);
            }
            printf("%d\n", x);
        }
    }

}