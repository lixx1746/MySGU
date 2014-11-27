#include <iostream>
#include <algorithm>

using namespace std;
int cont[10];
int main(void) {
  int k, n;
  cin >> k >> n;
  string s;
  for(int i = 0; i < n; i++) {
    cin >> s;
    cont[s[0] - '0']++;
  }
  int ans = 2;
  for(int i = 0; i < 10; i++) if(cont[i] > 0) {
    int cur = cont[i];
    ans += cur / k;
    if(cur % k) ans++;
  }

  cout << ans << endl;
  return 0;
}
