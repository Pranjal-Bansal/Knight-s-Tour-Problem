#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8
#define INF 1000000

struct Cell {
    int x, y;
};


bool isInside(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

int min(int a, int b) {
    return (a < b) ? a : b;
}
int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int shortestPath(struct Cell start, struct Cell end) {
    int xMove[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int yMove[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dist[N][N];
    int i, j;


    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            dist[i][j] = INF;
        }
    }


    dist[start.x][start.y] = 0;


    struct Cell queue[N * N];
    int front = 0, rear = 0;
    queue[rear++] = start;


    while (front != rear) {
        struct Cell curr = queue[front++];
        for (i = 0; i < 8; i++) {
            int x = curr.x + xMove[i];
            int y = curr.y + yMove[i];
            if (isInside(x, y) && dist[x][y] == INF) {
                dist[x][y] = dist[curr.x][curr.y] + 1;
                queue[rear++] = (struct Cell) {x, y};
            }
        }
    }


    return dist[end.x][end.y];
}
void printSolution(int sol[N][N]) {
    printf("\nSolution:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", sol[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

bool solveKTUtil(int x, int y, int movei, int sol[N][N], int* count) {
    if (movei == N * N) {
        (*count)++;
        printSolution(sol);
        return true;
    }

    for (int k = 0; k < 8; k++) {
        int next_x = x + xMove[k];
        int next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            solveKTUtil(next_x, next_y, movei + 1, sol, count);
            sol[next_x][next_y] = -1;
        }
    }
    return false;
}

void solveKT() {
    int sol[N][N];
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sol[i][j] = -1;
        }
    }
    sol[0][0] = 0;
    solveKTUtil(0, 0, 1, sol, &count);
    printf("\nTotal number of solutions: %d", count);
}


int main() {
    int r;
    printf("Enter 1 for shortest path and enter 2 for all possible ways  ");
    scanf("%d",&r);
    if(r==1)
    {
    int s1,s2,f1,f2;
    printf("Enter the starting coordinates");
    scanf("%d",&s1);
    scanf("%d",&s2);
    printf("Enter the ending coordinates");
    scanf("%d",&f1);
    scanf("%d",&f2);
    struct Cell start = {s1, s2};
    struct Cell end = {f1, f2};
    printf("The shortest path from (%d, %d) to (%d, %d) is %d\n", start.x, start.y, end.x, end.y, shortestPath(start, end));
    }
    else{
    solveKT();
    }
    return 0;
}

