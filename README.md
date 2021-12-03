# Homework_4
<h1 align="center">DFS (Поиск в глубину)</h1>
<h2 align="center">Поставленная задача</h2>
<p>Написать на языке программирования C(Си) DFS(Поиск в глубину) - это рекурсивный алгоритм поиска всех вершин графа или древовидной структуры. Написать считывание и проход для двух видов матриц.</p>
<h2 align="center">Описание</h2>
<h3>Алгоритм</h3>
<p>Стратегия поиска в глубину, как и следует из названия, состоит в том, чтобы идти «вглубь» графа, насколько это возможно. Алгоритм поиска описывается рекурсивно: перебираем все исходящие из рассматриваемой вершины рёбра. Если ребро ведёт в вершину, которая не была рассмотрена ранее, то запускаем алгоритм от этой нерассмотренной вершины, а после возвращаемся и продолжаем перебирать рёбра. Возврат происходит в том случае, если в рассматриваемой вершине не осталось рёбер, которые ведут в нерассмотренную вершину.</p>
<h3>Реализация на языки C(Си), файл dfc.c</h3>


```c
#include "insertion.h"


void dfs(int param, int length, int *arr, int *visited) {

    if (visited[param]) {
        return;
    }
    
    visited[param] = 1;
    for (int i = 1; i < length; i++) {
        if ((visited[i] == 0) && (arr[param*length + i] == 1)) {
            dfs(i, length, arr, visited);
        }
    }
}

```


<h3 align="center">Структурная схема</h3>

<p align="center">![Untitled Diagram-Page-1](https://user-images.githubusercontent.com/81951508/144552658-c9bcaa0a-1eff-49c4-82ef-55631d9a91ba.jpg)</p>

<h2 align="center">Ошибки</h2>
<p>Все ошибки выводятся в терминале с пометкой "!!!"</p>
<h2>Запуск программы</h2>
<p>Программа компилируется с помощью команды <i>make</i>. Запускается при вводе в терминал либо <i>./key.out</i> либо <i>make test</i>. Файлы <i>test.txt</i> и <i>answer.txt</i> самому создавать не требуется.</p>
