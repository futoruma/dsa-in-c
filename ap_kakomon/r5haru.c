#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define T_DEPTH 3
#define NUM_LEN 4
#define FIRST_NUM 1234
#define SECOND_NUM 5678

typedef struct {
  int N;
  int *values;
} Mpint;

typedef struct {
  int N;
  Mpint *val1;
  Mpint *val2;
  Mpint *result;
} Node;

Mpint * new_mpint(int n, int x)
{
  Mpint *mpint = (Mpint *) malloc(sizeof(Mpint));

  mpint->N = n;
  mpint->values = (int *) malloc((n + 1) * sizeof(int));

  for (size_t i = 1; i < (n + 1); ++i) {
    mpint->values[i] = x % 10;
    x = x / 10;
  }

  return mpint;
}

Mpint * add(Mpint *p, Mpint *q)
{
  Mpint *res_mpint = (Mpint *) malloc(sizeof(Mpint));

  Mpint *big_p;
  Mpint *small_p;

  if (p->N > q->N) {
    big_p = p;
    small_p = q;
  }
  else {
    big_p = q;
    small_p = p;
  }

  res_mpint->N = big_p->N;
  res_mpint->values = (int *) malloc((res_mpint->N + 1) * sizeof(int));

  for (size_t i = 1; i < (res_mpint->N + 1); ++i) {
    res_mpint->values[i] = big_p->values[i];
  }

  for (size_t i = 1; i < (small_p->N + 1); ++i) {
    res_mpint->values[i] += small_p->values[i];
  }

  return res_mpint;
}

Mpint * carry(Mpint *p)
{
  Mpint *res_mpint = (Mpint *) malloc(sizeof(Mpint));

  res_mpint->N = p->N;
  res_mpint->values = (int *) malloc((res_mpint->N + 1) * sizeof(int));

  for (size_t i = 1; i < (res_mpint->N + 1); ++i) {
    res_mpint->values[i] = p->values[i];
  }

  for (size_t i = 1; i < (res_mpint->N + 1); ++i) {
    if (res_mpint->values[i] < 0) {
      res_mpint->values[i] += 10;
      res_mpint->values[i + 1] -= 1;
    }
    else if (res_mpint->values[i] > 9) {
      res_mpint->values[i] -= 10;
      res_mpint->values[i + 1] += 1;
    }
  }

  return res_mpint;
}

Mpint * left(Mpint *p, int k)
{
  Mpint * left_mpint = (Mpint *) malloc(sizeof(Mpint));

  left_mpint->N = k;
  left_mpint->values = (int *) malloc((k + 1) * sizeof(int));

  for (size_t i = 0; i < k; ++i) {
    left_mpint->values[k - i] = p->values[p->N - i];
  }

  return left_mpint;
}

Mpint * right(Mpint *p, int k)
{
  Mpint * right_mpint = (Mpint *) malloc(sizeof(Mpint));

  right_mpint->N = k;
  right_mpint->values = (int *) malloc((k + 1) * sizeof(int));

  for (size_t i = 0; i < k; ++i) {
    right_mpint->values[k - i] = p->values[p->N - k - i];
  }

  return right_mpint;
}

Mpint * lradd(Mpint *p, int k)
{
  return add(left(p, k), right(p, k));
}

Mpint * shift(Mpint *p, int k)
{
  Mpint * res_mpint = (Mpint *) malloc(sizeof(Mpint));

  res_mpint->N = p->N + k;
  res_mpint->values = (int *) malloc((res_mpint->N + 1) * sizeof(int));

  for (size_t i = 1; i < (res_mpint->N + 1); ++i) {
    res_mpint->values[i] = 0;
  }

  for (size_t i = 0; i < p->N; ++i) {
    res_mpint->values[res_mpint->N - i] = p->values[p->N - i];
  }

  return res_mpint;
}

Mpint * sub(Mpint *p, Mpint *q)
{
  Mpint * res_mpint = (Mpint *) malloc(sizeof(Mpint));

  res_mpint->N = p->N;
  res_mpint->values = (int *) malloc((res_mpint->N + 1) * sizeof(int));

  for (size_t i = 1; i < (res_mpint->N + 1); ++i) {
    res_mpint->values[i] = p->values[i];
  }

  for (size_t i = 1; i < (q->N + 1); ++i) {
    res_mpint->values[i] -= q->values[i];
  }

  return res_mpint;
}

int mpint_to_int(Mpint *p)
{
  int res = 0;
  int multiplier = 1;

  for (size_t i = 1; i < (p->N + 1); ++i) {
    res += p->values[i] * multiplier;
    multiplier *= 10;
  }

  return res;
}

Node * new_elem(int k, Mpint *v1, Mpint *v2)
{
  Node * new_node = (Node *) malloc(sizeof(Node));

  new_node->N = k;

  new_node->val1 = v1;
  new_node->val2 = v2;

  new_node->result = new_mpint(2 * k, 0);

  return new_node;
}

int main()
{
  size_t layer_top[4] = {};
  layer_top[1] = 1;

  for (size_t i = 1; i < T_DEPTH; ++i) {
    layer_top[i + 1] = (size_t) (layer_top[i] + pow(3, i - 1)); 
  }

  Mpint *first_num = new_mpint(NUM_LEN, FIRST_NUM);
  Mpint *second_num = new_mpint(NUM_LEN, SECOND_NUM);

  int elements_max_num = 2 * pow(3, T_DEPTH - 1);
  Node *elements[elements_max_num] = {};

  elements[1] = new_elem(first_num->N, first_num, second_num);

  for (size_t dp = 1; dp < T_DEPTH; ++dp) {
    for (size_t i = 1; i < (pow(3, dp - 1) + 1); ++i) {
      Node *pe = elements[layer_top[dp] + (i - 1)];
      
      int cn = (pe->N) / 2;
      size_t tidx = layer_top[dp + 1] + (3 * (i - 1));

      elements[tidx] = new_elem(cn, left(pe->val1, cn), left(pe->val2, cn));
      elements[tidx + 1] = new_elem(cn, right(pe->val1, cn), right(pe->val2, cn));
      elements[tidx + 2] = new_elem(cn, lradd(pe->val1, cn), lradd(pe->val2, cn));
    }
  }

  for (size_t i = 1; i < (pow(3, T_DEPTH - 1) + 1); ++i) {
    Node *el = elements[layer_top[T_DEPTH] + (i - 1)];
    int mul = el->val1->values[1] * el->val2->values[1];
    el->result->N = 2;
    el->result->values[1] = mul % 10;
    el->result->values[2] = mul / 10;
  }

  for (size_t dp = (T_DEPTH - 1); dp > 0; --dp) {
    for (size_t i = 1; i < (pow(3, dp - 1) + 1); ++i) {
      Node *el = elements[layer_top[dp] + (i - 1)];
      
      size_t cidx = layer_top[dp + 1] + 3 * (i - 1);

      Mpint *s1 = sub(elements[cidx + 2]->result, elements[cidx]->result);
      Mpint *s2 = sub(s1, elements[cidx + 1]->result);

      Mpint *p1 = shift(elements[cidx]->result, el->N);
      Mpint *p2 = shift(s2, el->N / 2);
      Mpint *p3 = elements[cidx + 1]->result;

      el->result = add(add(p1, p2), p3);
    }
  }

  Mpint *answer = carry(elements[1]->result);

  printf("%d * %d = %d\n", FIRST_NUM, SECOND_NUM, mpint_to_int(answer));

  return 0;
}

