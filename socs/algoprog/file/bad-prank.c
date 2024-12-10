#include <stdio.h>
#include <string.h>

void parseChar(char encryption[]) {
    const int len = strlen(encryption);
    for (int i = 0; i < len; i++) {
        switch (encryption[i]) {
            case '0':
                encryption[i] = 'O';
            break;
            case '1':
                encryption[i] = 'I';
            break;
            case '3':
                encryption[i] = 'E';
            break;
            case '4':
                encryption[i] = 'A';
            break;
            case '5':
                encryption[i] = 'S';
            break;
            case '6':
                encryption[i] = 'G';
            break;
            case '7':
                encryption[i] = 'T';
            break;
            case '8':
                encryption[i] = 'B';
            break;
            default:
                break;  // ignore the rest
        }
    }
}


int main() {
    // open file
    FILE *file = fopen("../file/bad-prank.in", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    // test case
    int tc;
    fscanf(file, "%d\n", &tc);
    // process each test case
    for (int i = 0; i < tc; i++) {
        // number of shift
        int shift;
        fscanf(file, "%d\n", &shift);
        // raw encryption
        char encryption[1001];
        fscanf(file, "%[^\n]\n", encryption);
        // parse int to char
        parseChar(encryption);
        // shift char individually
        const int len = strlen(encryption);
        printf("Case #%d: ", i + 1);
        for (int j = 0; j < len; j++) {
            // check for only shifting uppercase letters
            if (encryption[j] >= 'A' && encryption[j] <= 'Z') {
                char shiftedChar = encryption[j] - shift;
                // wrap around if the shift goes below 'A'
                if (shiftedChar < 'A') {
                    shiftedChar += 26;
                }
                printf("%c", shiftedChar);
            } else {
                printf("%c", encryption[j]);
            }
        }
        printf("\n");
    }
    fclose(file);
    return 0;
}