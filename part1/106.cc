#include <iostream>
#include <algorithm>

using namespace std;

void extgcd(long long a, long long b, long long &d, long long &x, long long &y) {
  if(!b) { d = a; x = 1; y = 0; }
  else { extgcd(b, a % b, d, y, x); y -= (a / b) * x; }
}

int main(void) {
  long long a, b, c, xl, xr, yl, yr, ans = 0;
  cin >> a >> b >> c >> xl >> xr >> yl >> yr;
  c = -c;
  if(a == 0 && b == 0) {
    if(c == 0) ans = (xr - xl + 1) * (yr - yl + 1);
  }
  else if(a == 0) {
    if(c % b == 0 && c / b >= yl && c / b <= yr) ans = xr - xl + 1;
  }
  else if(b == 0) {
    if(c % a == 0 && c / a >= xl && c / a <= xr) ans = yr - yl + 1;
  }
  else {
    long long d, x0, y0;
    extgcd(a, b, d, x0, y0);
    if(c % d == 0) {
      long long lx, rx, ly, ry;
      x0 *= (c / d); y0 *= (c / d);
      lx=(xl<=x0 || (xl-x0)*d % b==0) ? (xl-x0)*d/b : (xl-x0)*d/b+1;
      rx=(xr>=x0 || (x0-xr)*d % b==0) ? (xr-x0)*d/b : (xr-x0)*d/b-1;
      ly=(yl<=y0 || (yl-y0)*d % a==0) ? (y0-yl)*d/a : (y0-yl)*d/a-1;
      ry=(yr>=y0 || (y0-yr)*d % a==0) ? (y0-yr)*d/a : (y0-yr)*d/a+1;
      if (lx>rx) swap(lx,rx);
      if (ly>ry) swap(ly,ry);
      if (lx<=ry && ly<=rx){
        long long l=(lx>ly)?lx:ly;
        long long r=(rx<ry)?rx:ry;
        ans = r - l + 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
