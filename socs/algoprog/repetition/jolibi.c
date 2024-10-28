#include <stdio.h>

int main() {
    int participant;
    scanf("%d", &participant);
    int jojo, lili, bibi;
    scanf("%d %d %d", &jojo, &lili, &bibi);
    int overall[participant];
    for (int i = 0; i < participant; i++) {
        scanf("%d", &overall[i]);
    }
    int allscore = jojo + lili + bibi;
    for (int i = 0; i < participant; i++) {
        allscore += overall[i];
    }
    int allparticipant = participant + 3;
    int average = allscore / allparticipant;
    if (jojo < average) {
        printf("Jojo tidak lolos\n");
    } else {
        printf("Jojo lolos\n");
    }
    if (lili < average) {
        printf("Lili tidak lolos\n");
    } else {
        printf("Lili lolos\n");
    }
    if (bibi < average) {
        printf("Bibi tidak lolos\n");
    } else {
        printf("Bibi lolos\n");
    }
    return 0;
}