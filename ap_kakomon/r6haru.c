#include <stdbool.h>
#include <stdio.h>

#define INF 1000000 

int distance(int N, int GOAL, int edge[N][N])
{
  int dist[N] = {};
  for (size_t i = 0; i < N; ++i) {
    dist[i] = INF;
  }
  dist[0] = 0;
  
  int done[N] = {};

  int curNode;
  int minDist;
  int k;

  int viaNode[N] = {};
  int j;

  while (true) {
    minDist = INF;

    for (k = 0; k < N; ++k) {
      if ((done[k] == 0) && (dist[k] < minDist)) {
        minDist = dist[k];
        curNode = k;
      }
    }

    done[curNode] = 1;

    if (curNode == GOAL) {
      j = GOAL;
      printf("%d ", GOAL);

      while (j > 0) {
        printf("%d ", viaNode[j]);
        j = viaNode[j];
      }

      return dist[curNode];
    }

    for (k = 0; k < N; ++k) {
      if ((dist[curNode] + edge[curNode][k]) < dist[k] && done[k] == 0) {
        viaNode[k] = curNode;

        dist[k] = dist[curNode] + edge[curNode][k];
      }
    }
  }

  return -1;
}

int main()
{
  int n = 5;
  int goal = 4;

  int edge[n][n];
  for (size_t row = 0; row < n; ++row) {
    for (size_t col = 0; col < n; ++col) {
      edge[row][col] = INF;
    }
  }

  edge[0][1] = 10;
  edge[1][0] = 10;
  edge[0][2] = 16;
  edge[2][0] = 16;
  edge[1][2] = 4;
  edge[2][1] = 4;
  edge[1][3] = 3;
  edge[3][1] = 3;
  edge[2][3] = 2;
  edge[3][2] = 2;
  edge[2][4] = 3;
  edge[4][2] = 3;
  edge[3][4] = 6;
  edge[4][3] = 6;

  printf("Shortest path from Node %d to Node %d: ", 0, goal);
  int shortest_distance = distance(n, goal, edge);
  printf("\n");

  printf("Shortest distance from Node %d to Node %d is %d", 0, goal, shortest_distance);
  
  return 0;
}

