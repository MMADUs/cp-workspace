#include <stdio.h>
#include <string.h>

#define STR_SIZE 101
#define MAX_LINES 101
#define MAX_WORDS 101

struct Sentence {
    char key[STR_SIZE];
    char value[STR_SIZE];
};

int main() {
    FILE *file = fopen("../searching/file.in", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    int size;
    fscanf(file, "%d", &size);
    struct Sentence data[size];
    for (int i = 0; i < size; i++) {
        fscanf(file, "%[^#]#%[^\n]", data[i].key, data[i].value);
    }
    int count;
    fscanf(file, "%d", &count);
    int line_count = 0;
    int word_count[MAX_LINES] = {0};
    char query[MAX_LINES][MAX_WORDS][STR_SIZE];
    while (line_count < count) {
        const int result = fscanf(file, "%s", query[line_count][word_count[line_count]]);
        if (result == 1) {
            word_count[line_count]++;
            if (fgetc(file) == '\n') {
                line_count++;
            }
        } else {
            break;
        }
    }

    // printf("Parsed key value:\n");
    // for (int i = 0; i < size; i++) {
    //     printf("key: %s value: %s\n", data[i].key, data[i].value);
    // }
    // // Output result
    // printf("Parsed words:\n[\n");
    // for (int i = 0; i < line_count; i++) {
    //     printf("  [");
    //     for (int j = 0; j < word_count[i]; j++) {
    //         printf("\"%s\"", query[i][j]);
    //         if (j < word_count[i] - 1) printf(", ");
    //     }
    //     printf("]");
    //     if (i < line_count) printf(",");
    //     printf("\n");
    // }
    // printf("]\n");

    fclose(file);
    return 0;
}