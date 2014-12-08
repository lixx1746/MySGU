#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int num;
int dp[10010], prime[10010], pre[10010];
const int INF = 100000;

int main(void) {
  cin >> num;
  for (int i = 0; i <10010 ; i++) dp[i] = INF;
  for(int i = 2; i < 10010; i++) prime[i] = 1;
  for(int i = 2; i * i < 10010; i++) if(prime[i]) for(int j = i * i; j < 10010; j += i) prime[j] = 0;
  int cnt = 0;
  dp[0] = 0;
  for(int i = 2; i < 10010; i++) {
    if(prime[i]) {
      cnt++;
      if(prime[cnt]) {
        for(int j = i; j < 10010; j++)
          if(dp[j - i] + 1 <= dp[j]) {
            dp[j] = dp[j - i] + 1;
            pre[j] = i;
          }
      }
    }
  }

  vector<int> res;
  int flag = 1;
  while(flag && num > 0) {
    if(pre[num] == 0) flag = 0;
    else {
      res.push_back(pre[num]);
      num -= pre[num];
    }
  }

  if(!flag) cout << 0 << endl;
  else {
    cout << res.size() << endl;
    for(int i = 0; i < (int) res.size(); i++) {
      if(i != 0) cout << " ";
      cout << res[i];
      if(i == (int) res.size() - 1) cout << endl;
    }
  }

  return 0;
}
