/* Sunday, 24 November 2019
This linear search aims to find out whether a given element is in a given
 collection of items. This algorithm search items from left to right one by
 one. */

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    char* string = "The string";
    char x = 's';
    int is_contain = 0;

    for (int i = 0; i < strlen(string); i++){
        if (string[i] == x){
            printf("The \'%c\' is at %d position of \"%s\".\n", x, i, string);
            is_contain = 1;
            break;
        }
    }

    if (!is_contain){
        printf("The \'%c\' does not contain in \"%s\".\n", x, string);
    }

    return 0;
}
