#include <iostream>

using namespace std;

struct Node {
  Node* next;
  Node* prev;
  int data;
};

int n, k;
Node node[5003];
Node* cursor;
int nodeCount, numCount;

Node* makeNode(int num) {
  Node* newNode = &node[nodeCount++];
  newNode->data = num;
  return newNode;
}

void init() {
  Node* newNode = makeNode(1);
  Node* prevNode = newNode;
  cursor = newNode;

  for(int i = 2 ; i <= n  ; i++) {
    newNode = makeNode(i);
    newNode->prev = prevNode;
    prevNode->next = newNode;
    prevNode = newNode;
  }
  prevNode->next = cursor;
  cursor->prev = prevNode;
  cursor = prevNode;

  numCount = n;
}

int main() {
  Node* nextCursor;
  cin >> n >> k;

  init();

  cout << '<';

  while(numCount > 0) {
    for(int i = 0 ; i < k ; i++) cursor = cursor->next;
    cout << cursor->data;
    nextCursor = cursor->prev;
    if(numCount >= 2) {
      cursor->prev->next = cursor->next;
      cursor->next->prev = cursor->prev;
      cursor->next = NULL;
      cursor->prev = NULL;
    }

    cursor = nextCursor;
    numCount--;

    if(numCount > 0) cout << ", ";
  }
  cout << ">\n";
  return 0;
}
/*
5 2
<2, 4, 1, 5, 3>

10 5
<5, 10, 6, 2, 9, 8, 1, 4, 7, 3>

3 2
<2, 1, 3>

4 2
<2, 4, 3, 1>
*/