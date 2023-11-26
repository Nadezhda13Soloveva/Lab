#include <stdio.h>
#include <string.h>

int main() {
    char number[100];
    char output[100][100];
    int i = 0;

    fgets(number, sizeof(number), stdin);
    number[strcspn(number, "\n")] = 0;

    while (strcmp(number, "") != 0) {
        if(number[0] == '-') {
            if(strlen(number)>2) {
                char second_symbol = number[2];
                char  prelast_symbol = number[strlen(number)-2];
                number[2] = prelast_symbol;
                number[strlen(number)-2] = second_symbol;
            }
        }
        else {
            if(strlen(number)>1) {
                char second_symbol = number[1];
                char  prelast_symbol = number[strlen(number)-2];
                number[1] = prelast_symbol;
                number[strlen(number)-2] = second_symbol;
            }
        }
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