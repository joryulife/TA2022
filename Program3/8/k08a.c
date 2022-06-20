#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define N 100000
#define llint long long int 

//O(1+2+3+,,,n  +  n) = O((n+n^2)/2  +  n) = O(n^2)
void set_sum0(llint n, int a[]) {
  int b[n];
  for (int i = 0; i < n; i++) {
    int ans = 0;
    for(int j = 0;j <= i;j++){
      ans += a[j];
    }
    b[i] = ans;
  }
  for(int i = 0;i < n;i++){
    a[i] = b[i];
  }
}

//O(n^2)
void set_sum1(llint n, int a[]) {
  int b[n];
  for (int i = 1; i < n; i++) {
    int ans = 0;
    for(int j = 0;j <= i;j++){
      ans += a[j];
    }
    b[i] = ans;
  }
  memcpy(a,b,sizeof(b));
}

//O(n^2)
void set_sum2(llint n, int a[]) {
  for (int i = n-1; 0 <= i ; i--) {
    for(int j = 0;j < i;j++){
      a[i] += a[j];
    }
  }
}

//O(n)
void set_sum3(llint n, int a[]) {
  if (n > 0) {
    a[0] = 0;
  }
  for (int i = 1; i < n; i++) {
    a[i] = a[i-1] + i;
  }
}

void set_sum4(llint n, int a[]) {
  if (n > 0) {
    a[0] = 0;
  }
  for (int i = 1; i < n; i++) {
    a[i] = a[i-1] + a[i];
  }
}

void set_sum5(llint n, int a[]) {
  if (n > 0) {
    a[0] = 0;
  }
  int i = 1;
  while(i < n){
    a[i] = a[i-1] + a[i];
    i++;
  }
}

void set_sum6(llint n, int a[]) {
  if(n <= 0) return;
  int *p;
  p = &a[0];
  *p = 0;
  int j = n-1;
  while(j--){
    *(p+1) = *p + *(p+1);
    p++;
  }
}

void set_array(llint n,int a[]){
  for(int i = 0;i<n;i++){
    a[i] = rand()%3;
  }
}



int main(void) {
  int a0[N];
  int a1[N];
  int a2[N];
  int a3[N];
  int a4[N];
  int a5[N];
  int a6[N];
  long long n = sizeof(a0)/sizeof(a0[0]);

  set_array(n,a0);
  set_array(n,a1);
  set_array(n,a2);
  set_array(n,a3);
  set_array(n,a4);
  set_array(n,a5);
  set_array(n,a6);
  /*for (int i = 0; i < n; i++) {
    printf("%d,", a0[i]);
  }*/
  printf("\n");
  long long cpu_time_old = clock();

  set_sum0(n, a0);
  long long cpu_time_new = clock();
  printf("set_sum0:%lld\n",cpu_time_new - cpu_time_old);
  cpu_time_old = cpu_time_new;

  set_sum1(n, a1);
  cpu_time_new = clock();
  printf("set_sum1:%lld\n",cpu_time_new - cpu_time_old);
  cpu_time_old = cpu_time_new;

  set_sum2(n, a2);
  cpu_time_new = clock();
  printf("set_sum2:%lld\n",cpu_time_new - cpu_time_old);
  cpu_time_old = cpu_time_new;

  set_sum3(n, a3);
  cpu_time_new = clock();
  printf("set_sum3:%lld\n",cpu_time_new - cpu_time_old);
  cpu_time_old = cpu_time_new;

  set_sum4(n, a4);
  cpu_time_new = clock();
  printf("set_sum4:%lld\n",cpu_time_new - cpu_time_old);
  cpu_time_old = cpu_time_new;

  set_sum5(n, a5);
  cpu_time_new = clock();
  printf("set_sum5:%lld\n",cpu_time_new - cpu_time_old);
  cpu_time_old = cpu_time_new;

  set_sum6(n, a6);
  cpu_time_new = clock();
  printf("set_sum6:%lld\n",cpu_time_new - cpu_time_old);
  cpu_time_old = cpu_time_new;

  /*for (int i = 0; i < n; i++) {
    printf("%d,", a0[i]);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d,", a1[i]);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d,", a2[i]);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d,", a3[i]);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d,", a4[i]);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d,", a5[i]);
  }
  printf("\n");*/
  return 0;
}
