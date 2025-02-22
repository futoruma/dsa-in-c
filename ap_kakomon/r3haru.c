#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 7
#define K 2
#define MaxCount 100

size_t cluster[N + 1] = {};
size_t core[K + 1] = {};
size_t points[N + 1][2] = {
  {0, 0},
  {1, 0},
  {2, 1},
  {4, 1},
  {1, 2},
  {1, 3},
  {2, 3},
  {4, 3}
};

void initial()
{
  size_t used[N + 1] = {};

  size_t i = 1;
  while (i <= K) {
    size_t random_num = (size_t) ((rand() % (N + 1)) + 1);

    if (used[random_num] != 0) {
      continue;
    }

    used[random_num] = 1;
    core[i] = random_num;

    ++i;
  }
}

size_t data_dist(size_t s, size_t t)
{
  int x_diff = (int) points[s][0] - (int) points[t][0];
  int y_diff = (int) points[s][1] - (int) points[t][1];

  return (size_t) (x_diff * x_diff + y_diff * y_diff);
}

size_t min_index_data(size_t *arr)
{
  size_t min_val = arr[1];
  size_t min_i = 1;

  for (size_t i = 2; i <= K; ++i) {
    if (arr[i] < min_val) {
      min_val = arr[i];
      min_i = i;
    }
  }

  return min_i;
}

float gravity_x(size_t t)
{
  size_t x_sum = 0;
  size_t cluster_size = 0;

  for (size_t i = 1; i <= N; ++i) {
    if (cluster[i] == t) {
      x_sum += points[i][0];
      ++cluster_size;
    }
  }

  return (float) x_sum / (float) cluster_size;
}

float gravity_y(size_t t)
{
  size_t y_sum = 0;
  size_t cluster_size = 0;

  for (size_t i = 1; i <= N; ++i) {
    if (cluster[i] == t) {
      y_sum += points[i][1];
      ++cluster_size;
    }
  }

  return (float) y_sum / (float) cluster_size;
}

float grav_dist(size_t s, size_t t)
{
  float x_diff = (float) points[s][0] - gravity_x(t);
  float y_diff = (float) points[s][1] - gravity_y(t);

  return (x_diff * x_diff + y_diff * y_diff);
}

size_t min_index_grav(float *arr)
{
  float min_val = arr[1];
  size_t min_i = 1;

  for (size_t i = 2; i <= K; ++i) {
    if (arr[i] < min_val) {
      min_val = arr[i];
      min_i = i;
    }
  }

  return min_i;
}

int main()
{
  srand(time(NULL));

  initial();

  size_t data_length[K + 1] = {};
  float grav_length[K + 1] = {};

  float coordinate_x[K + 1] = {};
  float coordinate_y[K + 1] = {};
  
  size_t flag = 0;

  for (size_t s = 1; s <= N; ++s) {
    for (size_t t = 1; t <= K; ++t) {
      data_length[t] = data_dist(s, core[t]);
    }

    cluster[s] = min_index_data(data_length);
  }

  for (size_t p = 1; p <= MaxCount; ++p) {
    if (p == 1) {
      for (size_t t = 1; t <= K; ++t) {
        coordinate_x[t] = gravity_x(t);
        coordinate_y[t] = gravity_y(t);
      }
    }
    else {
      flag = 0;

      for (size_t t = 1; t <= K; ++t) {
        if ((gravity_x(t) != coordinate_x[t]) || (gravity_y(t) != coordinate_y[t])) {
          coordinate_x[t] = gravity_x(t);
          coordinate_y[t] = gravity_y(t);

          flag = 1;
        }
      }

      if (flag == 0) {
        break;
      }
    }

    for (size_t s = 1; s <= N; ++s) {
      for (size_t t = 1; t <= K; ++t) {
        grav_length[t] = grav_dist(s, t);
      }

      cluster[s] = min_index_grav(grav_length);
    }
  }

  for (size_t i = 1; i <= N; ++i) {
    printf("%zu ", cluster[i]);
  }

  return 0;
}

