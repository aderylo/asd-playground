#include <iostream>

struct Node {
  int val;
  Node *left, *right;
  Node *parent;
  Node(int v) : val(v), left(nullptr), right(nullptr), parent(nullptr) {}
};

class SplayTree {
 private:
  Node *root;

 public:
  SplayTree() : root(nullptr) {}

  void insert(int val) {
    if (!root) {
      root = new Node(val);
      return;
    }

    Node *curr = root;
    while (true) {
      if (val < curr->val) {
        if (!curr->left) {
          curr->left = new Node(val);
          curr->left->parent = curr;
          splay(curr->left);
          break;
        }
        curr = curr->left;
      } else {
        if (!curr->right) {
          curr->right = new Node(val);
          curr->right->parent = curr;
          splay(curr->right);
          break;
        }
        curr = curr->right;
      }
    }
  }

  void remove(int val) {
    Node *node = search(val);
    if (!node)
      return;
    splay(node);

    if (!node->left) {
      root = node->right;
    } else {
      Node *right = node->right;
      root = node->left;
      Node *max = maximum(root);
      splay(max);
      max->right = right;
    }

    delete node;
  }

  Node *search(int val) {
    Node *curr = root;
    while (curr) {
      if (val == curr->val) {
        splay(curr);
        return curr;
      } else if (val < curr->val) {
        curr = curr->left;
      } else {
        curr = curr->right;
      }
    }
    return nullptr;
  }

  Node *maximum(Node *node) {
    while (node->right) {
      node = node->right;
    }
    return node;
  }

  void splay(Node *node) {
    while (node != root) {
      Node *parent = node->parent;
      Node *grandParent = parent->parent;

      if (grandParent && grandParent != root) {
        if ((parent->left == node) == (grandParent->left == parent)) {
          rotate(parent);
        } else {
          rotate(node);
        }
      }

      rotate(node);
    }
  }

  void rotate(Node *node) {
    Node *parent = node->parent;
    Node *grandParent = parent->parent;

    if (parent->left == node) {
      parent->left = node->right;
      node->right = parent;

    } else {
      parent->right = node->left;
      node->left = parent;
    }

    parent->parent = node;
    if (parent->left)
      parent->left->parent = parent;
    if (parent->right)
      parent->right->parent = parent;

    node->parent = grandParent;
    if (grandParent) {
      if (grandParent->left == parent)
        grandParent->left = node;
      else
        grandParent->right = node;
    }
  }
};

int main() {
  SplayTree tree;
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(50);

  std::cout << tree.search(30)->val << std::endl;
  tree.remove(30);
  std::cout << tree.search(30) << std::endl;

  return 0;
}
