#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int N;
int A[3][3], B[3][3];
int idir[] = { 0, -1, 0, 1}, jdir[] = {-1, 0, 1, 0};

bool check(int i, int j) {
  int acc = 0;
  for(int d = 0; d < 4; d++) {
    int toi = i + idir[d], toj = j + jdir[d];
    if(toi < 0 || toj < 0 || toi >= N || toj >= N) continue;
    if(A[toi][toj] > A[i][j]) acc++;
  }
  return acc == B[i][j];
}

void dfs(int i, int j) {
   if(i == N) {
     for(int k = 0; k < N; k++) if(!check(i - 1, k)) return;
     for(int m = 0; m < N; m++) {
       for(int n = 0; n < N; n++) {
         if(n != 0) printf(" ");
         printf("%d", A[m][n]);
       }
       printf("\n");
     }
     exit(0);
   }
   for(int cand = 0; cand <= 9; cand++) {
     A[i][j] = cand;
     if(i == 0 || check(i - 1, j)) {
       if(j == N - 1)  dfs(i + 1, 0);
       else dfs(i, j + 1);
     }
   }
}

int main(void) {
  scanf("%d", &N);
  memset(A, -1, sizeof A);
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      scanf("%d", &B[i][j]);
   dfs(0, 0);
   printf("NO SOLUTION\n");

  return 0;
}
