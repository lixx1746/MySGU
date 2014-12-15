#include <iostream>

using namespace std;
int a[16], res;
int main(void) {
  for(int i = 0; i < 16; i++) {
    cin >> a[i];
    if(a[i] == 0) res = 6 - (i % 4) - i / 4;
  }
  for(int i = 0; i < 16; i++) {
    for(int j = i + 1; j < 16; j++) if(a[i] > a[j]) res++;
  }

  if(res & 1) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
