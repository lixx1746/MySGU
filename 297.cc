#include <iostream>

using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;
  int sum = 0, ele;
  for(int i = 0; i < M; i++) { cin >> ele; sum += ele; }
  cout << sum % N;
  return 0;
}
