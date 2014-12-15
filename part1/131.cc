#include <cstdio>
#include <cstring>
using namespace std;

#define bin(i) (1<<i)
#define emp(a,i) (!(a&bin(i)))
int M, N, full;
const int MAX_N = 1 << 11;
long long cur[MAX_N], nxt[MAX_N];

void dfs(int a, int b, long long k) {
  if(a == full) {
    nxt[b] += k;
    return;
  }
  for(int i = 0; i < M; i++) if(emp(a,i)) {
   if(i + 1 < M && emp(a, i + 1)) {
                        dfs(a | bin(i) | bin(i + 1), b, k);
                        if(emp(b, i)) dfs(a | bin(i)| bin(i + 1),b | bin(i), k);
                        if(i + 1 < M && emp(b,i + 1))dfs(a | bin(i) | bin(i + 1), b | bin(i + 1), k);
                }
                if(emp(b, i)){
                        dfs(a | bin(i), b | bin(i), k);
                        if(i + 1 < M && emp(b, i + 1)) dfs(a | bin(i), b | bin(i) | bin(i + 1), k);
                        if(i >= 1 && emp(b, i - 1)) dfs(a | bin(i), b | bin(i) | bin(i - 1), k);
                }
                break;
    }
}

int main(void) {
  scanf("%d %d", &N, &M);
  full = (1 << M) - 1;
  cur[full] = 1LL;
  for(int i = 0; i <= N; i++) {
    for(int s = 0; s <= full; s++) {
      if(cur[s]) dfs(s, 0, cur[s]);
    }
    memcpy(cur, nxt, sizeof nxt);
    memset(nxt, 0, sizeof nxt);
  }

  printf("%lld\n", cur[0]);
  return 0;
}
