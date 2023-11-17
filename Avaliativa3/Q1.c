#include <stdio.h>
#include <string.h>

int RomanoBase10(char *roma){
  int valores[7] = {1000, 500, 100, 50, 10, 5, 1};
  char simbolos[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
  int base10 = 0;

  int tamanho = strlen(roma);

  for (int i = 0; i < tamanho; i++){
    int numatras = 0;
    int numfrente = 0;

    for (int j = 0; j < 7; j++){
      if (roma[i] == simbolos[j]){
        numatras= valores[j];
      }
      if (i + 1 < tamanho && roma[i + 1] == simbolos[j]){
        numfrente = valores[j];
      }
    }

    if (numatras < numfrente){
      base10 += (numfrente - numatras);
      i++;
    } 
    else{
      base10 += numatras;
    }
  }

  return base10;
}

void Base10Binario(int base10, char *roma){
    int binario[64];
    int i = 0;

    while (base10 > 0){
        binario[i] = base10 % 2;
        base10 = base10 / 2;
        i++;
    }

    printf("%s na base 2: ", roma);
    for (int j = i - 1; j >= 0; j--){
        printf("%d", binario[j]);
    }
    printf("\n");
}

void Base10Hexa(int base10, char *roma){
  char hexa[32];
  int i = 0;

  while (base10 > 0){
    int num = base10 % 16;
      if (num < 10){
        hexa[i] = num + '0';
      } 
      else{
        hexa[i] = num - 10 + 'a';
      }
      base10 = base10 / 16;
      i++;
    }

  printf("%s na base 16: ", roma);
  for (int j = i - 1; j >= 0; j--){
    printf("%c", hexa[j]);
  }
  printf("\n");
}

int main(){
    char romano[20];

    scanf("%s", romano);

    int base10 = RomanoBase10(romano);
    
    Base10Binario(base10, romano);
    printf("%s na base 10: %d\n", romano, base10);
    Base10Hexa(base10, romano);

    return 0;
}
