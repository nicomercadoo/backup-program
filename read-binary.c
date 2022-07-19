#include <stdio.h>
#include "types.h"

int main(){
  FILE *f = fopen(PATHS_FILE, "rb");
  char s[PATH_MAX];

  while (fread(s, sizeof(s), 1, f) != 0){
    printf("%s\n",s);

  }

  fseek(f, 0, SEEK_SET);
  int n = 0;
  while (fread(s, sizeof(s), 1, f) != 0){
    n++;
  }
  printf("n: %d\n", n);

  fseek(f, 0, SEEK_END);
  n = ftell(f)/sizeof(s);
  printf("n: %d\n", n);

}