#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
const int MAX_N = 105;
int N;
typedef pair<int, int> Pii;
Pii job[MAX_N];
bool mycomp(Pii a, Pii b) { return a.second > b.second; }
int main(void) {
  cin >> N;
  for(int i = 0; i < N; i++) cin >> job[i].first;
  for(int i = 0; i < N; i++) cin >> job[i].second;
  sort(job, job + N, mycomp);
  int acc = 0, ans = 0;
  for(int i = 0; i < N; i++) {
    ans = max(ans, acc + job[i].first + job[i].second);
    acc += job[i].first;
  }
  cout << ans << endl;
  return 0;
}
