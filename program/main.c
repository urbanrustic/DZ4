#include "insertion.h"


int main(void) {

    char c;
    printf("%s", "Введите тип матрицы(1 - смежности, 2 - вид 1-2 3-4): ");
    c = getchar();
    switch (c-'0') {
    case 1:
        printf("%s\n", "Была выбрана матрица смежности");
        adjacency();    
        break;
    case 2:
        printf("%s\n", "Был выбран вид 1-2 3-4");
        other_view();
        break;
    default:
        printf("%s\n", "Вы не выбрали не один из доступных типов матриц...");
        break;
    }

    return 0;
}
