#include <stdio.h>

int main() {
  FILE* fp;

  fp = fopen("test/test.txt", "w");
  fprintf(fp, "blablabla\n");
  fclose(fp);

  return 0;
}
