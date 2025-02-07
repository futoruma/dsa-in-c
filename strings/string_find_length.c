#include <stdio.h>
#include <stdlib.h>

int main()
{
  char greeting[] = "Hello world!";

  size_t i = 0;
  while (greeting[i] != '\0') {
    i++;
  }

  printf("Length is %zu.\n", i);
  
  return 0;
}

