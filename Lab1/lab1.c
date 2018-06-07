#include <stdio.h>
#include <stdlib.h>


int main(){

char line[100];
char *ptr;
fgets(line,sizeof(line),stdin);

int n = strtol(line, &ptr, 10);
//printf("%d\n",n);

int *map = (int *)malloc(n * sizeof(int));
int *index = (int *)malloc(n * sizeof(int));
int *count = (int *)malloc(n * sizeof(int));
int i = 0, j=0, arg1, arg2;

// initialization
for(i=0;i<n;i++){
    map[i] = i;
    index[i] = i;
    count[i] = 0;
}

while(j==0){

    fgets(line,sizeof(line),stdin);
    int operation = strtol(line, &ptr, 10);
   // printf("%d", operation);
    if(operation == 0){
        j = 1;
    }
    switch(operation){
        case 1:
            
            break;
        case 2:
            break;
        case 3:
            arg1 = strtol(ptr, &ptr, 10);
         //   printf(" %d",arg1);
            break;
        case 4:
            arg1 = strtol(ptr, &ptr, 10);
         //   printf(" %d",arg1);
            break;
        case 5:
            arg1 = strtol(ptr, &ptr, 10);
            arg2 = strtol(ptr, &ptr, 10);
        //    printf(" %d",arg1);
        //    printf(" %d",arg2);
            break;
            break;
        default:
            break;
    }
    //printf("\n");
}

free(map);
free(index);
free(count);

}