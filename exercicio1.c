#include <stdio.h>
#include <stdlib.h>

void combinacao_simples(int n, int r, int x[], int next, int k,int m[n][n]){
  int i;
  if (k == r){
    for (i = 0; i < r; i++)
    printf("%d ", x[i] + 1);
    printf("%d -- %d -- %d -- %d -- %d -- %d -- %d -- %d -- %d -- %d\n",m[x[0]][x[1]],m[x[0]][x[2]],m[x[0]][x[3]],m[x[0]][x[4]],m[x[1]][x[2]],m[x[1]][x[3]],m[x[1]][x[4]], m[x[2]][x[3]],m[x[2]][x[4]],m[x[3]][x[4]] );
    if(((m[x[0]][x[1]]) == 1) && ((m[x[0]][x[2]]) == 1) && ((m[x[0]][x[3]]) == 1) && ((m[x[0]][x[4]]) == 1) && ((m[x[1]][x[2]]) == 1) && ((m[x[1]][x[3]]) == 1) && ((m[x[1]][x[4]]) == 1) && ((m[x[2]][x[3]]) == 1) && ((m[x[2]][x[4]]) == 1) && ((m[x[3]][x[4]]) == 1)) {
      printf("A série %d, %d, %d, %d e %d eh valida!\n",x[0]+1,x[1]+1,x[2]+1,x[3]+1,x[4]+1);
    }
  }
  else{
    for (i = next; i < n; i++){
      x[k] = i;
      combinacao_simples(n, r, x, i + 1, k + 1, m);
    }
  }
}
int main(){

  int n, r, x[1000];
  printf("Entre com o valor de n: ");
  scanf("%d", &n);
  printf("Entre com o valor de r: ");
  scanf("%d", &r);
  int m[n][n];
  char nome[n*n];
  FILE *arq;
  int i,j;
  arq=fopen("matriz.txt", "r");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      fscanf(arq,"%d ", &m[i][j]);
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
  printf("finished matrix\n" );
  fclose(arq);
  combinacao_simples(n, r, x, 0, 0, m);



  return 0;
}
