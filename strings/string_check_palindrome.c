#include <stdio.h>

void str_check_palindrome(char *str)
{
  size_t j = 0;
  while (str[j] != '\0') {
    j++;
  }
  j--;

  for (size_t i = 0; i < j; i++, j--) {
    if (str[i] != str[j]) {
      printf("%s is not a palindrome.\n", str);
      return;
    }
  }

  printf("%s is a palindrome.\n", str);
}

int main()
{
  char str1[] = "racecar";
  str_check_palindrome(str1);
  
  char str2[] = "racer";
  str_check_palindrome(str2);
  
  return 0;
}

