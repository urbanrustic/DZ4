#include "insertion.h"


//Функция задержки передаваемое в секундах
void delay(int s) {

    int c = clock() + s*1000000;
    while (clock() < c);
}

//Подсчёт количества вершин
int counter_apex(FILE *fp1) {

    int apex = 1;
    char c;
    while ((c = fgetc(fp1))!='\n') {
        if (c ==' ') {
            apex++;
        }  
    }
    return apex;
}

//Максимальная вершина
int find_max(FILE *fp1) {

    int count = 0, max = 0;
    char c;
    while ((c = fgetc(fp1)) != EOF) {
        if (isdigit(c)) {
            count = c-'0' + count*10;
        }
        else if ((c == '-') || (c == '\n')) {
            count = 0;
        }
        if (count > max) {
            max = count;
        }
    }
    return max;
}

//
void printvisit(int k, int length, int *visited, int key) {

    FILE *fp2 = fopen("answer.txt", "w");

    if (key == 1) {
        fprintf(fp2, "%s\n%s\n", "Обход по графу", "1-Можно попасть   0-Нельзя");
        for (int i = k; i < length; i++) {
            fprintf(fp2, "Вершина [%d] - %d\n", i, visited[i]);
        }
    }
    else {
        fprintf(fp2, "%s\n%s\n", "Обход по графу", "1-Можно попасть   0-Нельзя");
        for (int i = k; i < length; i++) {
            fprintf(fp2, "Вершина [%d] - %d\n", i+1, visited[i]);
        }
    }
    fclose(fp2);
}
