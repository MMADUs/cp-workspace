#include <stdio.h>
#include <string.h>

#define STR_SIZE 50

struct student {
    char name[STR_SIZE];
    int score;
};

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int len;
        scanf("%d", &len);
        struct student students[len];
        for (int j = 0; j < len; j++) {
            scanf(" %[^#]#%d", students[j].name, &students[j].score);
        }
        for (int j = 0; j < len - 1; j++) {
            for (int k = 0; k < len - j - 1; k++) {
                if (students[k].score < students[k + 1].score || (students[k].score == students[k + 1].score && strcmp(students[k].name, students[k + 1].name) > 0)) {
                    struct student temp = students[k];
                    students[k] = students[k + 1];
                    students[k + 1] = temp;
                }
            }
        }
        char query[STR_SIZE];
        scanf("%s", query);
        for (int j = 0; j < len; j++) {
            if (strcmp(students[j].name, query) == 0) {
                printf("Case #%d: %d\n", i + 1, j + 1);
                break;
            }
        }
    }
    return 0;
}

// 2
// 3
// Jojo#40
// Lili#80
// Bibi#90
// Lili
// 3
// Jojo#100
// Lili#80
// Bibi#90
// Lili