#include <stdio.h>

int main() {
    char courseCode[10+1];
    int startHour, startMinute, endHour, endMinute;
    for (int i = 0; i < 5; i++) {
        scanf("%s %d:%d-%d:%d", courseCode, &startHour, &startMinute, &endHour, &endMinute);
        startHour -= 1;
        endHour -= 1;
        printf("%s %02d:%02d-%02d:%02d\n", courseCode, startHour, startMinute, endHour, endMinute);
    }
    return 0;
}
