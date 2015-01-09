#include <cstdio>
#include <iostream>
using namespace std;

const int MAX_N = 10000;
int heap[MAX_N];
int cnt = 0;

bool mycomp(int a, int b) { return a < b; }

int left_child(int id) {
  int t = (id << 1) + 1;
  return t < cnt ? t : -1;
}

int right_child(int id) {
  int t = (id << 1) + 2;
  return t < cnt ? t : -1;
}

int parent(int id) {
  if(id == 0) return -1;
  return (id - 1) >> 1;
}

void swapup(int id) {
  while(id > 0 && parent(id) >= 0 && heap[id] < heap[parent(id)]) {
    heap[id] ^= heap[parent(id)];
    heap[parent(id)] ^= heap[id];
    heap[id] ^= heap[parent(id)];
  }
}

void swapdown(int id) {
  int child = left_child(id);
  if(child > 0 && right_child(id) > 0 && heap[child] > heap[right_child(id)])
     child = right_child(id);
  if(child > 0 && heap[child] < heap[id]) {
    heap[id] ^= heap[child];
    heap[child] ^= heap[id];
    heap[id] ^= heap[child];
    swapdown(child);
  }
}

int top(void) { if(cnt > 0) return heap[0]; else return -1; }

void insert(int ele) {
  heap[cnt++] = ele;
  swapup(cnt - 1);
}

void pop(void) {
  if(cnt <= 0) return;
  heap[0] = heap[--cnt];
  swapdown(0);
}

int main(void) {
  for(int i = 1; i < 10; i++) insert(i);
  while(cnt) {  cout << top() << endl; pop(); }
  return 0;
}
