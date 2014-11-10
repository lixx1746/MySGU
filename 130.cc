#include <iostream>

using namespace std;

long long dp[100];

int main(void) {
  int k;
  cin >> k;
  dp[0] = 1;
  for(int i = 1; i <= k; i++) {
    long long sum = 0;
    for(int j = 1; j <= i; j++) {
      sum += dp[2 * i - 2 * j] * dp[2 * j - 2];
    }
    dp[2 * i] = sum;
  }
  cout << dp[2 * k] << " " << k + 1 << endl;
  return 0;
}
