#include <stdio.h>

int main() {
    int team;
    scanf("%d", &team);
    int allPeople[team][team];
    int countTeam[team + 1];
    for (int i = 1; i <= team; i++) {
        countTeam[i] = 0;
    }
    for (int i = 0; i < team; i++) {
        for (int j = 0; j < team; j++) {
            scanf("%d", &allPeople[i][j]);
            if (allPeople[i][j] != 0) {
                countTeam[allPeople[i][j]]++;
            }
        }
    }
    int incompleteTeams = 0;
    for (int i = 1; i <= team; i++) {
        if (countTeam[i] < team) {
            incompleteTeams++;
        }
    }
    printf("%d\n", incompleteTeams);
    return 0;
}