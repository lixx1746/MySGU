#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int N, l, r;
typedef pair<int, int> Pii;
bool mycomp(Pii a, Pii b) { return a.first < b.first || (a.first == b.first && a.second > b.second); }
Pii data[16005];
bool mask[16005];

int main(void) {
  scanf("%d", &N);
  for(int i = 0; i < N; i++)
    scanf("%d %d", &data[i].first, &data[i].second);
  sort(data, data + N, mycomp);
  memset(mask, true, sizeof mask);
  int ans = 0;
  for(int i = 0; i < N; i++) {
    if(!mask[i]) continue;
    for(int j = i + 1; j < N; j++) {
      if(!mask[j]) continue;
      if(data[j].first > data[i].first && data[j].second < data[i].second) { ans++; mask[j] = 0; }
    }
  }
  printf("%d\n", ans);
  return 0;
}
