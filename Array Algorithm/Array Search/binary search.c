#include <stdio.h>

void binary_search(int* array, int x, int start, int end, int* instruction){
    // base case
    if (end <= start){
        printf("%d is not found1.\n", x);
        return;
    }

    if ((end - start) == 1 && array[start] == x){
        printf("%d is at position %d.\n", x, start);
        *instruction = *instruction + 1;
        return;
    }else if ((end - start) == 1 ){
        *instruction = *instruction + 1;
        printf("%d is not found2.\n", x);
        return;
    }

    // recursive case
    int middle = (end + start)/2;
    *instruction = *instruction + 1;
    if (array[middle]==x){
        printf("%d is at position %d.\n", x, middle);
        return;
    }else if (x > array[middle]){
        binary_search(array, x, middle+1, end, instruction);
    }else{
        binary_search(array, x, start, middle, instruction);
    }
}

int main(int argc, char* argv[]){
    // int array[8] = {4, 6, 2, 8, 1, 0 , 6, 4};
    int array[21] = {0, 1, 2 ,3, 4, 5, 6 ,7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int len = sizeof(array)/sizeof(array[0]);
    int instruction = 0;
    int x =6;

    // sort the array

    // implement binary search
    binary_search(array, x, 0, len, &instruction);

    printf("The total instruction is %d\n", instruction);
}
