#include <cstdio>
using namespace std;


int main(void) {
  int N;
  scanf("%d", &N);
  N -= 9;
  if(N < 0) printf("0");
  else if(N == 0) printf("8");
  else {
    printf("72");
    for(int i = 1; i < N; i++) printf("0");
  }
  printf("\n");
  return 0;
}
