#include <stdio.h>
#include <string.h>

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        char sentence[1000+1];
        scanf("%s", sentence);
        int len = strlen(sentence);
        int changes;
        scanf("%d", &changes);
        for (int j = 0; j < changes; j++) {
            char key;
            char value;
            getchar();
            scanf("%c %c", &key, &value);
            for (int k = 0; k < len; k++) {
                if(sentence[k] == key) {
                    sentence[k] = value;
                }
            }
        }
        printf("Case #%d: %s\n", i + 1, sentence);
    }
    return 0;
}
