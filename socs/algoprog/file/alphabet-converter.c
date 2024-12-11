#include <stdio.h>
#include <string.h>

#define SENTENCE_SIZE 101
#define ALPHABET_SIZE 26

void convert(char from, char to, char str[]){
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        if (str[i] == from){
            str[i] = to;
        }
    }
}

void countChar(const char str[], int counter[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        counter[str[i] - 'A']++;
    }
}

void printChar(int counter[]){
    for (int i = 0; i < 26; i++){
        if (counter[i] > 0){
            printf("%c %d\n", (char)i+'A', counter[i]);
        }
    }
}

int main(){
    // open file
    FILE *file = fopen("../file/alphabet-converter.in","r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    // get test case
    int tc;
    fscanf(file,"%d\n",&tc);
    // process changes
    for (int i = 0; i < tc; i++){
        // get sentence
        char sentence[SENTENCE_SIZE];
        fscanf(file,"%[^\n]\n", sentence);
        // get number of changes
        int changes;
        fscanf(file,"%d\n", &changes);
        int counter[ALPHABET_SIZE] = {0};
        int converted[ALPHABET_SIZE] = {0};
        char exist;
        char replace;
        // get changes
        for(int j = 0; j < changes; j++){
            fscanf(file,"%c %c\n", &exist, &replace);
            if(converted[exist - 'A'] == 1){
                continue;
            }
            convert(exist, replace, sentence);
            converted[exist - 'A'] = 1;
        }
        countChar(sentence, counter);
        printChar(counter);
    }
    fclose(file);
    return 0;
}