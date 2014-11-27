#include <iostream>

using namespace std;

int k, m;

long long my_pow(int a, int b) {
  if(b == 0) return 1;
  long long half = my_pow(a, b / 2) % k;
  if(b % 2) return (a * half * half) % k;
  else return (half * half) % k;
}

int main(void) {
  int n, d;
  int c = 0;
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    cin >> d;
    if((my_pow(d, m) % k) == 0) c++;
  }
  cout << c << endl;
  return 0;
}
