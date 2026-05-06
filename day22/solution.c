#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 105

typedef struct {
    int r, c;
} Point;

char grid[MAX][MAX];
int dist[MAX][MAX];
Point queue[MAX * MAX];
int head = 0, tail = 0;

void enqueue(int r, int c) {
    queue[tail].r = r;
    queue[tail].c = c;
    tail++;
}

Point dequeue() {
    return queue[head++];
}

int is_empty() {
    return head == tail;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }

    int startR, startC, goalR, goalC;
    if (scanf("%d %d %d %d", &startR, &startC, &goalR, &goalC) != 4) return 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = -1;
        }
    }

    dist[startR][startC] = 0;
    enqueue(startR, startC);

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!is_empty()) {
        Point curr = dequeue();

        if (curr.r == goalR && curr.c == goalC) {
            printf("%d\n", dist[curr.r][curr.c]);
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];

            while (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == '.') {
                if (dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[curr.r][curr.c] + 1;
                    enqueue(nr, nc);
                }
                nr += dr[i];
                nc += dc[i];
            }
        }
    }

   
    if (dist[goalR][goalC] == -1) {
    }

    return 0;
}
