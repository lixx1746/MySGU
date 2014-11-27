#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime(int n) {
  if(n < 2) return 0;
  if(n == 2) return 1;
  if(!(n & 1)) return 0;
  for(int i = 3; i < sqrt(n) + 1; i += 2) if((n % i) == 0) return 0;
  return 1;
}


int main(void) {
  int n;
  vector<int> res;
  cin >> n;
  if(n >= 5) res.push_back(3);
  int i = 1, ele;
  while((ele = 6 * i - 1) <= (n - 2)) {
    if(isPrime(ele) && isPrime(ele + 2)) res.push_back(ele);
    ele = 6 * i + 1;
    if(ele + 2 <= n && isPrime(ele) && isPrime(2 + ele)) res.push_back(ele);
    i++;
  }
  cout << res.size() << endl;
  for(int i = 0; i < (int) res.size(); i++) cout << 2 << " " << res[i] << endl;
  return 0;
}
