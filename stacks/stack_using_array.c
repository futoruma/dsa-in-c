#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int size;
  int top;
  int * S;
} Stack;

void create(Stack * st)
{
  printf("Enter the stack size");
  scanf("%d", & st -> size);
  st -> top = -1;
  st -> S = (int * ) malloc(st -> size * sizeof(int));
}

void display(Stack st)
{
  int i;
  for (i = st.top; i >= 0; --i)
    printf("%d ", st.S[i]);
  printf("\n");
}

void push(Stack * st, int x)
{
  if (st -> top == st -> size - 1)
    printf("Stack overflow\n");
  else {
    st -> top++;
    st -> S[st -> top] = x;
  }
}

int pop(Stack * st)
{
  int x = -1;

  if (st -> top == -1)
    printf("Stack Underflow\n");
  else {
    x = st -> S[st -> top--];
  }

  return x;
}

int peek(Stack st, int index)
{
  int x = -1;
  
  if (st.top - index + 1 < 0)
    printf("Invalid Index \n");
  x = st.S[st.top - index + 1];

  return x;
}

int is_empty(Stack st)
{
  if (st.top == -1)
    return 1;

  return 0;
}

int is_full(Stack st)
{
  return st.top == st.size - 1;
}

int stack_top(Stack st)
{
  if (!is_empty(st))
    return st.S[st.top];

  return -1;
}

int main(int argc, char **argv)
{
  Stack st;
  create(&st);

  push(&st, 410);
  push(&st, 230);
  push(&st, 32);
  push(&st, 49);

  printf("%d \n", peek(st, 2));

  display(st);

  return 0;
}
