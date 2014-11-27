#include <iostream>

using namespace std;
int main(void) {
  long long pre = 1, cur = 1, i = 1, K, temp;
  long long sum = 1;
  cin >> K;
  while(i < K) {
    sum += cur;
    temp = pre;
    pre = cur;
    cur += temp;
    i++;
  }
  cout << sum << endl;

}
