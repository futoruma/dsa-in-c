#include <stdio.h>
#include <stdlib.h>

void str_to_lower(char *str)
{
  for (size_t i = 0; str[i] != '\0'; ++i) {
    if (str[i] > 64 && str[i] < 91) {
      str[i] += 32;
    }
  }
}

void str_to_upper(char *str)
{
  for (size_t i = 0; str[i] != '\0'; ++i) {
    if (str[i] > 96 && str[i] < 123) {
      str[i] -= 32;
    }
  }
}

int main()
{
  char greeting[] = "Hello World!";

  str_to_lower(greeting);
  printf("Lower case: %s\n", greeting);
  
  str_to_upper(greeting);
  printf("Upper case: %s\n", greeting);
  
  return 0;
}

