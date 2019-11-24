#include "stdio.h"
#include "stdlib.h"


void insert(int* array, int item) {

}

int main(int argc, char* argv[]){
    int* array = (int*)malloc(3*sizeof(int));

    // array[0] = 3;

    // insert(array, 5);
    int len = sizeof(array)/sizeof(array[0]);
    printf("sizeof(array) is %ld\n", sizeof(*array));
    printf("sizeof(array[0]) is %ld\n", sizeof(array[0]));

    for (int i = 0; i < len; i++){
        printf(" %d ", array[i]);
    }

    printf("\n");
}
