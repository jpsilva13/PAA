#include <stdio.h>
#include <stdlib.h>
void permutacao(int n, int x[], int used[], int k, int m[n][n]){
  int i;
  int teste=1;
  if (k == n){

    for (i = 0; i < n; i++){
      printf("%d ", x[i] + 1);
    }
    for (i = 0; i < n; i++){

      if (i!=n-1){
        //printf("%d ¨¨ %d\n",x[i],x[i+1] );
        if ((teste == 1) && (m[x[i]][x[i+1]] == 1)){
          teste=1;
        } else{
          //printf("entrei %d\n");
          teste=0;
        }
      }

    }
    if ((teste==1)&&(x[0]==7)){
      printf(" Por este caminho é possível que todas as cidades sejam percorridas a partir da cidade 8!");
    }
    printf("\n");

  }
  else{
    for (i = 0; i < n; i++){
      if (!used[i]){
        used[i] = 1;
        x[k] = i;
        permutacao(n, x, used, k + 1,m );
        used[i] = 0;
      }
    }
  }
}
int main(){
  int i, n, x[100], used[100];
  printf("Entre com o valor de n: ");
  scanf("%d", &n);
  /* se um elemento i estiver em uso, entao used[i] = 1,
  caso contrario, used[i] = 0. */
  int m[n][n];
  char nome[n*n];
  FILE *arq;
  int j;
  arq=fopen("matriz2.txt", "r");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      fscanf(arq,"%d ", &m[i][j]);
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
  printf("finished matrix\n" );
  fclose(arq);
  for (i = 0; i < n; i++)
  used[i] = 0;
  permutacao(n, x, used, 0, m);
  return 0;
}
