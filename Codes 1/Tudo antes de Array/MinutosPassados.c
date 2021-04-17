#include <stdio.h>
#include <math.h>

int main() {
  
  int Horas;
  int Minutos;
  int Ans;

    scanf("%i", &Horas);
    scanf("%i", &Minutos);
  Ans = (Horas*60) + Minutos;

printf("%i Minutos.\n", Ans);
  return 0;
}