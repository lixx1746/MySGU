#include <iostream>
#include <stack>
#include <vector>
using namespace std;

string str;
stack<int> st;

char to_low(char c) {
  if(c >= 'a' && c <= 'z') return c;
  else return (c - 'A') + 'a';
}

char to_up(char c) {
  if(c >= 'A' && c <= 'Z') return c;
  else return (c - 'a') + 'A';
}

int main(void) {
  cin >> str;
  int state = -1;
  string s;
  string res;
  for(int i = 0; i < (int) str.size(); ) {
    char c  = str[i];
    if(c == '<') {
      if(str[i + 1] == '/') {
        st.pop();
        if(str[i + 2] == 'U') {
          state = st.empty() ? -1 : st.top();
          i += 5;
        }
        else {
          state = st.empty() ? -1 : st.top();
          i += 7;
        }
      }
      else {
        if(str[i + 1] == 'U') {
          state = 1;
          i += 4;
        }
        else {
          state = 0;
          i += 6;
        }
        st.push(state);
      }
    }
    else {
      char t;
      if(state == -1) t = str[i];
      else if(state == 0) t = to_low(str[i]);
      else t = to_up(str[i]);
      res.push_back(t);
      i++;
    }
  }

  cout << res << endl;

  return 0;
}
