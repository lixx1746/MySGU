#include <iostream>
#include <vector>

using namespace std;

int dsum(long long a) {
  if(a < 10) return a;
  int s = 0;
  while(a > 0) {
    s = s +  (a % 10);
    a /= 10;
  }
  return s;
}

int main(void) {
  int k, n;
  cin >> k;
  for(int m = 0; m < k; m++) {
    cin >> n;
    vector<int> data(n, 0);
    for(int i = 0; i < n; i++) cin >> data[i];
    int pre = data[0];
    while(pre >= 10) pre = dsum(pre);
    long long sum = pre;
    for(int j = 1; j < n; j++) {
      long long ele = (long long) data[j] * pre;
      while(ele >= 10) ele = dsum(ele);
      pre = ele;
      sum += ele;
      while(sum >= 10) sum = dsum(sum);
    }
    cout << sum << endl;
  }
  return 0;
}
