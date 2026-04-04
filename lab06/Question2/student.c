#include "graph.h"

int count_isolated(Graph* g) {
    int count = 0;

    for (int i = 0; i < MAX_NODES; i++) {
        int isIsolated = 1; //assume isolated

        for (int j = 0; j < MAX_NODES; j++){
            if (g->adj[i][j] == 1){
                isIsolated = 0;
                break;
            }
        }

        if (isIsolated) {
            count++;
        }
    }
    return count;
}

