#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N, K, q;

bool mask[128];
int res[1000000];
int main(void) {
  cin >> N >> K;
  int t = 0;
  memset(mask, true, sizeof mask);
  for(int i = 1; i <= N; i += 64) {
    memset(mask + 64, true, sizeof(mask) / 2);
    for(int d = 0; d <= 63; d++) {
      int ele = i + d, tmp = i + d;
      while(tmp) {
        ele += (tmp % 10);
        tmp /= 10;
      }
      mask[ele - i] = false;
    }
    for(int j = 0; j < 64; j++) if(mask[j]) res[++t] = i + j;
    for(int j = 0; j < 64; j++) mask[j] = mask[j + 64];
  }

  while(res[t] > N) t--;
  cout << t  << endl;
  for(int i = 0; i < K; i++) {
    cin >> q;
    if(i != 0) cout << " ";
    cout << res[q];
    if(i == K - 1) cout << endl;
  }

  return 0;
}
