#include <iostream>

using namespace std;

int N, q;

int search(int n, int q) {
  if(n == 1) return q;
  if(q <= n / 2) return (n - n / 2) + search(n / 2, n / 2 - q + 1);
  else return search(n - n / 2, n - q + 1);
}

int main(void) {
  cin >> N >> q;
  cout << search(N, q) << endl;
  return 0;
}
