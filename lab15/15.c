#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int min_el = 1000000, max_el = -1000000, min_row_with_min = 0;
    int count = 0;
    scanf("%d", &count);
    int matrix[count][count];
    if (count == 0) {
        printf("No elements\n");
    }
    else {
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                scanf("%d", &matrix[i][j]);
                if (matrix[i][j] < min_el) {
                    min_el = matrix[i][j];
                    min_row_with_min = i;
                }
                else if (matrix[i][j] > max_el) {
                    max_el = matrix[i][j];
                } 
            }
        }

        printf("New matrix:\n");
        for (int i = 0; i < count; i++) {
            int find_max = 0;
            for (int j = 0; j < count; j++) {
                if (matrix[i][j] == max_el) {
                    find_max = 1;
                }
            }
            if (find_max == 1) {
                for (int j = 0; j < count; j++) {
                    printf("%d ", matrix[min_row_with_min][j]);
                }
                printf("\n");
            }
            else if (find_max == 0) {
                for (int j = 0; j < count; j++) {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
        }

    }
    return 0;
}