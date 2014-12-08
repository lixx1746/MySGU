#include <iostream>
#include <vector>

using namespace std;

int aes[105][105];
int dp[105][105], pre[105];
int main(void) {
  int F, V;
  cin >> F >> V;
  for(int i = 1; i < 105; i++)
    for(int j = i; j <= F; j++)
      dp[i][j] = -100000;

  for(int i = 1; i <= F; i++)
    for(int j = 1; j <= V; j++)
      cin >> aes[i][j];

  for(int i = 1; i <= V; i++) {
    for(int j = 1; j <= i; j++) {
      if(i - 1 >= j) dp[i][j] = max(dp[i - 1][j - 1] + aes[j][i], dp[i - 1][j]);
      else dp[i][j] = dp[i - 1][j - 1] + aes[j][i];
    }
  }

  int ans = dp[V][F];
  cout << ans << endl;
  vector<int> res;
  int i = V, j = F;
  while(ans > 0) {
    if(dp[i - 1][j - 1] + aes[j][i] == ans) {
      res.push_back(i);
      ans -= aes[j--][i--];
    }
    else i--;
  }
  reverse(res.begin(), res.end());
  for(int i = 0; i < (int) res.size(); i++) { if(i != 0) cout << " "; cout << res[i]; }
  cout << endl;


  return 0;
}
