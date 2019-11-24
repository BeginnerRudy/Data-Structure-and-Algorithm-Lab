/* Sunday, 24 November 2019.

Description about 3-way quick sort:
Step1: Pick a pivot.
Step2: Partition according to the pivot, that is put items smaller than the
       pivot to the left of the partition, put the items larger then the partition
       to the right of the partition, put the items equal to the pivot into the
       pivot.
Step3: Recusively perform Step1&2 on the left and right partition respectively,
       Until there is only one item in the partition then stop.

P.S: 2-way quick sort is just removing the equal partition with others to be
exactly same.

Analysis:
Worst Case  : O(n^2)     [Each pivot is max or min of the partition]
Average Case:            [Need mathematical proof https://secweb.cs.odu.edu/~zeil/cs361/web/website/Lectures/quick/pages/ar01s05.html]
Best Case   : O(nlgon)   [Each pivot is the middle of the partition]

*/
#include <stdio.h>
#include <stdlib.h>

int* quicksort(int* array){
    int len = sizeof(array)/sizeof(array[0]);
    // base case
    if (len <= 1){
        return array;
    }

    // recursive case
    // pick a pivot
    int pivot = pick_pivot(array, len);

    // partition according to the pivot
    int* smaller = (int*)malloc(sizeof(int));
    int* greater = (int*)malloc(sizeof(int));
    int* equal = (int*)malloc(sizeof(int));
    partition(array, pivot, len, smaller, larger, equal);

    // quicksort on left and right partition
    int* sorted_smaller = quicksort(smaller)
    int* sorted_larger = quicksort(larger)

    // combine the sorted left and right partition with the middle partition
    int* sorted_array = (int*)malloc(len*sizeof(int));
    int len_smaller = sizeof(sorted_smaller)/sizeof(sorted_smaller[0]);
    int len_larger = sizeof(sorted_larger)/sizeof(sorted_larger[0]);
    int len_equal = sizeof(equal)/sizeof(equal[0]);
    for (int i = 0; i < len_smaller; i++){
        sorted_array[i] = sorted_smaller[i];
    }
    for (int i = 0; i < len_equal; i++){
        sorted_array[i+len_smaller] = equal[i];
    }
    for (int i = 0; i < len_larger; i++){
        sorted_array[i+len_smaller+len_equal] = sorted_larger[i];
    }

    // return the sorted array
    return sorted_array;
}

void partition(int* array, int pivot, int len,  int* smaller, int* larger, int* equal) {
    
}

int pick_pivot(int* array, int len){
    // Here we just pick the middle element as the pivot
    int middle = len/2;
    return array[middle];
}

int main(int argc, char* argv[]){
    int array[8] = {4, 6, 2, 8, 1, 0 , 6, 4};

    int len = sizeof(array)/sizeof(array[0]);
    int instruction = 0;


}
