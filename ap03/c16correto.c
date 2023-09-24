#include <stdio.h>
#include <stdlib.h>

int actual_calc(int a, int b){
  int c;
  c=a/b;
  return 0;
}

int calc(){
  int a;
  int b;
  a=13;
  b=0;

  if(b == 0)
  {
      printf("a variável b deve ser diferente de 0 \n");
      b=1;
  }
  actual_calc(a, b);
  return 0;
}

int main(){
  calc();
  return 0;
}
