#include <iostream>

using namespace std;

struct Node {
  Node* prev;
  Node* next;
  int num;
  char data;
};

string initial;
Node node[600010];
Node* cursor;
int nodeCount, numCount;
int n;

void init() {
  node[0].data = -1;
  node[0].num = -1;

  node[1].data = -2;
  node[1].num = -2;

  node[0].prev = NULL;
  node[0].next = &node[1];

  node[1].next = NULL;
  node[1].prev = &node[0];

  cursor = &node[1];
  nodeCount = 2;

  for(int i = 0 ; i < initial.length() ; i++) {
    char current = initial[i];
    Node* newNode = &node[nodeCount++];
    
    newNode->num = numCount++;
    newNode->data = current;
    newNode->prev = cursor->prev;
    newNode->next = cursor;
    
    cursor->prev->next = newNode;
    cursor->prev = newNode;
  }
}

int main() {
  char cmd, letter;

  cin >> initial;
  cin >> n;

  init();

  for(int i = 0 ; i < n ; i++) {
    cin >> cmd;
    if(cmd == 'L') {
      if(cursor->prev->num == -1) continue;
      cursor = cursor->prev;
    }
    else if(cmd == 'D') {
      if(cursor->next == NULL) continue;
      cursor = cursor->next;
    }
    else if(cmd == 'B') {
      Node* target = cursor->prev;
      if(target->num == -1) continue;
      
      cursor->prev = target->prev;
      target->prev->next = cursor;

      target->prev = NULL;
      target->next = NULL;
    }
    else if(cmd == 'P') {
      cin >> letter;
      Node* newNode = &node[nodeCount++];
      newNode->data = letter;
      newNode->num = numCount++;
      newNode->next = cursor;
      newNode->prev = cursor->prev;
      cursor->prev->next = newNode;
      cursor->prev = newNode;
    }
  }

  Node* printNode = node[0].next;
  while(printNode->num != -2) {
    cout << printNode->data;
    printNode = printNode->next;
  }
  cout << '\n';
  
  return 0;
}