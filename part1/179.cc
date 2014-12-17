#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int cnt[10005];
string str;
int main(void) {
  cin >> str;
  int len = str.size();
  int f = 0, b = 0;
  for(int i = 0; i < len; i++) {
    if(str[i] == '(') cnt[i] = f++;
    else cnt[i] = b++;
  }
  int t;
  for(int i = len - 1; i >= 0; i--) {
    if(str[i] == ')') t = i;
    else if(cnt[i] > cnt[t]) {
      swap(str[i], str[len - 1]);
      reverse(str.begin() + i + 1, str.end());
      cout << str << endl;
      return 0;
    }
  }
  cout << "No solution" << endl;
  return 0;
}
