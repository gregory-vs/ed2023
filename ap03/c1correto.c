#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  int i;
  int *a = (int*)malloc(10*sizeof(int));
  if (!a) return -1; /*malloc failed*/
  for (i = 0; i < 10; i++){
    a[i] = i;
  }
  free(a);
  return 0;
}
