#include <iostream>

using namespace std;

int K;

int main(void) {
  cin >> K;
  if(K == 1) cout << 8 << endl;
  else if((K + 2) % 3 == 0 && (K  + 5) % 6 == 0) cout << 4 << endl;
  else if((K + 2) % 3 == 0) cout << 3 << endl;
  else cout << 1 << endl;
  return 0;
}
