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

Node *lca(Node *root, int p, int q) {
  if (root == NULL)
    return NULL;

  if (root->data == p || root->data == q) {
    return root;
  }

  Node *left = lca(root->left, p, q);
  Node *right = lca(root->right, p, q);

  if (left && right)
    return root;

  if (left)
    return left;

  return right;
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

  int a, b;
  cin >> a >> b;
  Node *ans = lca(root, a, b);
  if (ans)
    cout << ans->data << " ";

  return 0;
}
