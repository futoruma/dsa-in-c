#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int * prime1(int N)
{
  int *primes = (int *) malloc(N * sizeof(int));
  for (size_t i = 0; i < N; ++i) {
    primes[i] = 0;
  }

  int primes_i = 0;

  bool isPrime;

  int d = 2;
  int t;

  while (d <= N) {
    isPrime = true;
    t = 2;

    while (t < d) {
      if ((d % t) == 0) {
        isPrime = false;
      }

      t++;
    }

    if (isPrime) {
      primes[primes_i] = d;
      primes_i++;
    }

    d++;
  }

  return primes;
}

int * prime2(int N)
{
  int *primes = (int *) malloc(N * sizeof(int));
  for (size_t i = 0; i < N; ++i) {
    primes[i] = 0;
  }

  int primes_i = 0;

  bool *isPrime = (bool *) malloc(N * sizeof(bool));
  isPrime[0] = false;

  int c = 2;
  int d = 2;
  int t;

  while (c <= N) {
    isPrime[c-1] = true;
    c++;
  }

  while (d <= N) {
    if (isPrime[d]) {
      primes[primes_i] = d;
      primes_i++;

      t = d * d;

      while (t <= N) {
        isPrime[t] = false;
        t += d;
      }
    }

    d++;
  }

  return primes;
}

int * prime3(int N)
{
  int *primes = (int *) malloc(N * sizeof(int));
  for (size_t i = 0; i < N; ++i) {
    primes[i] = 0;
  }

  primes[0] = 2;
  int primes_i = 1;

  bool *isPrime = (bool *) malloc(N * sizeof(bool));
  isPrime[0] = false;
 
  int c = 3;
  int d = 3;
  int t;

  while (c <= N) {
    isPrime[(c - 1) / 2] = true;
    c += 2;
  }

  while (d <= N) {
    if (isPrime[(d - 1) / 2]) {
      primes[primes_i] = d;
      primes_i++;

      t = d * d;

      while (t <= N) {
        isPrime[(t - 1) / 2] = false;
        t += 2 * d; 
      }
    }

    d += 2;
  }

  return primes;
}

int main()
{
  int N1 = 20;
  int *primes1 = prime1(N1);

  printf("Prime numbers up to %d:\n", N1);
  for (size_t i = 0; (i < N1) && (primes1[i] != 0); ++i) {
    printf("%d ", primes1[i]);
  }
  printf("\n");

  int N2 = 20;
  int *primes2 = prime2(N2);

  printf("Prime numbers up to %d:\n", N2);
  for (size_t i = 0; (i < N2) && (primes2[i] != 0); ++i) {
    printf("%d ", primes2[i]);
  }
  printf("\n");

  int N3 = 20;
  int *primes3 = prime3(N3);

  printf("Prime numbers up to %d:\n", N3);
  for (size_t i = 0; (i < N3) && (primes3[i] != 0); ++i) {
    printf("%d ", primes3[i]);
  }
  printf("\n");

  return 0;
}

