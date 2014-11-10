#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 65537;
int data[N];

long long solve(int *p, int n) {
  if(n == 0 || n == 1) return 0;
  int l[n / 2], r[n - n / 2];
  memcpy(l, p, (n / 2) * sizeof(int));
  memcpy(r, p + n / 2, (n - n / 2) * sizeof(int));
  long long res = solve(l, n / 2) + solve(r, n - n / 2);
  for(int i = 0, j = 0; i + j < n;) {
    if(j ==  (n - n / 2) || (i < n / 2 && *(l + i) <= *(r + j))) {
      *(p + i + j) = *(l + i);
      i++;
      res += j;
    }
    else {
      *(p + i + j) = *(r + j);
      j++;
    }
  }
  return res;
}

int main(void) {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> data[i];
  cout << solve(data, n) << endl;
  return 0;
}
