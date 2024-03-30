#include <stdio.h>
#include "person.h"
#include <stdlib.h>
#include <string.h>

void displayTable(FILE *file);
void displayFilteredTable(FILE *file);

int main(int count_arg, char *args[]) {

    if (count_arg < 3)
    {
        printf("Usage: %s filename -f/-p\n", args[0]);
        return 1;
    }

    FILE *file = fopen(args[1], "rb");
    
    if (file == NULL)
    {
        printf("File open error\n");
        return 1;
    }

    if (strcmp(args[2], "-f") == 0) {
        displayTable(file);
    } else if (strcmp(args[2], "-p") == 0) {
        displayFilteredTable(file);
    } else {
        printf("Invalid parameter, please use -f or -p\n");
    }

    fclose(file);

    return 0;
}

void displayTable(FILE *file) {
    Person p;

    printf("+--------------+----------------+-----------+-----------+-----------------+----------------+------------+---------------+-------------------+----------------------+-------------------------+---------+\n");
    printf("|   Surname    | Count of proc. | Processor | Memory GB | Videocontroller | Videomemory GB | Winchester | Count of win. | Volume of win. GB | Count of int. contr. | Count of perif. devices |   OS    |\n");
	printf("+--------------+----------------+-----------+-----------+-----------------+----------------+------------+---------------+-------------------+----------------------+-------------------------+---------+\n");

    while (fread(&p, sizeof(p), 1, file) == 1) {
        printf("| %12s | %14s | %9s | %9s | %15s | %14s | %10s | %13s | %17s | %20s | %23s | %7s |\n", p.surname, p.count_proc, p.type_proc, p.memory, p.type_video, p.videomemory, p.type_vin, p.count_vin, p.volume_vin, p.count_int, p.count_per, p.system);
        printf("+--------------+----------------+-----------+-----------+-----------------+----------------+------------+---------------+-------------------+----------------------+-------------------------+---------+\n");

	}
}

void displayFilteredTable(FILE *file) {
    Person p;
	int count = 0;

    while (fread(&p, sizeof(p), 1, file) == 1) {
        if (!(strcmp(p.type_proc, "Intel") == 0 && strcmp(p.system, "Windows") == 0)) {
			count += 1;
			if (count == 1) {
				printf("+--------------+----------------+-----------+-----------+-----------------+----------------+------------+---------------+-------------------+----------------------+-------------------------+---------+\n");
    			printf("|   Surname    | Count of proc. | Processor | Memory GB | Videocontroller | Videomemory GB | Winchester | Count of win. | Volume of win. GB | Count of int. contr. | Count of perif. devices |   OS    |\n");
				printf("+--------------+----------------+-----------+-----------+-----------------+----------------+------------+---------------+-------------------+----------------------+-------------------------+---------+\n");

				printf("| %12s | %14s | %9s | %9s | %15s | %14s | %10s | %13s | %17s | %20s | %23s | %7s |\n", p.surname, p.count_proc, p.type_proc, p.memory, p.type_video, p.videomemory, p.type_vin, p.count_vin, p.volume_vin, p.count_int, p.count_per, p.system);
        		printf("+--------------+----------------+-----------+-----------+-----------------+----------------+------------+---------------+-------------------+----------------------+-------------------------+---------+\n");
			}
			else {
				printf("| %12s | %14s | %9s | %9s | %15s | %14s | %10s | %13s | %17s | %20s | %23s | %7s |\n", p.surname, p.count_proc, p.type_proc, p.memory, p.type_video, p.videomemory, p.type_vin, p.count_vin, p.volume_vin, p.count_int, p.count_per, p.system);
        		printf("+--------------+----------------+-----------+-----------+-----------------+----------------+------------+---------------+-------------------+----------------------+-------------------------+---------+\n");
			}
        }
    }
	if (count == 0) {
		printf("Not found any students with a computer platform other than WINTEL :( \n");
	}
}