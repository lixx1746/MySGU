#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
inline int abs(int a) { return a < 0 ? -a : a; }
string str1, str2;
int d1[5005], d2[5005], cnt1, cnt2;
int main(void) {
  cin >> str1 >> str2;
  int n1 = str1.size(), n2 = str2.size();
  if(n1 != n2) { cout << -1 << endl; return 0; }
  for(int i = 0; i < n1; i++) if(str1[i] == '-') d1[++cnt1] = i;
  for(int i = 0; i < n2; i++) if(str2[i] == '-') d2[++cnt2] = i;
  if(cnt1 != cnt2) { cout << -1 << endl; return 0; }
  int ans = 0;
  for(int i = 1; i <= cnt1; i++) ans += abs(d1[i] - d2[i]);
  cout << ans << endl;
  return 0;
}
