#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
  if(n < 2) return 0;
  if(n == 2) return 1;
  if(n % 2 == 0) return 0;
  for(int s = 3; (s * s) <= n ; s += 2) {
    if(n % s == 0) return 0;
  }
  return 1;
}
bool check(int n) {
  if(isPrime(n)) return 0;
  if(n % 2 == 0) return isPrime(n / 2);
  if(n % 3 == 0) return isPrime(n / 3);
  int i = 1, s = 0;
  while((s * s) <= n) {
    s = 6 * i - 1;
    if(n % s == 0) break;
    s = 6 * i + 1;
    if(n % s == 0) break;
    i++;
  }
  return isPrime(n / s);
}

int main(void) {
  int n, k;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> k;
    if(check(k)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
