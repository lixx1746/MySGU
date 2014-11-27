#include <iostream>

using namespace std;

int data[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ac[13];
int main(void) {
  ac[1] = 31;
  for(int i = 2; i <= 12; i++) ac[i] =  data[i] + ac[i - 1];
  int d, m;
  cin >> d >> m;
  if(d > data[m]) { cout << "Impossible" << endl; return 0; }
  int sum = ac[m - 1] + d;
  int data = sum % 7 == 0 ? 7 : sum % 7;
  cout << data << endl;
  return 0;
}
