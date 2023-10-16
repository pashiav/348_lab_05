#include <stdio.h>

void findCombinations(int score, int combo[], int index) {
    if (score == 0) {
        for (int i = 0; i < index; i++) {
            if (i > 0) {
                printf(", ");
            }
            printf("%d %s", combo[i], (combo[i] == 1) ? "TD" : (combo[i] == 3) ? "FG" : "Safety");
        }
        printf("\n");
        return;
    }

    if (score < 0 || index >= 5) {
        return;
    }

    combo[index] = 1; // TD
    findCombinations(score - 6, combo, index + 1);
    combo[index] = 3; // FG
    findCombinations(score - 3, combo, index + 1);
    combo[index] = 11; // Safety
    findCombinations(score - 2, combo, index + 1);
    combo[index] = 8; // 1TD+2pt
    findCombinations(score - 8, combo, index + 1);
    combo[index] = 7; // 1TD+FG
    findCombinations(score - 7, combo, index + 1);
}

int main() {
    int score;
    while (1) {
        printf("Enter the NFL score (0 or 1 to stop): ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        int combo[5]; // Store a combination of at most 5 plays
        findCombinations(score, combo, 0);
    }

    return 0;
}
