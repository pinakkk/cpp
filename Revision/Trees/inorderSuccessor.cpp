#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node *next;

  Node(int value) {
    data = value;
    left = NULL;
    right = NULL;
    next = NULL;
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

Node *prevNode = NULL;

void populateSuccessor(Node *root) {
  if (root == NULL)
    return;

  populateSuccessor(root->left);
  if (prevNode != NULL) {
    prevNode->next = root;
    cout << prevNode->data << " --> " << root->data << " ";
  }
  prevNode = root;
  populateSuccessor(root->right);
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

  populateSuccessor(root);
  return 0;
}
