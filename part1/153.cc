#include <cstdio>
#include <cstring>
using namespace std;
int N, M;
int dp[1200], P[10];
int main(void) {
  int tc;
  scanf("%d", &tc);
  P[0] = 1;
  while(tc--) {
    scanf("%d %d", &N, &M);
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= M; i++) scanf("%d", P + i);
    for(int i = 1; i < 1100; i++)
      if(!dp[i]) for(int j = 0; j <= M; j++) dp[i + P[j]] = 1;
    int c_len = 520;
    while(1) {
      int l = 1, r = c_len + 1, k;
      for(k = 0; k < c_len; k++) if(dp[l + k] != dp[r + k]) break;
      if(k >= c_len) break;
      c_len--;
    }
    if(dp[N % c_len]) puts("FIRST PLAYER MUST WIN");
    else puts("SECOND PLAYER MUST WIN");
  }

  return 0;
}
