#include <stdio.h>

void str_validate(char *str)
{
  for (size_t i = 0; str[i] != '\0'; ++i) {
    if ((str[i] < 65) || (str[i] > 90 && str[i] < 97) || (str[i] > 122)) {
      printf("\"%s\" is invalid.\n", str);
      return;
    }
  }

  printf("\"%s\" is valid.\n", str);
}

int main()
{
  char str1[] = "Username";
  str_validate(str1);
  
  char str2[] = "User name";
  str_validate(str2);
  
  return 0;
}

