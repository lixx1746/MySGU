#include <cstdio>
#include <cstring>
using namespace std;
int A, alpha, beta, gamma, M, k;
int pos[1001], res[1001];

int main(void) {
  scanf("%d %d %d %d %d %d", &A, &alpha, &beta, &gamma, &M, &k);
  int x = A % M, i, len, circle_len;
  memset(pos, -1, sizeof pos);
  pos[x] = 0; res[0] = x;
  for(i = 1; ;i++) {
    x = ((alpha * x * x) % M + beta * x % M + gamma % M) % M;
    if(pos[x] != -1) {
      len = pos[x];
      circle_len = i - len;
      break;
    }
    pos[x] = i;
    res[i] = x;
  }
  if(k == 0) printf("%d\n", A);
  else if(k <= len) printf("%d\n", res[k]);
  else printf("%d\n", res[(k - len) % circle_len + len]);
  return 0;
}
