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
