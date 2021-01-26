#include <stdio.h>

int main() {
  FILE* fp;
  FILE* fp2;
  FILE* fp3;
  FILE* fp4;

  fp = fopen("test/test.txt", "w");
  fp2 = fopen("test/test2.txt", "w");
  fp3 = fopen("../test3.txt", "w");
  fp4 = fopen("test/test4.txt", "w");
  fprintf(fp, "This is a first file\n");
  fprintf(fp2, "This is a second file\n");
  fprintf(fp3, "This is a third file\n");
  fclose(fp);
  fclose(fp2);
  fclose(fp3);
  fclose(fp4);

  return 0;
}
