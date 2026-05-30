#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int value) {
    data = value;
    left = NULL;
    right = NULL;
  }
};

void insert(Node *&root, int value) {
  Node *newNode = new Node(value);
  if (root == NULL) {
    root = newNode;
    return;
  }

  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    Node *temp = q.front();
    q.pop();

    if (temp->left == NULL) {
      temp->left = newNode;
      return;
    } else {
      q.push(temp->left);
    }

    if (temp->right == NULL) {
      temp->right = newNode;
      return;
    } else {
      q.push(temp->right);
    }
  }
}

void spiralOrder(Node *root) {
  if (root == NULL)
    return;

  stack<Node *> s1;
  stack<Node *> s2;
  s1.push(root);

  while (!s1.empty() || !s2.empty()) {

    while (!s1.empty()) {
      Node *temp = s1.top();
      s1.pop();

      cout << temp->data << " ";
      if (temp->left != NULL)
        s2.push(temp->left);

      if (temp->right != NULL)
        s2.push(temp->right);
    }

    while (!s2.empty()) {
      Node *temp = s2.top();
      s2.pop();

      cout << temp->data << " ";

      if (temp->left != NULL)
        s1.push(temp->right);

      if (temp->right != NULL)
        s1.push(temp->left);
    }
  }
}

int main() {
  int n;
  cin >> n;
  Node *root = NULL;

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    insert(root, val);
  }

  spiralOrder(root);

  return 0;
}
