#include <stdio.h>
#include <stdlib.h>

int str_count_words(char *str)
{
  int words_count = 0;

  size_t i = 1;
  while (str[i] != '\0') {
    if (str[i] != ' ' && str[i] != '.' && str[i] != ',') {
      i++;
      continue;
    }

    if ((str[i-1] > 64 && str[i-1] < 91) || (str[i-1] > 96 && str[i-1] < 123)) {
      words_count++;
    }
    i++;
  }

  if ((str[i-1] > 64 && str[i-1] < 91) || (str[i-1] > 96 && str[i-1] < 123)) {
    words_count++;
  }

  return words_count;
}

int main()
{
  char str1[] = "Some string  with  some  words";
  printf("%s\nWords: %d.\n", str1, str_count_words(str1));
  
  char str2[] = "Some string  with  some  words.";
  printf("%s\nWords: %d.\n", str2, str_count_words(str2));
  
  char str3[] = "Some string  with  some  words     .";
  printf("%s\nWords: %d.\n", str3, str_count_words(str3));
  
  return 0;
}

