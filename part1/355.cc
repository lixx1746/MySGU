#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
int res[10005];

int main(void) {
  scanf("%d", &N);
  res[1] = 1;
  int ans = 1;
  for(int i = 2; i <= N; i++) {
    vector<int> colors(1, 1);
    int l = 2;
    while(l < sqrt(i)) {
      if(i % l == 0) {
        colors.push_back(res[l]);
        colors.push_back(res[i / l]);
      }
      l++;
    }
    if(l * l == i) colors.push_back(res[l]);
    sort(colors.begin(), colors.end());
    colors.erase(unique(colors.begin(), colors.end()), colors.end());
    if((int) colors.size() == ans) { ans++; res[i] = ans; }
    else {
      int flag = 0, j = 0;
      for(; !flag && j < (int) colors.size(); j++) {
        if(colors[j] == j + 1) continue;
        res[i] = j + 1;
        flag = 1;
      }
      if(!flag) res[i] = j + 1;
    }
  }
  printf("%d\n", ans);
  for(int i = 1; i <= N; i++) printf("%d ", res[i]);

}
