#ifndef insertion_h
#define insertion_h

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void dfc(int param, int length, int *arr, int *visited);
void adjacency(void);
void other_view(void);
void printvisit(int k, int apex, int *visited, int key);
void delay(int s);
int counter_apex(FILE *fp1);
int find_max(FILE *fp1);

#endif //insetion_h