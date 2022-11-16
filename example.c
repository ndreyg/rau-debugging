#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_max_len(char **start, char **end) {
    int res = strlen(*start);
    start += 1;
    while (start != end) {
        int other = strlen(*start);
        res = other > res ? other : res;
        start += 1;
    }
    return res;
}

void play(char *array[], int size) {
     char *postfix = "!!!";
     int max_length = find_max_len(array, array + size);
     char *new_str = calloc(max_length + strlen(postfix), 1);
     for (int i = 0; i < size; ++i) {
         int len = strlen(array[i]);
         for (int j = 0; j < len; ++j) {
             new_str[j] = array[i][j];
         }
     }
     strcat(new_str, postfix);
     printf("Result:\n%s\n", new_str);
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Not enough arguments\n");
    }
    printf("Hello, %s, your first letter is '%c'\n", argv[1], argv[1][0]);
    if (argv[1][0] == 'A') {
        printf("You are lucky =)\n");
    }
    char *test[] = {"ABCDEFG", "abcde", "123"};
    play(test, 3);
    play(argv + 2, argc - 3);
    return 0;
}
