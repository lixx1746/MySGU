#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> ans[10001];

int N, A, B;
bool mycomp(pair<int, int> a, pair<int, int> b) {
  if(a.first < b.first || (a.first == b.first && a.second < b.second)) return 1;
  return 0;
}

int main() {
  scanf("%d %d %d", &N, &A, &B);
  A %= N; B %= N;
  int a = A, b = B;
  int cnt = 0;
  do {
    a = (a + A) % N;
    b = (b + B) % N;
    ans[cnt].first = a;
    ans[cnt].second = b;
    cnt++;
  } while(a != A || b != B);

  sort(ans, ans + cnt, mycomp);
  printf("%d\n", cnt);
  for(int i = 0; i < cnt; i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }

}
