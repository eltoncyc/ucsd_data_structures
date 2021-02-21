#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

#define MIN_INT  -9999999999999999998
#define MAX_INT  9999999999999999997

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool isBinarySearchTreeHelper(const vector<Node>& tree, const int& node_idx, long long  min, long long  max)
{
    if (node_idx == -1) {
        return true;
    }
    if (tree[node_idx].key < min || tree[node_idx].key >= max) {
        return false;
    }
    return isBinarySearchTreeHelper(tree, tree[node_idx].left, min, tree[node_idx].key) && isBinarySearchTreeHelper(tree, tree[node_idx].right, tree[node_idx].key, max);
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
    if (tree.size() == 0) {
        return true;
    }
    return isBinarySearchTreeHelper(tree, 0, MIN_INT, MAX_INT);
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
