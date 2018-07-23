
#include <stdio.h>
#include <stdlib.h>

void StreamInput(int *size, int *x, int *y,int ** inputArray){
    int i = 0;
    //Input for Size and the two targets
    scanf("%d", size);
    scanf("%d", x);
    scanf("%d", y);

    //Memory Allocated to the Input Array and the two Cost tables
    *inputArray = malloc((*size + 1) * sizeof(int)); 
    
    
    //If Malloc failed
    if(!(*inputArray)){
        printf("Memory Allocation Failed.\n");
        exit(0);
    }
    else{
        (*inputArray[0]) = 0; 
        for(i = 1; i <= *size; i++){
            scanf("%d", *inputArray+i);
        }
    }

}


int ** FCostTable, ** SCostTable;
void SubsetSumTable(int InputSetSize, int SubsequenceTarget, int inputArray[], int **CostTable); 
void ConsoleOutput(int InputSetSize, int SubsequenceTarget, int inputArray[], int **CostTable);


int main(){

    int SubsequenceTargets[2], InputSetSize, *InputSetArray, i = 0,j;
   
    StreamInput(&InputSetSize, &SubsequenceTargets[0], &SubsequenceTargets[1], &InputSetArray);
    printf("Targets are %d and %d\n",SubsequenceTargets[0],SubsequenceTargets[1]);
    printf("  i   S\n");
    printf("--------\n");
    for(i = 1; i <= InputSetSize; i++){
        printf("%3d %3d\n",i, InputSetArray[i]);
    }
    
    FCostTable = malloc(sizeof(int*) * (InputSetSize + 1));
    SCostTable = malloc(sizeof(int*) * (InputSetSize + 1));
    for(i = 0; i <= InputSetSize; i++){
        FCostTable[i] = malloc(sizeof(int) * (SubsequenceTargets[0] + 1));
        FCostTable[i][0] = 1;
        SCostTable[i] = malloc(sizeof(int) * (SubsequenceTargets[1] + 1));
        SCostTable[i][0] = 1;
    }
    
    SubsetSumTable(InputSetSize, SubsequenceTargets[0], InputSetArray,FCostTable); 
    ConsoleOutput(InputSetSize, SubsequenceTargets[0], InputSetArray,FCostTable);
    SubsetSumTable(InputSetSize, SubsequenceTargets[1], InputSetArray,SCostTable); 
    ConsoleOutput(InputSetSize, SubsequenceTargets[1], InputSetArray,SCostTable);

    //Pointer Freeing Area
    for(i = 0; i <= InputSetSize; i++){
       free(FCostTable[i]);
       free(SCostTable[i]); 
    }
    free(FCostTable);
    free(SCostTable);
    free(InputSetArray);
}

void SubsetSumTable(int InputSetSize, int SubsequenceTarget, int inputArray[], int **CostTable){
    int i,j;
    for(j = 1; j <= SubsequenceTarget; j++){
        CostTable[0][j] = 0;
    }
    for(j = 1; j <= SubsequenceTarget; j++){
        for(i = 1; i <= InputSetSize; i++){
            if(j < inputArray[i]){
               CostTable[i][j] = CostTable[i - 1][j];
            }
            else{
                CostTable[i][j] = CostTable[i - 1][j - 1] ||
                CostTable[i - 1][j - inputArray[i]];
            }
    }
    }
}

void ConsoleOutput(int InputSetSize, int SubsequenceTarget, int inputArray[], int **CostTable){
    int i,j;
    if(CostTable[InputSetSize][SubsequenceTarget]){
        printf("\nSubsequence for %d:\n",SubsequenceTarget);
        int j = SubsequenceTarget;
        for (int i = InputSetSize; i>=1; i--) {
            if (!CostTable[i-1][j]){
                printf("%d\n",inputArray[i]); 
                j -= inputArray[i];
            }
        }
    }
    else{
         printf("\nSubsequence for %d:\n",SubsequenceTarget);
        printf("No Solution");
        exit(0);
    }
}
