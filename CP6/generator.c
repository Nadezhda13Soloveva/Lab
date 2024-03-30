#include <stdio.h>
#include "person.h"
#include <string.h>

int readPerson(Person *p);

int main(int count_arg, char *args[]) {

    Person p;
    FILE *file = NULL;

    if (count_arg != 2)
    {
        printf("Usage: %s filename\n", args[0]);

        return 1;
    }

    file = fopen(args[1], "wb");

    if (file == NULL)
    {
        printf("Openfile error\n");

        return 1;
    }

    int result;
	printf("Enter 12 words for a person (or leave blank line to exit):\n");
    while ((result = readPerson(&p)) == 1) {
        fwrite(&p, sizeof(p), 1, file);
    }

    fclose(file);

    return 0;
}

int readPerson(Person *p)
{
    char input[100]; // Максимальная длина строки - 200 символов
    char *word;
        
    if (fgets(input, sizeof(input), stdin) != NULL) {
        if (strlen(input) <= 1) {
            return 0; // Пустая строка
        }

        word = strtok(input, " \n");
        strcpy(p->surname, word);

        for (int i = 0; i < 11; i++) {
            word = strtok(NULL, " \n");
            if (word == NULL) {
                printf("Not enough words entered!\n");
                return -1; // Недостаточно слов
            }
            switch(i) {
                case 0:
                    strcpy(p->count_proc, word);
                    break;
                case 1:
                    strcpy(p->type_proc, word);
                    break;
                case 2:
                    strcpy(p->memory, word);
                    break;
                case 3:
                    strcpy(p->type_video, word);
                    break;
                case 4:
                    strcpy(p->videomemory, word);
                    break;
                case 5:
                    strcpy(p->type_vin, word);
                    break;
                case 6:
                    strcpy(p->count_vin, word);
                    break;
                case 7:
                    strcpy(p->volume_vin, word);
                    break;
				case 8:
                    strcpy(p->count_int, word);
                    break;
				case 9:
                    strcpy(p->count_per, word);
                    break;
				case 10:
                    strcpy(p->system, word);
                    break;
            }
        }
        return 1; 
    } 
    return -1; 
}