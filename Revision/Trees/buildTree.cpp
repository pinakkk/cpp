#include <cstddef>
#include <iostream>
#include <queue>
#include <stack>
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

// Queue Based Insertion
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

// Delete in Queue Based
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

void deleteNode(Node *&root, int key) {
  if (root == NULL)
    return;

  // Only Root Node
  if (root->left == NULL && root->right == NULL) {
    if (root->data == key) {
      delete root;
      root = NULL;
    }

    return;
  }

  queue<Node *> q;
  q.push(root);

  Node *target = NULL;
  Node *temp;

  while (!q.empty()) {
    temp = q.front();
    q.pop();

    if (temp->data == key) {
      target = temp;
    }

    if (temp->left != NULL) {
      q.push(temp->left);
    }

    if (temp->right != NULL) {
      q.push(temp->right);
    }
  }

  Node *deepest = temp;
  if (target != NULL) {
    target->data = deepest->data;
    deleteDeepest(root, deepest);
  }
}

// Build BST
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

// Diameter of Tree
int diameter = 0;

int height(Node *root) {
  if (root == NULL)
    return 0;

  int leftDia = height(root->left);
  int rightDia = height(root->right);

  diameter = max(diameter, leftDia + rightDia + 1);

  return 1 + max(leftDia, rightDia);
}

// Lowest Common Anscestor
Node *lca(Node *root, int p, int q) {
  if (root == NULL)
    return NULL;

  if (root->data == p || root->data == q)
    return root;

  Node *left = lca(root->left, p, q);
  Node *right = lca(root->right, p, q);

  if (left && right)
    return root;

  if (left != NULL)
    return left;

  return right;
}

// Spiral Order
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

      if (temp->right != NULL)
        s1.push(temp->right);

      if (temp->left != NULL)
        s1.push(temp->left);
    }
  }
}

// Level Order Traversal
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

// Boundary Traversal
bool isLeaf(Node *root) { return root->left == NULL && root->right == NULL; }

void printLeft(Node *root) {
  if (root == NULL || isLeaf(root))
    return;
  cout << root->data << " ";

  if (root->left) {
    printLeft(root->left);
  } else {
    printLeft(root->right);
  }
}

void printLeaves(Node *root) {
  if (root == NULL)
    return;

  printLeaves(root->left);
  if (isLeaf(root)) {
    cout << root->data << " ";
  }
  printLeaves(root->right);
}

void printRight(Node *root) {
  if (root == NULL || isLeaf(root))
    return;

  if (root->right) {
    printRight(root->right);
  } else {
    printRight(root->left);
  }
  cout << root->data << " ";
}

void BoundaryTraversal(Node *root) {
  if (root == NULL)
    return;

  cout << root->data << " ";
  printLeft(root->left);

  printLeaves(root->left);
  printLeaves(root->right);

  printRight(root->right);
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

  height(root);

  cout << " Tree Diameter is : " << diameter << " ";

  return 0;
}