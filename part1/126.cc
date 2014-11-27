#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
  int a, b, c = 0;
  cin >> a >> b;
  while(a && b && c < 35) {
    if(a > b) swap(a, b);
    b -= a;
    a <<= 1;
    c++;
  }
  if(c >= 35) cout << -1 << endl;
  else cout << c << endl;
  return 0;
}
