#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  FILE *fp;
  fp = fopen("input.txt", "r");
  ssize_t read;
  size_t length = 100;
  char *line = calloc(100, 1);
  
  int priority = 0;
  int debugVal = 1;
  int debug = 0;
  while ((read = getline(&line, &length, fp)) != -1) {
    char *first = calloc(50, 1);
  char *second = calloc(50, 1);
    memcpy(first, line, strlen(line)/2);
    memcpy(second, line+(strlen(line)/2), strlen(line)/2);
    printf("%s, %s, %s\n", line, first, second);
    for(int i =0; i < strlen(first); i++) {
      if(strchr(second, first[i]) != NULL) {
        if (isupper(first[i])) {
          priority += (first[i]-38);
        } else {
          priority += (first[i]-96);
        }
        break;
      }
    }
    free(first);
  free(second);
  }
  printf("Total Priority = %d\n", priority);
  free(line);

  return 0;
} 