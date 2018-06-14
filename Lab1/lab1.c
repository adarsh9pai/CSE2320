#include <stdio.h>
#include <stdlib.h>



int BinarySearchLast(int arr[], int low, int high, int n, int len){

    if(high>=low){
        int mid = low + (high-low)/2; //to avoid integer overflow
        if((mid == len-1 || n<arr[mid+1]) && arr[mid]==n){
            return mid;
        }
        else if(n <arr[mid]){
            return BinarySearchLast(arr,low,(mid-1),n,len);
        }
        else{
            return BinarySearchLast(arr,(mid+1),high,n,len);
        }
    }
    else{
        return -1;
    }
}

int BinarySearchFirst(int arr[], int low, int high, int n, int len){

    int ret = -1;

    while(low<=high){
        int mid = (low+high)/2;
        if(n == arr[mid]){
            ret = mid;
            high = mid-1;
        }
        else if(n < arr[mid]){
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }

    return ret;
}

void AscendingIndexValue(int *map, int *index, int *count, int n){
    int i = 0;
    for(i=0;i<n;i++){
        printf("%d %d\n", i, count[map[i]]);
    }
}

void AscendingCounterValue(int *index, int *count, int n){
    int i = 0;
    for(i=0;i<n;i++){
        printf("%d %d\n", index[i], count[i]);
    }
}

void IncrementByIndex(int *map,int *index, int *count, int n,int length){

     int p = map[n];

     int first = 0, last = length-1;
     int x = BinarySearchLast(count, first, last, count[p], length);
     int temp;

     temp = index[p];
     index[p] = index[x];
     index[x] = temp;

     temp = map[index[p]];
     map[index[p]] = map[index[x]];
     map[index[x]] = temp;

     count[x] += 1;
}

void DecrementByIndex(int *map,int *index, int *count, int n,int length){
    
     int p = map[n];

     int first = 0, last = length-1;
     int x = BinarySearchFirst(count, first, last, count[p], length);
     int temp;

     temp = index[p];
     index[p] = index[x];
     index[x] = temp;

     temp = map[index[p]];
     map[index[p]] = map[index[x]];
     map[index[x]] = temp;

     count[x] -= 1;

}

int NumberOfCounters(int *count, int i, int j, int n){

    int x = BinarySearchFirst(count,0,(n-1),i,n);
    int y = BinarySearchLast(count,0,(n-1),j,n);
    //printf("%d,%d\n",x,y);
    if(x == -1 || y == -1){
        return 1;
    }
    else{
        return (y-x)+1;
    }
    
}

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
    else{
        switch(operation){
        case 1:
            printf("print by index\n");
            AscendingIndexValue(map,index,count,n);
            printf("-------\n");
            break;
        case 2:
            printf("print by count\n");
            AscendingCounterValue(index,count,n);
            printf("-------\n");
            break;
        case 3:
            arg1 = strtol(ptr, &ptr, 10);
            IncrementByIndex(map,index,count,arg1,n);
            break;
        case 4:
            arg1 = strtol(ptr, &ptr, 10);
            DecrementByIndex(map,index,count,arg1,n);
            break;
        case 5:
            arg1 = strtol(ptr, &ptr, 10);
            arg2 = strtol(ptr, &ptr, 10);
            int num = NumberOfCounters(count,arg1,arg2,n);
            
            printf("%d counters between %d and %d\n", num, arg1,arg2);
            printf("-------\n");
            break;
        default:
            break;
    }
    }
    
    //printf("\n");
}

free(map);
free(index);
free(count);

}