#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _Key
{
    char key_word[6];
} Key;

typedef struct _Val
{
    char val[81];
} Val;

void printTable(const Key *k, const Val *v, const int size);
int binSearch(const Key *k, const Val *v, const int size, const Key key);
void sort(Key *k, Val *v, const int size);
void scramble(Key *k, Val *v, const int size);
void reverse(Key *k, Val *v, const int size);

void getRow(FILE *stream, char *str, const int size);
void swapRows(Key *k, Val *v, const int a, const int b);
int comparator(const Key k1, const Key k2);
int isEqualKeys(const Key k1, const Key k2);
int randomAB(const int a, const int b);
int isSorted(const Key *k, const int size);

int main(void)
{
    const int N = 50;
    int i, cnt, action;
    
    Key keys[N];
    Val values[N];
    Key key;
    FILE *file = fopen("input.txt", "r");

    if (file == NULL)
    {
        printf("Ошибка при открытии файла\n");
        return 0;
    }

    i = 0;

    while (i < N && fscanf(file, "%5s", keys[i].key_word) == 1 && fgets(values[i].val, sizeof(values[i].val), file))
    {
        i++;
    }

    fclose(file);
    cnt = i;

    do
    {
        printf("Меню\n");
        printf("1) Печать\n");
        printf("2) Бинарный поиск\n");
        printf("3) Сортировка\n");
        printf("4) Перемешивание\n");
        printf("5) Реверс\n");
        printf("6) Выход\n");
        printf("Выберите действие\n");
        scanf("%d", &action);

        switch (action)
        {
            case 1:
            {
                printTable(keys, values, cnt);
                break;
            }

            case 2:
            {
                if (!isSorted(keys, cnt))
                    printf("Ошибка. Таблица не отсортирована\n");
                else
                {
                    printf("Введите ключ: ");
                    scanf("%5s", key.key_word);

                    i = binSearch(keys, values, cnt, key);

                    if (i > -1)
                        printf("Найдена строка: %s\n", values[i].val);
                    else
                        printf("Строка с таким ключом не найдена\n");
                }
                break;
            }

            case 3:
            {
                sort(keys, values, cnt);
                break;
            }

            case 4:
            {
                scramble(keys, values, cnt);
                break;
            }

            case 5:
            {
                reverse(keys, values, cnt);
                break;
            }

            case 6:
                break;

            default:
            {
                printf("Ошибка. Такого пункта меню не существует\n");
                break;
            }
        }
    }
    while (action != 6);

    return 0;
}

void printTable(const Key *k, const Val *v, const int size)
{
    int i;
    printf("+-------+----------------------------------------------------------------------------------+\n");
    printf("|  Ключ |                          Значение                                                |\n");
    printf("+-------+----------------------------------------------------------------------------------+\n");

    for (i = 0; i < size; i++)
        printf("| %5s |%60s\n", k[i].key_word, v[i].val);

    printf("+-------+----------------------------------------------------------------------------------+\n");
}

int binSearch(const Key *k, const Val *v, const int size, const Key key)
{
    int start = 0, end = size - 1, mid;

    if (size <= 0)
        return -1;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (isEqualKeys(k[mid], key))
            return mid;
        else if (comparator(k[mid], key))
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

void sort(Key *k, Val *v, const int size)
{
    int gap, i, j;
    Key keyTemp;
    Val valTemp;

    for (gap = size / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < size; i++)
        {
            keyTemp = k[i];
            valTemp = v[i];
            j = i;

            while (j >= gap && comparator(k[j - gap], keyTemp) > 0)
            {
                k[j] = k[j - gap];
                v[j] = v[j - gap];
                j -= gap;
            }

            k[j] = keyTemp;
            v[j] = valTemp;
        }
    }
}

void reverse(Key *k, Val *v, const int size)
{
    int i, j;
    for (i = 0, j = size - 1; i < j; i++, j--)
    {
        swapRows(k, v, i, j);
    }
}

void scramble(Key *k, Val *v, const int size)
{
    int i;
    for (i = size - 1; i > 0; i--)
    {
        int j = randomAB(0, i);
        swapRows(k, v, i, j);
    }
}

void getRow(FILE *stream, char *str, const int size)
{
    int cnt = 0, ch;

    while ((ch = getc(stream)) != '\n' && cnt < size - 1)
        str[cnt++] = ch;

    str[cnt] = '\0';
}

void swapRows(Key *k, Val *v, const int a, const int b)
{
    Key tmpKey;
    Val tmpVal;

    tmpKey = k[a];
    k[a] = k[b];
    k[b] = tmpKey;

    tmpVal = v[a];
    v[a] = v[b];
    v[b] = tmpVal;
}


int comparator(const Key k1, const Key k2)
{
    return strcmp(k1.key_word, k2.key_word);
}

int isEqualKeys(const Key k1, const Key k2)
{
    return strcmp(k1.key_word, k2.key_word) == 0;
}

int randomAB(const int a, const int b)
{
    return a + rand() % (b - a + 1);
}

int isSorted(const Key *k, const int size)
{
    int i;

    for (i = 0; i < size - 1; i++)
        if (comparator(k[i], k[i + 1]) != -1)
            return 0;

    return 1;
}