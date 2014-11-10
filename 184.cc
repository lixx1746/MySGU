#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
  int P, M, C, K, R, V;
  cin >> P >> M >> C >> K >> R >> V;
  int a[] = {P / K, M / R, C / V };
  sort(a, a + 3);
  cout << a[0] << endl;
  return 0;
}
