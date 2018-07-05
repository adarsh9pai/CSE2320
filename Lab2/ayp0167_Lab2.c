#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char **heapArrayPointer;
int N, minQueued, *pq, *qp;


int Parent(int x){
    return x/2;
}
int Left(int x){
    return 2*x;
}
int Right(int x){
    return (2*x)+1;
}


void minHeapInit(char **heapArray,int n){
    N = 0;
    int i;
    heapArrayPointer = heapArray;
    minQueued = n;
    pq = malloc((minQueued+1)*sizeof(int));
    qp = malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        qp[i] = -1;
    }
}

void Exchange(int i,int j){
    int temp = pq[i]; 
    pq[i] = pq[j]; 
    pq[j] = temp;
    qp[pq[i]] = i;
    qp[pq[j]] = j;
}

int more(int i,int j){
    return strcmp(heapArrayPointer[pq[i]], heapArrayPointer[pq[j]])>0?1:0;
}

void heapIncreaseKey(int *pq,int x){
    while(x>1 && more(Parent(x),x)){
        Exchange(x,Parent(x));
        x = Parent(x);
    }
}

void minHeapInsert(int x){
    qp[x] = ++N;
    pq[N] = x;
    heapIncreaseKey(pq,N);
}

void minHeapify(int *pq, int k, int N){
    int j = Left(k);
    if (j < N && more(j, j+1))
        j=Right(k);
    if (!more(k, j))
    {
        return;
    }
    Exchange(k, j);
    k = j;
}

void minHeapChange(int k){
    heapIncreaseKey(pq, qp[k]); 
    minHeapify(pq, qp[k], N);
}

int heapExtractMin()
{ 
    Exchange(1, N); 
    minHeapify(pq, 1, --N); 
    qp[pq[N+1]]=(-1);  
    return pq[N+1]; 
}


int main(){

    int i = 0,n,fileExhaustionCount = 0;
    char line[50];
    FILE *fileNamePointer;


    fileNamePointer = fopen("in.dat","r");
    fgets(line,50,fileNamePointer);
    n = atoi(line);
    char **file_names = malloc(n * (sizeof(char *))); 
    while(fgets(line,50,fileNamePointer)){
        line[ strcspn(line, "\r\n") ] = 0;
        file_names[i] = malloc(50 * sizeof(char));
        strcpy(file_names[i],line);
        i++;
    }
    fclose(fileNamePointer);

    FILE *Files[n];
    for(i = 0;i<n;i++){
        Files[i] = fopen(file_names[i],"r");
        
    }
    FILE *filePrinter = fopen("output.dat","w");


    char **heapArray = malloc(n*sizeof(char*));

    minHeapInit(heapArray,n);
    for(i = 0;i<n;i++){
        fgets(line,50,Files[i]);
        heapArray[i] = malloc(sizeof(char)*50);
        strcpy(heapArray[i],line);
        minHeapInsert(i);
    }

    printf("----table (priority) active entries----\n");
  for (i=0;i<n;i++)
    printf("%d %s",i,heapArray[i]);
  printf("----heap (pq)-----\n");
  for (i=1;i<=N;i++)
    printf("%d %d\n",i,pq[i]);
  printf("----handles (qp)-----\n");
  for (i=0;i<n;i++)
    printf("%d %d\n",i,qp[i]);
    /*
    int b = heapExtractMin();
    fprintf(filePrinter,"%s %d\n",heapArray[b],1);
    strcpy(heapArray[b],"unused or removed\n");

    printf("\n%d\n",b);
    */
     printf("----table (priority) active entries----\n");
  for (i=0;i<n;i++)
    printf("%d %s",i,heapArray[i]);
  printf("----heap (pq)-----\n");
  for (i=1;i<=N;i++)
    printf("%d %d\n",i,pq[i]);
  printf("----handles (qp)-----\n");
  for (i=0;i<n;i++)
    printf("%d %d\n",i,qp[i]);
    /*

    while(fileExhaustionCount < n){
        int stringOccurence = 1;

    }
   */

    for(i = 0;i<n;i++){
        free(file_names[i]);
    }
    for(i = 0;i<n;i++){
        free(heapArray[i]);
    }
    free(file_names);
    free(heapArray);
    for(i = 0;i<n;i++){
        fclose(Files[i]);
    }
    fclose(filePrinter);
    
}