#include "stdio.h"
#include "stdlib.h"


void insert(int* array, int item) {
    if (item <= 1){
        return;
    }

    printf("hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n");
}

int main(int argc, char* argv[]){
    int* array = (int*)malloc(3*sizeof(int));

    insert(array, 1);
}
