#include <cstdio>
#include <algorithm>
using namespace std;
int data[105];
int main(void) {
  int l = 0, ans = 0, r;
  scanf("%d", &r);
  for(int i = 0; i < r; i++) scanf("%d", data + i);
  sort(data, data + r);
  r--;
  while(l < r) {
    data[l]--; r--;
    if(!data[l]) l++;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
