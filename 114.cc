#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int pos[15005], cost[15005];
int n;

int main(void) {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> pos[i] >> cost[i];
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      if(pos[i] > pos[j]) {
        swap(pos[i], pos[j]);
        swap(cost[i], cost[j]);
      }
    }
  }
  vector<int> ac(n + 1, 0);
  for(int i = 1; i <= n; i++) ac[i] = cost[i - 1] + ac[i - 1];
  double l = 0, r = pos[n - 1];
  for(int i = 0; i < 200; i++) {
    double mid = (l + r) / 2.0;
    int temp = lower_bound(pos, pos + n, mid) - pos;
    if(ac[temp] > ac[n] - ac[temp]) r = mid;
    else l = mid;
  }
  cout << l << endl;
  return 0;
}
