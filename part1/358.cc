#include <cstdio>
#include <algorithm>
using namespace std;

int data[3], res[3];
int main(void) {
  for(int i = 0, j = 0; i < 9; i++) {
    scanf("%d", &data[i % 3]);
    if((i + 1) % 3 == 0) {
      sort(data, data + 3);
      res[j++] = data[1];
    }
  }
  sort(res, res + 3);
  printf("%d\n", res[1]);
  return 0;
}
