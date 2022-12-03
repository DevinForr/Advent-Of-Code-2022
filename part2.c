#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  FILE *fp;
  fp = fopen("input.txt", "r");
  ssize_t read;
  size_t length = 100;
  char *first = calloc(100, 1);
  char *second = calloc(100, 1);
  char *third = calloc(100, 1);
  int priority = 0;
  int debugVal = 1;
  int debug = 0;
  while ((read = getline(&first, &length, fp)) != -1) {
    getline(&second, &length, fp);
    getline(&third, &length, fp);
    for(int i =0; i < strlen(first); i++) {
      if(strchr(second, first[i]) != NULL && strchr(third,first[i]) != NULL) {
        if (isupper(first[i])) {
          priority += (first[i]-38);
        } else {
          priority += (first[i]-96);
        }
        break;
      }
    }
  }
  printf("Total Priority = %d\n", priority);
  free(first);
  free(second);
  free(third);
  return 0;
} 