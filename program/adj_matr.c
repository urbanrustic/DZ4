#include "insertion.h"


//Матрица смежности
void adjacency(void) {

    printf("%s\n", "Формат ввода: между числами пробел, в конце каждой строки должен быть Enter, даже в последней");

    FILE *fp = fopen("test.txt", "r");
    if (!fp) {
        system("touch test.txt");
        fp = fopen("test.txt", "r");
    }
    fclose(fp);
    
    delay(5);
    system("wslview test.txt");

    char c;
    printf("%s", "Файл готов и сохранён y(YES)/n(NO): ");
    c = getchar();
    if ((c = getchar())!='y') {
        printf("%s\n", "Вы отменили работу программы");
        return;
    }
    
    FILE *fp1 = fopen("test.txt", "r");

    int apex = counter_apex(fp1);

    rewind(fp1);//Возвращаемся в начало файла

    //Считываем файл в массив
    int *ar = (int*)malloc(apex*apex*sizeof(int));
    int i = 0;
    int count = 0;
    int fl1 = 0, fl2 = 0;

    while ((c = fgetc(fp1)) != EOF) {
    
        if (!isdigit(c) && (c != ' ') && (c != '\r') && (c != '\n')) {
            printf("%s\n", "!!!Буквы не должны присутствовать в матрице");
            free(ar);
            fclose(fp1);
            return;
        }
        if (isdigit(c)) {
            count = (c - '0') + count*10;
            fl1 = 0;
            fl2 = 0;
        }
        //Проверка на правильность ввода матрицы
        if (((c == ' ') && fl1) || ((c == '\n') && fl2)) {
            printf("%s\n", "!!!Между цифрами больше одного пробела или одного переноса строки пробела");
            free(ar);
            fclose(fp1);
            return;
        }
        //Заполнение массива
        if (c == ' ') {
            ar[i++] = count;
            count = 0;
            fl1 = 1;
        }
        else if (c == '\n') {
            ar[i++] = count;
            count = 0;
            fl2 = 1;
        }
    }

    if (!fl2) {
        printf("%s\n", "!!!В конце тоже перенос должен быть");
        free(ar);
        fclose(fp1);
        return;
    }
    
    fclose(fp1);

    int *visited = (int*)malloc((apex+1)*sizeof(int));
    dfs(0, apex, ar, visited);
    free(ar);

    printvisit(0, apex, visited, 0);

    delay(2);
    free(visited);
    system("wslview answer.txt");
}
