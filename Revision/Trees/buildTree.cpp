#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = NULL;
    right = NULL;
  }
};

void insert(Node *&root, int val) {
  Node *newNode = new Node(val);
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

void deleteDeepest(Node *root, Node *deepest) {
  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    Node *temp = q.front();
    q.pop();

    if (temp->left != NULL) {
      if (temp->left == deepest) {
        temp->left = NULL;
        delete deepest;
        return;
      } else {
        q.push(temp->left);
      }
    }

    if (temp->right != NULL) {
      if (temp->right == deepest) {
        temp->right = NULL;
        delete deepest;
        return;
      } else {
        q.push(temp->right);
      }
    }
  }
}

void buildBST(Node *&root, int val) {
  if (root == NULL) {
    root = new Node(val);
    return;
  }

  if (val < root->data) {
    buildBST(root->left, val);
  }

  else {
    buildBST(root->right, val);
  }
}

void levelOrder(Node *root) {
  if (root == NULL) {
    return;
  }
  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    Node *temp = q.front();
    q.pop();
    cout << temp->data << " ";

    if (temp->left != NULL) {
      q.push(temp->left);
    }

    if (temp->right != NULL) {
      q.push(temp->right);
    }
  }
}

void inorder(Node *root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

int main() {
  Node *root = NULL;

  int val;

  while (cin >> val && val != -1) {
    buildBST(root, val);
  }

  inorder(root);

  return 0;
}