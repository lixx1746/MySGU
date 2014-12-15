#include <cstdio>

using namespace std;

int data[10005], N;

int main(void) {
  scanf("%d", &N);
  int sum = 0;
  for(int i = 1; i <= N; i++) {
    scanf("%d", data + i);
    sum += data[i];
  }
  int acc = 0;
  for(int i = 1; i <= N; i++) {
    acc += data[i] * 100 % sum;
    data[i] = data[i] * 100 / sum;
    if(acc >= sum) {
      data[i]++;
      acc -= sum;
    }
  }
  for(int i = 1; i <= N; i++) printf("%d ", data[i]);
  return 0;
}
