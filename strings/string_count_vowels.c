#include <stdio.h>
#include <stdlib.h>

int str_count_vowels(char *str)
{
  int count_arr[26] = {};

  int j;
  for (size_t i = 0; str[i] != '\0'; ++i) {
    if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122) {
      continue;
    }

    j = -65;
    if (str[i] > 96) {
      j -= 32;
    }

    j += str[i];
    count_arr[j]++;
  }

  return count_arr[0] + count_arr[4] + count_arr[8] + count_arr[14] + count_arr[20]; 
}

int main()
{
  char str[] = "Let's count vowels!";
  int vowels = str_count_vowels(str);

  printf("%s has %d vowels.\n", str, vowels);
  
  return 0;
}

