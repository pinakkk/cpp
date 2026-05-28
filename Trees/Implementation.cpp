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

// Insert in tree
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

    // Check Left
    if (temp->left == NULL) {
      temp->left = newNode;
      return;
    } else {
      q.push(temp->left);
    }

    // Check Right
    if (temp->right == NULL) {
      temp->right = newNode;
      return;
    } else {
      q.push(temp->right);
    }
  }
}

// Level Order Traversal

void levelOrder(Node *root) {
  if (root == NULL)
    return;

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

void preorder(Node *root) {
  if (root == NULL)
    return;

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(Node *root) {
  if (root == NULL)
    return;

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void postorder(Node *root) {
  if (root == NULL)
    return;

  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

void inorderWithoutRecursion(Node *root) {
  stack<Node *> st;
  Node *current = root;

  while (current != NULL || !st.empty()) {

    // Go left as much
    while (current != NULL) {
      st.push(current);
      current = current->left;
    }

    // Process Node
    current = st.top();
    st.pop();
    cout << current->data << " ";

    current = current->right;
  }
}

int main() {
  Node *root = NULL;

  insert(root, 1);
  insert(root, 2);
  insert(root, 3);
  insert(root, 4);
  insert(root, 5);
  insert(root, 6);

  cout << "Before Deletion:\n";
  levelOrder(root);
  cout << endl;

  deleteNode(root, 2);

  cout << "After Deletion:\n";
  levelOrder(root);
  cout << endl;

  cout << "Preorder Traversal:\n";
  preorder(root);
  cout << endl;

  cout << "Inorder Traversal:\n";
  inorder(root);
  cout << endl;

  cout << "Inorder Traversal without recursion:\n";
  inorderWithoutRecursion(root);
  cout << endl;

  cout << "Postorder Traversal:\n";
  postorder(root);
  cout << endl;
  return 0;
}