#include <stdio.h>
#include <string.h>

#define STR_SIZE 50
#define MAX_LINES 100
#define MAX_WORDS 100

struct Sentence {
    char key[STR_SIZE];
    char value[STR_SIZE];
};

void Merge(struct Sentence arr[], const int left, const int mid, const int right) {
    const int leftSize = mid - left + 1;
    const int rightSize = right - mid;
    struct Sentence leftArr[leftSize];
    struct Sentence rightArr[rightSize];
    for(int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for(int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    int idx = left;
    int leftIdx = 0;
    int rightIdx = 0;
    while (leftIdx < leftSize && rightIdx < rightSize) {
        if(strcmp(leftArr[leftIdx].key, rightArr[rightIdx].key) < 0) {
            arr[idx] = leftArr[leftIdx];
            idx++;
            leftIdx++;
        } else {
            arr[idx] = rightArr[rightIdx];
            idx++;
            rightIdx++;
        }
    }
    while(leftIdx < leftSize) {
        arr[idx] = leftArr[leftIdx];
        idx++;
        leftIdx++;
    }
    while(rightIdx < rightSize) {
        arr[idx] = rightArr[rightIdx];
        idx++;
        rightIdx++;
    }
}

void Divide(struct Sentence arr[], const int left, const int right) {
    if (left >= right) {
        return;
    }
    const int mid = (left+right)/2;
    Divide(arr, left, mid);
    Divide(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

int binarySearch(struct Sentence arr[], const char target[], int left, int right) {
    while (left <= right) {
        const int mid = left + (right - left) / 2;
        const int cmp = strcmp(arr[mid].key, target);
        if (cmp == 0) {
            return mid;
        }
        if (cmp > 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    // open file
    FILE *file = fopen("testdata.in", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    // data size
    int size;
    fscanf(file, "%d\n", &size);
    // data seeding
    struct Sentence data[size];
    for (int i = 0; i < size; i++) {
        fscanf(file, "%[^#]#%[^\n]\n", data[i].key, data[i].value);
    }
    // sort key to prep search
    Divide(data, 0, size - 1);
    // for (int i = 0; i < size; i++) {
    //     printf("%s-%s\n", data[i].key, data[i].value);
    // }
    // query count
    int count;
    fscanf(file, "%d", &count);
    // get query
    int line_count = 0;
    int word_count[MAX_LINES] = {0};
    char query[MAX_LINES][MAX_WORDS][STR_SIZE];
    // parser
    while (line_count < count) {
        // load all sentence
        const int result = fscanf(file, "%s", query[line_count][word_count[line_count]]);
        if (result == 1) {
            word_count[line_count]++;
            // check if end of line
            if (fgetc(file) == '\n') {
                // query operations
                printf("Case #%d:\n", line_count + 1);
                for (int i = 0; i < word_count[line_count]; i++) {
                    const int index = binarySearch(data, query[line_count][i], 0, size - 1);
                    if (index != -1) { // check if value exist
                        const struct Sentence sentence = data[index];
                        printf("%s", sentence.value);
                    } else {
                        printf("%s", query[line_count][i]); // display query if not found
                    }
                    if (i < word_count[line_count] - 1) {
                        printf(" ");
                    } else {
                        printf("\n");
                    }
                }
                // go to next line
                line_count++;
            }
        } else {
            break;
        }
    }
    fclose(file);
    return 0;
}