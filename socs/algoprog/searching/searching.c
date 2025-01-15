#include <stdio.h>
#include <string.h>

#define STR_SIZE 50

struct student {
    char nim[STR_SIZE];
    char name[STR_SIZE];
};

int main() {
    // FILE *file = fopen("../searching/searching.in", "r");
    FILE *file = fopen("testdata.in", "r");
    if (file == NULL) {
        printf("File could not be opened\n");
        return 1;
    }
    int size;
    fscanf(file, "%d", &size);
    struct student students[size];
    for (int i = 0; i < size; i++) {
        fscanf(file, "%s %s\n", &students[i].nim, students[i].name);
    }
    int query;
    fscanf(file, "%d", &query);
    for (int i = 0; i < query; i++) {
        char selected_id[STR_SIZE];
        fscanf(file, "%s", &selected_id);
        struct student selected_student;
        int found = 0;
        for (int j = 0; j < size; j++) {
            int cmp = strcmp(students[j].nim, selected_id);
            if (cmp == 0) {
                selected_student = students[j];
                found = 1;
            }
        }
        if (!found) {
            printf("Case #%d: N/A\n", i + 1);
        } else {
            printf("Case #%d: %s\n", i + 1, selected_student.name);
        }
    }
    return 0;
}