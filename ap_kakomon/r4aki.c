#include <stdio.h>

#define OK 0
#define VISITED 1
#define NG 2

size_t maze[7][7] = {
  {NG, NG, NG, NG, NG, NG, NG},
  {NG, OK, OK, OK, OK, OK, NG},
  {NG, OK, NG, OK, NG, OK, NG},
  {NG, OK, OK, OK, OK, NG, NG},
  {NG, NG, OK, NG, OK, NG, NG},
  {NG, OK, OK, OK, OK, OK, NG},
  {NG, NG, NG, NG, NG, NG, NG}
};

size_t stack_visit[32] = {};
size_t stack_top = 0;

size_t start_x = 1;
size_t start_y = 1;

size_t goal_x = 5;
size_t goal_y = 5;

size_t sol_num = 0;
size_t paths[32][32] = {};

void visit(size_t x, size_t y)
{
  maze[x][y] = VISITED;
  stack_visit[stack_top] = x + (7 * y);

  if ((x == goal_x) && (y == goal_y)) {
    for (size_t k = 0; k <= stack_top; ++k) {
      paths[sol_num][k] = stack_visit[k];
    }

    sol_num++;
  }
  else {
    stack_top++;

    if (maze[x][y + 1] == OK) {
      visit(x, y + 1);
    }
    if (maze[x + 1][y] == OK) {
      visit(x + 1, y);
    }
    if (maze[x][y - 1] == OK) {
      visit(x, y - 1);
    }
    if (maze[x - 1][y] == OK) {
      visit(x - 1, y);
    }

    stack_top--;
  }

  maze[x][y] = OK;
}

int main()
{
  visit(start_x, start_y);

  if (sol_num == 0) {
    printf("迷路の解は見つからなかった\n");
  }
  else {
    for (size_t sol = 0; sol < 32; ++sol) {
      if (paths[sol][0] == 0) {
        continue;
      }
      printf("Path %zu: ", sol);

      for (size_t step = 0; step < 32; ++step) {
        if (paths[sol][step] == 0) {
          break;
        }
        printf("-> (%zu, %zu) ", paths[sol][step] % 7, paths[sol][step] / 7);
      }

      printf("\n");
    }
  }

  return 0;
}

