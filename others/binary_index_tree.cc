#include <iostream>
#include <vector>
using namespace std;


struct Fenwick_Tree_Sum {
  vector<int> tree;
  Fenwick_Tree_Sum(const int *Arg, int n) {
    tree.resize(n);
    for(int i = 0 ; i< (int) tree.size(); i++) increase(i, Arg[i]);
  }
  // Increases value of i-th element by ''delta''.
  void increase(int i, int delta) {
    for (; i < (int)tree.size(); i |= i + 1) tree[i] += delta;
  }

  // Returns sum of elements with indexes left..right, inclusive; (zero-based);
  int getsum(int left, int right) {
    return sum(right) - sum(left-1); //when left equals 0 the function hopefully returns 0
  }

  int sum(int ind) {
    int sum = 0;
    while (ind>=0) {
      sum += tree[ind];
      ind &= ind + 1;
      ind--;
    }
    return sum;
  }
};

int main(void) {
  int test1[] = { 1, 2, 3, 4, 5, 6, 7 };
  Fenwick_Tree_Sum tree1(test1, 7);
  for(int i = 0; i < 7; i++) cout << tree1.tree[i] << " ";
  cout << endl;
  return 0;
}
