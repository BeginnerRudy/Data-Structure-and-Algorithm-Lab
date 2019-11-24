/* Sunday, 24 November 2019.
Totla implementation time: 30min + 80min & finished with the help of the textbook

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


void swap(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    return;
}

int pick_pivot(int* array, int len){
    // Here we just pick the middle element as the pivot
    int middle = len/2;
    return array[middle];
}

void partition(int* array, int pivot, int len,  int* fe, int* fl, int* instruction) {
    int first_equal = 0, first_larger = len;
    int i = 0;
    while (i < first_larger) {
        int item = array[i];
        if (item < pivot){
            swap(&array[i], &array[first_equal]);
            first_equal ++;
            i ++;
        }else if (item > pivot){
            swap(&array[i], &array[--first_larger]);
        }else{
            i++;
        }

        *instruction = *instruction + 1;
    }

    *fe = first_equal;
    *fl = first_larger;

    // for (int i=0; i<len; i++){
    //     printf("%d ", array[i]);
    // }
    // printf("\n");
    return;
}


void quicksort(int* array, int len, int* instruction){
    // base case
    if (len <= 1){
        return;
    }

    // recusive case
    int pivot = pick_pivot(array, len);
    int first_equal, first_larger; // noth are 0-strated index
    partition(array, pivot, len, &first_equal, &first_larger, instruction);

    // sort left part
    quicksort(array, first_equal, instruction);
    // sort right part
    quicksort(array+first_larger, len-first_larger, instruction);
}


int main(int argc, char* argv[]){
    int array[8] = {4, 6, 2, 8, 1, 0 , 6, 4};

    int len = sizeof(array)/sizeof(array[0]);

    int instruction = 0;
    quicksort(array, len, &instruction);

    for (int i=0; i<len; i++){
        printf(" %d ", array[i]);
    }
    printf("\n%d\n", instruction);
}
