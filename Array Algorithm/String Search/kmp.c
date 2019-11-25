/* Monday, 25 November 2019. Spend 60mins.

The KMP string pattern searching algorithm.

Preprocessing:

Pattern searching:

*/

#include <stdio.h>

int find_longest_common_prefix_and_suffix(char* string, int len){
    for (int i=1; i<len; i++){
        int all_match = 1;
        for (int j=0; j<i;j++){
            if (string[j] != string[len - i + j]){
                all_match = 0;
                break;
            }
        }

        if (all_match==1){
            return i;
        }
    }

    return 0;
}

int main(){

    // char string[29] = "Data Structure and Algorithm\0";
    // char pattern[10] = "Algorithm\0";
    // char string[6] = "ABCABA";
    char string[21] = "she sells sea shells\0";
    char pattern[11] = "she shells\0";
    int m = sizeof(pattern)/sizeof(pattern[0]);
    int len = sizeof(string)/sizeof(string[0]);
    char pi[m];

    // preprocessing
    for (int i=0; i<m; i++){
        // find longest common prefix and suffix before position i
        pi[i] = find_longest_common_prefix_and_suffix(pattern, i);
        // printf("%d", pi[i]);
    }

    // printf("\n");

    // pattern searching
    int current_char_in_string = 0;
    int current_char_in_pattern = 0;
    while (current_char_in_string<len && current_char_in_pattern<m){

        if (string[current_char_in_string] == pattern[current_char_in_pattern+1]){
            current_char_in_string++;
            current_char_in_pattern++;
        }else{
            int common = pi[current_char_in_pattern+1];
            if (common == 0){
                current_char_in_pattern = 0;
                current_char_in_string++;
            }else{
                current_char_in_pattern = common;
            }
        }
        if (current_char_in_string +1 == len){
            break;
        }
    }
    printf("current_char_in_pattern is %d\n", current_char_in_pattern);
    printf("current_char_in_string is %d\n", current_char_in_string);
    printf("=============================================\n");
    if (current_char_in_pattern+1 == m-1){
        printf("%s\n", string);
        for (int i=0; i<=current_char_in_string-m; i++){
            printf(" ");
        } 
        printf("%s\n", pattern);
    }else{
        printf("Pattern not found in the string.\n");
    }
    return 0;
}
