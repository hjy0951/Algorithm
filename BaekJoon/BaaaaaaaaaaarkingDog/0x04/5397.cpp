#include <iostream>
#include <vector>

using namespace std;

struct Node {
  Node* prev;
  Node* next;
  char data;
};

int n;
vector<string> cmds;
Node node[1000002];
Node *head, *tail, *cursor;
int nodeCount = 0;

void init() {
  head = &node[0];
  head->prev = NULL;
  tail = &node[1];
  tail->next = NULL;
  tail->prev = head;
  head->next = tail;
  nodeCount = 2;

  cursor = head;
}

void printPassword() {
  Node* printNode = head->next;

  while(printNode->next != NULL) {
    cout << printNode->data;
    printNode = printNode->next;
  }
  cout << '\n';
}

void executeCmd(int index) {
  string cmd = cmds[index];
  for(int i = 0 ; i < cmd.length() ; i++) {
    char current = cmd[i];

    if(current == '<') {
      // node 왼쪽 이동
      if(cursor->prev == NULL) continue;
      cursor = cursor->prev;
    } else if(current == '>') {
      // node 오른쪽 이동
      if(cursor->next->next == NULL) continue;
      cursor = cursor->next;
    } 
    else if(current == '-') {
      // node 삭제
      if(cursor->prev == NULL) continue;
      Node* nextCursor = cursor->prev;
      cursor->prev->next = cursor->next;
      cursor->next->prev = cursor->prev;
      cursor->prev = NULL;
      cursor->next = NULL;
      cursor = nextCursor;
    } else {
      // node 추가
      Node* newNode = &node[nodeCount++];
      newNode->data = current;
      newNode->prev = cursor;
      newNode->next = cursor->next;
      cursor->next->prev = newNode;
      cursor->next = newNode;
      cursor = newNode;
    }
  }
}

int main() {
  cin >> n;

  for(int i = 0 ; i < n ; i++) {
    string cmd;
    cin >> cmd;
    cmds.push_back(cmd);
  }

  for(int i = 0 ; i < n ; i++) {
    init();
    executeCmd(i);
    printPassword();
  }

  return 0;
}