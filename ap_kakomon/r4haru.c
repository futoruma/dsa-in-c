#include <stdbool.h>
#include <stdio.h>

#define COLS 9
#define ROWS 9
#define MAX_BOARD 81

size_t board[MAX_BOARD] = {
  2,0,1,0,9,0,7,0,0,
  0,4,0,2,0,0,3,0,0,
  5,0,0,0,0,8,0,2,9,
  0,9,0,6,7,0,2,0,0,
  6,0,0,3,0,5,0,0,4,
  0,0,7,0,4,9,0,1,0,
  7,6,0,9,0,0,0,0,3,
  0,0,9,0,0,6,0,4,0,
  0,0,4,0,1,0,6,0,0
};

void print_board()
{
  for (size_t r = 0; r < ROWS; ++r) {
    for (size_t c = 0; c < COLS; ++c) {
      printf("%zu ", board[(r * COLS) + c]);
    }

    printf("\n");
  }
}

bool row_ok(size_t n, size_t x)
{
  size_t row_top = (x / COLS) * COLS;

  for (size_t c = 0; c < COLS; ++c) {
    if (board[row_top + c] == n) {
      return false;
    }
  }

  return true;
}

bool column_ok(size_t n, size_t x)
{
  size_t column_top = x % COLS;

  for (size_t r = 0; r < ROWS; ++r) {
    if (board[column_top + (r * COLS)] == n) {
      return false;
    }
  }

  return true;
}

bool frame_ok(size_t n, size_t x)
{
  size_t frame_top = x - (((x / COLS) * COLS) % (3 * COLS)) - (x % 3);

  for (size_t r = 0; r < 3; ++r) {
    for (size_t c = 0; c < 3; ++c) {
      if (board[frame_top + (r * COLS) + c] == n) {
        return false;
      }
    }
  }

  return true;
}

bool check_ok(size_t n, size_t x)
{
  return (row_ok(n, x) && column_ok(n, x) && frame_ok(n, x));
}

void solve(size_t x)
{
  if (x > (MAX_BOARD - 1)) {
    print_board();
    return;
  }

  if (board[x] != 0) {
    solve(x + 1);
    return;
  }
  
  for (size_t n = 1; n <= 9; ++n) {
    if (check_ok(n, x)) {
      board[x] = n;
      solve(x + 1);
      board[x] = 0;
    }
  }
}

int main()
{
  solve(0);

  return 0;
}

