#include <stdio.h>
#include <string.h>

struct Name {
    char friend[50];
    char tree[50];
};

// search name
int linearSearch(struct Name names[], const char* target, const int size) {
    for (int i = 0; i < size; i++) {
        if(strcmp(names[i].friend, target) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    // open file
    FILE *file = fopen("../file/planting-tree.in", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    // get the array size
    int size;
    fscanf(file, "%d\n", &size);
    // store name as struct list in array
    struct Name name_list[size];
    for (int i = 0; i < size; i++) {
        struct Name name;
        fscanf(file, "%[^#]#%[^\n]\n", name.friend, name.tree);
        name_list[i] = name;
    }
    // the count for displaying tree
    int count;
    fscanf(file, "%d\n", &count);
    // list of target name
    char target[count][50];
    for (int i = 0; i < count; i++) {
        fscanf(file, "%[^\n]\n", target[i]);
    }
    // display tree name based on target name
    for (int i = 0; i < count; i++) {
        const int index = linearSearch(name_list, target[i], size);
        if (index != -1) {
            printf("Case #%d: %s\n", i + 1, name_list[index].tree);
        } else {
            printf("Case #%d: N/A\n", i + 1);
        }
    }
    fclose(file);
    return 0;
}