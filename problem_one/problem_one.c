#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void sales_summary(double sales[],char *months[]){
    printf("Sales summary:\n");
    double min_sales = 1000000000000;
    char *min_month;
    for (int i = 0; i < 12; i++) {
        if (sales[i] < min_sales) {
            min_sales = sales[i];
            min_month = months[i];
        }
    }
    printf("Minimum sales: $%-10.2f   (%s)",min_sales,min_month);
    printf("\n");
    
    double max_sales = 0;
    char *max_month;
    for (int i = 0; i < 12; i++) {
        if (sales[i] > max_sales) {
            max_sales = sales[i];
            max_month = months[i];
        }
    }

    printf("Maximum sales: $%-10.2f   (%s)",max_sales,max_month);
    printf("\n");

    double total_sales = 0;
    for (int i = 0; i < 12; i++) {
        total_sales += sales[i];
    }
    double average_sales = total_sales/12;


    printf("Average sales: $%-10.2f",average_sales);
    printf("\n");

}

void six_month(double sales[],char *months[])
    {
    printf("Six-Month Moving Average Report:\n");
    double January_June;
    
    for (int i = 0; i < 7; i++) {
        double sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        double average = sum / 6;
        printf("%-12s - %-15s $%-15.2f\n", months[i], months[i + 5], average);
    }
    }

struct FloatMonthPair 
    {
    float floatValue;
    char *month;
    };

int compare(const void *a, const void *b)
    {
    return (int)(((struct FloatMonthPair *)b)->floatValue - ((struct FloatMonthPair *)a)->floatValue);
    }


void high_to_low(double sales[], char *months[], int numPairs) {
    struct FloatMonthPair *floatMonthPairs = malloc(numPairs * sizeof(struct FloatMonthPair));
    for (int i = 0; i < numPairs; i++) {
        floatMonthPairs[i].floatValue = sales[i];
        floatMonthPairs[i].month = months[i];
    }

    qsort(floatMonthPairs, numPairs, sizeof(struct FloatMonthPair), compare);

    for (int i = 0; i < numPairs; i++) {
        //printf("%.2f - %s\n", floatMonthPairs[i].floatValue, floatMonthPairs[i].month);
        printf("%-14s   $%.2f\n",floatMonthPairs[i].month, floatMonthPairs[i].floatValue);
    }

    free(floatMonthPairs);
}


int main()
{
    // Read in the file
    double sales[] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Check for error in file existence
    printf("Monthly sales report for 2022:\n");
    printf("Month             Sales\n");


    for (int i = 0; i < 12; i++) {
        printf("%-14s $%.2f\n", months[i], sales[i]);
    }

    printf("\n");

    sales_summary(sales,months);
    printf("\n");
    six_month(sales,months);
    printf("\n");

    printf("Sales Report (Highest to Lowest):\n");
    printf(" Month             Sales\n");
    high_to_low(sales,months,12);

    return 0;
}
