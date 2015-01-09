#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
const LL mul = 10000;

int main(void) {
  LL len, N, v, t, sum = 0;
  double l;
  scanf("%lf %lld", &l, &N);
  len = round(l * mul);
  for(int i = 1; i <= N; i++) {
    scanf("%lld %lld", &v, &t);
    sum += v * t * mul;
    sum %= len;
  }
  double ans = (double) (1.0 * sum) / mul;
  if(l - ans < ans) ans = l - ans;
  printf("%.4lf\n", ans);
}
