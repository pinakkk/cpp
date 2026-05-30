#include <iostream>
#include <queue>
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

int diameter = 0;

int height(Node *root) {
  if (root == NULL) {
    return 0;
  }

  int leftDia = height(root->left);
  int rightDia = height(root->right);

  diameter = max(diameter, leftDia + rightDia + 1);

  return 1 + max(leftDia, rightDia);
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
  height(root);
  cout << diameter << " ";
  return 0;
}
