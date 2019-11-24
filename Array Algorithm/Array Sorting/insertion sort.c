/*
Date: 11:53 am, Sunday, 24 November 2019.
The insertion sort algorithm. The idea is to keep item in sorted order one
by one.
Step1: Treat the most left element itself as a sorted array.
Step2: Move 2nd most left item into the sorted array.
Step3: Continue the Step2 on each element from left to right.
Step4: When the most right element is inserted, then done.

*/


// The following implementation is insertion sorting in ascending order on integers.
#include <stdio.h>
#include <stdlib.h>

void swap(int* p1, int* p2){
    int temp = *p1;

    // assign p1 to be p2
    *p1 = *p2;

    // assign p2 to be p1
    *p2 = temp;
}

int main(int argc, char* argb[]){

    int array[8] = {4, 6, 2, 8, 1, 0 , 6, 4};

    int len = sizeof(array)/sizeof(array[0]);
    int instruction = 0;
    for (int i = 1; i < len; i++){
        // insert ith element into the array from 0 to i - 1
        for (int j = i - 1; j >= 0; j--){
            if (array[j+1] < array[j]){
                swap(&array[j+1], &array[j]);
            }
            instruction++;
        }
    }

    for (int i=0; i < len; i++){
        printf(" %d ", array[i]);
    }
    printf("\n Total instruction is %d.\n", instruction);
}
