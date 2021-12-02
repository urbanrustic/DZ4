#include "insertion.h"


//Вид 1-2 3-4
void other_view(void) {

    printf("%s\n", "Формат ввода: между числами дефис, в конце каждой строки должен быть Enter, даже в последней");

    FILE *fp = fopen("test.txt", "r");
    if (!fp) {
        system("touch test.txt");
        fp = fopen("test.txt", "r");
    }
    fclose(fp);

    delay(8);
    system("wslview test.txt");

    char c;
    printf("%s", "Файл готов и сохранён y(YES)/n(NO): ");
    c = getchar();
    if ((c = getchar())!='y') {
        printf("%s\n", "Вы отменили работу программы");
        return;
    }

    FILE *fp1 = fopen("test.txt", "r");
    
    int apex = find_max(fp1);

    int *ar = (int *)malloc((apex+1)*(apex+1) * sizeof(int));
    
    int fl1 = 0, fl2 = 0;
    int p_1 = 0, p_2 = 0;
    rewind(fp1);

    while ((c = fgetc(fp1)) != EOF) {
        if (p_1 && p_2 && fl1 && fl2) {
            ar[p_1*(apex+1) + p_2] = 1;
            ar[p_2*(apex+1) + p_1] = 1;
            fl1 = 0;
            fl2 = 0;
            p_2 = 0;
            p_1 = 0;
        }
        //Проверка на правильный ввод
        if ((c == ' ') || (!isdigit(c) && (c != '\r') && (c != '\n') && (c != '-'))) {
            printf("%s\n", "Букв и пробелов не должно быть в матрице");
            free(ar);
            fclose(fp1);
            return;
        }
        if (((c == '-') && fl1) || ((c == '\n') && fl2)) {
            printf("%s\n", "Между цифрами больше одного дефиса или одного переноса строки пробела");
            free(ar);
            fclose(fp1);
            return;
        }
        
        if (c == '\n') {
            fl2 = 1;
        }
        if (c == '-') {
            fl1 = 1;
        }
        if (isdigit(c) && fl1 && !fl2) {
            p_2 = c-'0' + p_2*10;
        }
        else if (isdigit(c)) {
            p_1 = c-'0' + p_1*10;
        }
        if (!fl1 && fl2) {
            fl1 = 0;
            fl2 = 0;
            p_2 = 0;
            p_1 = 0;
        }
        
    }

    if (p_1 && p_2 && fl1) {
            ar[p_1*(apex+1) + p_2] = 1;
            ar[p_2*(apex+1) + p_1] = 1;
            fl1 = 0;
            p_2 = 0;
            p_1 = 0;
    }

    fclose(fp1);

    int *visited = (int*)malloc((apex+1)*sizeof(int));

    dfc(apex, apex+1, ar, visited);
    free(ar);

    printvisit(1, apex+1, visited, 1);
    
    delay(5);
    free(visited);
    system("wslview answer.txt");    
}
