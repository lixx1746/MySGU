#include <iostream>

using namespace std;

int main(void) {
  int S, P, res;
  cin >> S >> P;
  int gap = P - S;
  if(gap < 1) res = 0;
  else {
    int minute = gap / 60;
    if(minute < 5) res = 1;
    else if(minute >= 5 && minute < 15) res = 2;
    else if(minute >= 15 && minute < 30) res = 3;
    else res = 4;
  }
  cout << res << endl;
  return 0;
}
