#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

const int I = 12;
const int J = 4;
const int L_const = 3;

int main() {
	int i = I;
	int j = J;
	int k = 0;
	int L = L_const;
       int pre_i = i;
       int pre_j = j;
       int pre_L = L;

	while (k < 50) {
                pre_i = i;
                pre_j = j;
                pre_L = L;
                i = ((pre_i * pre_j / (abs(pre_L) + 1) + pre_j * pre_L / (abs(pre_i) + 1) + pre_i * pre_L / (abs(pre_j) + 1)) % 30);
                j = (i * MAX(pre_j, pre_L) % 20 + pre_j * MIN(pre_i, pre_L) % 30 - k);
                L = (MAX(MAX(pre_i * pre_j, pre_i * pre_L), MAX(pre_i * pre_L, pre_j * pre_L)) % 30 + 20);
                k++;
                if (i + j + 10 >= 0 && i + j + 20 <= 0) {
			printf("Точка попала в заданную область плоскости на шаге %d\n", k);
			printf("Время попадания: %d\n", k);
			printf("Координаты точки: (%d, %d)\n", i, j);
			printf("Значение динамического параметра движения: %d\n", L);
			return 0;
		};
	};

	printf("Точка не попала в заданную область плоскости за %d шагов\n", 50);
	printf("Время окончания движения: %d\n", 50);
	printf("Координаты точки: (%d, %d)\n", i, j);
	printf("Значение динамического параметра движения: %d\n", L);
	return 0;
}

