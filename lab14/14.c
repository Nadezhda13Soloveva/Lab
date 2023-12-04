#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

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
            }
        }

        printf("Elements: ");

        int i, j;
        int startRowIndex = 0, endRowIndex = count - 1;
        int startColumnIndex = 0, endColumnIndex = count - 1;

        while (startRowIndex <= endRowIndex && startColumnIndex <= endColumnIndex) {
            // Вывод верхней строки
            for (j = startColumnIndex; j <= endColumnIndex; j++) {
                printf("%d ", matrix[startRowIndex][j]);
            }
            startRowIndex++;

            // Вывод правого столбца
            for (i = startRowIndex; i <= endRowIndex; i++) {
                printf("%d ", matrix[i][endColumnIndex]);
            }
            endColumnIndex--;

            // Вывод нижней строки
            if (startRowIndex <= endRowIndex) {
                for (j = endColumnIndex; j >= startColumnIndex; j--) {
                    printf("%d ", matrix[endRowIndex][j]);
                }
                endRowIndex--;
            }

            // Вывод левого столбца
            if (startColumnIndex <= endColumnIndex) {
                for (i = endRowIndex; i >= startRowIndex; i--) {
                    printf("%d ", matrix[i][startColumnIndex]);
                }
                startColumnIndex++;
            }
        }
    }
    return 0;
}
