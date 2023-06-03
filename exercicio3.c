#include <stdio.h>
void printMaxActivities(int s[], int f[], int n,int i,int jafeitas[]){
  int j, e, menor,testae;
  testae=0;
  menor=99;

  for (j = 1; j < n; j++){

    if ((s[j] >= f[i]) && (s[j] < menor) && (jafeitas[j]!=1)) {
      menor=s[j];
      e = j;
      testae=1;

    }
  }
  if (testae==1){
    jafeitas[e]=1;
    i=e;
    printf("%d\n",e );
    printMaxActivities(s,f,n,i,jafeitas);
  }
}
int main(){

  int s[] = {1, 3, 5 , 0, 5, 3, 5, 6, 8, 8, 2, 12};
  int f[] = {4, 5, 24, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  int n = sizeof(s)/sizeof(s[0]);
  int jafeitas[n];
  for (int i=0;i<n;i++){
    jafeitas[i]=0;
  }
  for (int i=0;i<n;i++){
  }
  printf("%d\n", 0 );
  printMaxActivities(s, f, n, 0 , jafeitas);
  return 0;
}
