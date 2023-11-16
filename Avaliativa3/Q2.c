#include <stdio.h>
#include <math.h>

int main(){

  int T;
  double J, A;

  scanf("%d", &T);
  scanf("%lf", &A);
  scanf("%lf", &J);
  
  double Total = 0;
  
  for (int i = 1; i <= T; ++i){
    Total = Total + A * pow(1 + J, i);
    printf("Montante ao fim do mes %d: R$ %.2f\n", i, Total);
  }
  
  return 0;
}