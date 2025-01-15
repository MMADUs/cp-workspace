#include <stdio.h>
#include <string.h>

struct data {
    char shortWord[50], longWord[50];
};

int main() {
    // FILE *file = fopen("../searching/file.in", "r");
    FILE *file = fopen("testdata.in", "r");
    int T;
    fscanf(file, "%d\n", &T);
    struct data data[T];
    for (int i = 0; i < T; i++) {
        fscanf(file, "%[^#]#%[^\n]\n", data[i].shortWord, data[i].longWord);
    }
    int M;
    fscanf(file, "%d\n", &M);
    for (int i = 0; i < M; i++) {
        char line[100], output[1000] = "";
        fscanf(file, "%[^\n]\n", line);
        char *word = strtok(line, " ");
        while (word != NULL) {
            int found = 0;
            for (int j = 0; j < T; j++) {
                if (strcmp(word, data[j].shortWord) == 0) {
                    strcat(output, data[j].longWord);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcat(output, word);
            }
            word = strtok(NULL, " ");
            if(word != NULL) {
                strcat(output, " ");
            }
        }
        printf("Case #%d:\n%s\n", i + 1, output);
    }
    return 0;
}