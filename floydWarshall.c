#include <stdio.h>
#define INF 99999
#define v 4

void printmatrix(int dist[v][v]) {
    printf("The shortest distance between every pair of vertices:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[v][v]) {
    int dist[v][v];

    // Initialize the solution matrix same as input graph matrix
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printmatrix(dist);
}

int main() {
    int graph[v][v];
    printf("Enter the adjacency matrix (0 for no edge, except self-loops):\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    floydWarshall(graph);
    return 0;
}

// Enter the adjacency matrix (0 for no edge, except self-loops):
// 0 3 9999 5
// 2 0 9999 4
// 9999 1 0 9999
// 9999 9999 2 0
// The shortest distance between every pair of vertices:
//   0   3   7   5 
//   2   0   6   4 
//   3   1   0   5 
//   5   3   2   0 
