#include <iostream>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  long long pre = 1, cur = 1;
  for(int i = 1; i <= N; i++) {
    cur = pre + i;
    pre = cur;
  }
  cout << cur << endl;
  return 0;
}
