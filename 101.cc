#include <iostream>
#include <algorithm>

using namespace std;

int rot[105], order[105], X[105], Y[105];
int main(void) {
  int N;
  cin >> N;
  for(int i = 1; i <= N; i++) {
    int x, y;
    cin >> x >> y;
    order[i] = i;
    if(x > y) { rot[i] = 1; int temp = x; x = y; y = temp; }
    X[i] = x;
    Y[i] = y;
  }

  for(int i = 1; i <= N; i++) {
    for(int j = i + 1; j <= N; j++) {
      if(X[i] >= X[j]) {


      }

    }

  }


}
