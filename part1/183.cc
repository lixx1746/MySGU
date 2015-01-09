#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M;
int a[10005];
int dp[10005][2];
int main(void) {
  scanf("%d %d", &N, &M);
  for(int i = 1; i <= N; i++) {
    scanf("%d", a + i);
  }
  memset(dp, 0x3F, sizeof dp);
  dp[0][1] = dp[0][0] = 0;
  for(int i = 1; i <= N; i++) {
    for(int m = max(0, i - M); m <= i - 1; m++) {
      if(dp[i][1] < dp[m][1] + a[i]) dp[i][1] = dp[m][1] + a[i];
    }
    for(int m = max(0, i - M); m <= i - 1; m++) {
      for(int n = m + 1; n <= i - 1; n++) {
        if(dp[i][0] < dp[m][1] + dp[n][1]) dp[i][0] = dp[m][1] + dp[n][1];
      }
    }
    cout << dp[i][0] << " " << dp[i][1] << endl;
  }
  int ans = dp[N][0] < dp[N][1] ? dp[N][0] : dp[N][1];
  printf("%d\n", ans);


  return 0;
}
