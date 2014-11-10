#include <cstdio>
using namespace std;

int main(void) {
  int x, y;
  double z;
  scanf("%d %d %lf", &x, &y, &z);
  double l = 60.0 *(y - x);
  printf("%.7lf\n", (1 + (l - z) / l) * (z / l));
  return 0;
}
