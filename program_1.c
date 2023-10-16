#include <stdio.h>

#define NUM_MONTHS 12

void salesReport(double sales[]) {
    printf("Monthly sales report for 2022:\n");
    printf("Month      Sales\n");

    char *months[] = {"January", "February", "March", "April", "May", "June", "July",
                      "August", "September", "October", "November", "December"};

    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%-10s $%.2f\n", months[i], sales[i]);
    }
}

void salesSummary(double sales[]) {
    double minS = sales[0];
    double maxS = sales[0];
    double totalS = sales[0];

    for (int i = 1; i < NUM_MONTHS; i++) {
        if (sales[i] < minS) {
            minS = sales[i];
        }
        if (sales[i] > maxS) {
            maxS = sales[i];
        }
        totalS += sales[i];
    }

    double avgS = totalS / NUM_MONTHS;

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (January)\n", minS);
    printf("Maximum sales: $%.2f (December)\n", maxS);
    printf("Average sales: $%.2f\n", avgS);
}

void calcMovingAverages(double sales[]) {
    printf("\nSix-Month Moving Average Report:\n");

    char *months[] = {"January", "February", "March", "April", "May", "June", "July",
                      "August", "September", "October", "November", "December"};

    for (int i = 0; i < NUM_MONTHS - 5; i++) {
        double sum = 0;
        for (int j = 0; j < 6; j++) {
            sum += sales[i + j];
        }

        // Use a fixed width for month and range columns
        printf("%-10s - %-10s $%.2f\n", months[i], months[i + 5], sum / 6);
    }
}

void salesReportDescending(double sales[]) {
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month        Sales\n");

    char *months[] = {"January", "February", "March", "April", "May", "June", "July",
                      "August", "September", "October", "November", "December"};

    // Create a copy of the sales array and its corresponding months for sorting
    double sortedS[NUM_MONTHS];
    char *sortedM[NUM_MONTHS];

    for (int i = 0; i < NUM_MONTHS; i++) {
        sortedS[i] = sales[i];
        sortedM[i] = months[i];
    }

    // Sort the sales data and corresponding months in descending order
    for (int i = 0; i < NUM_MONTHS - 1; i++) {
        for (int j = i + 1; j < NUM_MONTHS; j++) {
            if (sortedS[i] < sortedS[j]) {
                // Swap sales
                double tempS = sortedS[i];
                sortedS[i] = sortedS[j];
                sortedS[j] = tempS;
                // Swap months
                char *tempM = sortedM[i];
                sortedM[i] = sortedM[j];
                sortedM[j] = tempM;
            }
        }
    }

    // Print the sorted sales report
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%-12s $%.2f\n", sortedM[i], sortedS[i]);
    }
}

int main() {
    double sales[] = {
        23458.01,
        40112.00,
        56011.85,
        37820.88,
        37904.67,
        60200.22,
        72400.31,
        56210.89,
        67230.84,
        68233.12,
        80950.34,
        95225.22
    };

    salesReport(sales);
    salesSummary(sales);
    calcMovingAverages(sales);
    salesReportDescending(sales);

    return 0;
}
