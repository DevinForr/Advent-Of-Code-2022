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
  int overlaps = 0;
  int first1= 0, last1 =0, first2= 0, last2 = 0;
  while ((read = getline(&line, &length, fp)) != -1) {
    sscanf(line, "%d-%d,%d-%d", &first1, &last1, &first2, &last2);
    if ((first1 <= first2 && first2 <= last1) || (first2 <= first1 && first1 <= last2)) {
      overlaps++;
    }
  }
  printf("Total Overlaps = %d\n", overlaps);
  free(line);
   
  return 0;
} 
