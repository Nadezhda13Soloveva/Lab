#include <stdio.h>
#include <string.h>

int main() {
    char number[100];
    int num;
    char output[100][100];
    int i = 0;

    fgets(number, sizeof(number), stdin);
    number[strcspn(number, "\n")] = 0;

    while (strcmp(number, "") != 0) {
        char second_symbol = number[1];
        char  prelast_symbol = number[strlen(number)-2];
        number[1] = prelast_symbol;
        number[strlen(number)-2] = second_symbol;
        strcpy(output[i], number);
        i++;
        
        fgets(number, sizeof(number), stdin);
        number[strcspn(number, "\n")] = 0;
    }

    for (int j = 0; j < i; j++) {
        printf("%s\n", output[j]);
    }
    return 0;
}