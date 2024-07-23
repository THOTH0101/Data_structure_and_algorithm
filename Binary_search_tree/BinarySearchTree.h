#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

#include <bits/stdc++.h>

#include <deque>
#include <utility>
#include <vector>
using namespace std;

template <typename T>
class BinarySearchTree {
 private:
  T data{};
  BinarySearchTree* left{};
  BinarySearchTree* right{};
  BinarySearchTree* parent{};

  /***** helper function *****/
  // using post order traversal
  BinarySearchTree* build_balanced_bst_tree(vector<T>& vec, int start = 0,
                                            int end = -10) {
    if (end == -10) end = (int)vec.size() - 1;

    if (start > end) return nullptr;

    // The best root for N sorted numbers is their middle number
    // as N/2 numbers before and after. Keep applying recursively
    int mid = (start + end) / 2;
    BinarySearchTree* left = build_balanced_bst_tree(vec, start, mid - 1);
    BinarySearchTree* right = build_balanced_bst_tree(vec, mid + 1, end);
    BinarySearchTree* root = new BinarySearchTree(vec[mid], left, right);

    return root;
  }

  int min_value() {
    BinarySearchTree* cur = this;
    while (cur && cur->left) cur = cur->left;
    return cur->data;
  }

  BinarySearchTree* find(int target) {
    if (target == data) return this;

    if (target < data) {
      if (!left) return nullptr;
      return left->find(target);
    }

    if (!right) return nullptr;
    return right->find(target);
  }

  BinarySearchTree* max_node() {
    BinarySearchTree* cur = this;
    while (cur && cur->right) cur = cur->right;
    return cur;
  }

  void special_delete(BinarySearchTree* child) {
    data = child->data;
    left = child->left;
    right = child->right;
    delete child;
  }

 public:
  /***** constructors *****/
  BinarySearchTree(T data, BinarySearchTree* left = nullptr,
                   BinarySearchTree* right = nullptr) {
    this->data = data;
    this->left = left;
    this->right = right;
  }

  BinarySearchTree(BinarySearchTree* parent, T data)
      : parent(parent), data(data) {}

  BinarySearchTree(vector<T>& vec) {
    BinarySearchTree* root = build_balanced_bst_tree(vec);

    // set property
    data = root->data;
    left = root->left;
    right = root->right;
  }

  BinarySearchTree(deque<int>& preorder, int start = 0, int end = -1) {
    if (end == -1) end = (int)preorder.size() - 1;

    // next preorder is the current root
    data = preorder[start];

    // Carefully split the remaining of the preorder
    // Be careful for subrange left only case
    for (int split = start + 1; split <= end + 1; ++split) {
      if (split == end + 1 || preorder[split] > data) {
        if (start + 1 <= split - 1)  // there is a left tree
          left = new BinarySearchTree(preorder, start + 1, split - 1);

        if (split <= end) right = new BinarySearchTree(preorder, split, end);

        break;
      }
    }
  }

  /***** printer *****/
  void print_inorder() {
    if (left) left->print_inorder();

    cout << data << " ";

    if (right) right->print_inorder();
  }

  void level_order_traversal() {
    queue<BinarySearchTree*> nodes_queue;
    nodes_queue.push(this);

    int level = 0;
    while (!nodes_queue.empty()) {
      int sz = nodes_queue.size();

      cout << "Level " << level << ": ";
      while (sz--) {
        BinarySearchTree* cur = nodes_queue.front();
        nodes_queue.pop();

        cout << cur->data << " ";
        if (cur->left) nodes_queue.push(cur->left);
        if (cur->right) nodes_queue.push(cur->right);
      }
      level++;
      cout << "\n";
    }
  }

  /****** insertion *****/
  void insert(int target) {
    if (target < data) {
      if (!left)
        left = new BinarySearchTree(target);
      else
        left->insert(target);
    } else if (target > data) {
      if (!right)
        right = new BinarySearchTree(target);
      else
        right->insert(target);
    }
  }
  void insert_with_parent(int target) {
    if (target < data) {
      if (!left)
        left = new BinarySearchTree(this, target);
      else
        left->insert_with_parent(target);
    } else if (target > data) {
      if (!right)
        right = new BinarySearchTree(this, target);
      else
        right->insert_with_parent(target);
    }
  }

  /***** deletion *****/
  BinarySearchTree* delete_node(int target, BinarySearchTree* node) {
    if (!node) return nullptr;

    if (target < node->data)
      node->left = delete_node(target, node->left);
    else if (target > node->data)
      node->right = delete_node(target, node->right);
    else {
      if (!node->left && !node->right) {
        delete node;
        node = nullptr;
      } else if (!node->right)             // case 2: has left only
        node->special_delete(node->left);  // connect with child
      else if (!node->left)                // case 2: has right only
        node->special_delete(node->right);

      else {  // 2 children: Use predecessor
        BinarySearchTree* mx = node->left->max_node();
        node->data = mx->data;  // copy & go delete
        node->left = delete_node(node->data, node->left);
      }
    }
    return node;
  }

  BinarySearchTree* delete_node2(int target, BinarySearchTree* node) {
    if (!node) return nullptr;

    if (target < node->data)
      node->left = delete_node2(target, node->left);
    else if (target > node->data)
      node->right = delete_node2(target, node->right);
    else {
      // A bit changed from the video

      if (!node->left && !node->right) {
        delete node;
        node = nullptr;
      } else if (!node->right)             // case 2: has left only
        node->special_delete(node->left);  // connect with child
      else if (!node->left)                // case 2: has right only
        node->special_delete(node->right);
      else {  // 2 children: Use successor
        // Get the minimum node AND its parent
        BinarySearchTree* parent = node;
        BinarySearchTree* child = node->right;
        while (child->left) parent = child, child = child->left;

        node->data = child->data;

        // child->left must be null, but child->right might not be
        // we need to link parent to child->right
        // But link with parent->left? or parent->right?
        // Simply same as current parent-child relations
        // In details: 2 cases: either successor was directly node's right
        // Or it was deeper on chain of left nodes
        if (parent->right == child) {
          parent->right = child->right;
        } else
          parent->left = child->right;
        delete child;  // never be this in 2 children case
      }
    }
    return node;
  }

  void delete_value(int target) {
    if (target == data && !left && !right)
      return;  // can't remove root in this structure
    delete_node(target, this);
  }

  /***** search *****/
  bool search(int target) {  // tail recursion
    if (target == data) return true;

    if (target < data) return left && left->search(target);

    return right && right->search(target);
  }

  bool search_iterative(int target) {
    BinarySearchTree* cur = this;

    while (cur) {
      if (target == cur->data) return true;

      if (target < cur->data)
        cur = cur->left;
      else if (target > cur->data)
        cur = cur->right;
    }

    return false;
  }

  bool is_bst1(int mn = INT_MIN, int mx = INT_MAX) {
    bool status = mn < data && data < mx;

    if (!status) return false;

    bool left_bst = !left || left->is_bst1(mn, data);

    if (!left_bst) return false;

    bool right_bst = !right || right->is_bst1(data, mx);
    return right_bst;
  }

  bool is_bst2() {
    vector<T> values;
    get_inorder(values);

    for (int i = 0; i < (int)values.size(); i++)
      if (values[i] < values[i - 1]) return false;

    return true;
  }

  void get_inorder(vector<T>& vec) {
    if (left) left->get_inorder(vec);

    vec.push_back(data);

    if (right) right->get_inorder(vec);
  }

  // The interesting idea is doing partial inorder traversal
  // If the tree has for each node count for how many nodes in its tree
  // we can get answer in O(h)
  T kth_smallest(int& k) {
    if (k == 0) return -1234;

    if (left) {
      int res = left->kth_smallest(k);
      if (k == 0) return res;
    }

    --k;  // for current node

    if (k == 0) return data;

    if (right) return right->kth_smallest(k);

    return -1234;
  }

  int lca(int x, int y) {
    // if both on left or right subtree, then lca must be in the subtree
    // otherwise this node is lca: x is in a branch and y in another
    if (x < data && y < data) return left->lca(x, y);

    if (x > data && y > data) return right->lca(x, y);

    return data;
  }

  pair<bool, T> successor(int target) {
    BinarySearchTree* node = find(target);

    if (!node) return make_pair(false, -1);

    if (node->right) return make_pair(true, node->right->min_value());

    BinarySearchTree* parent = node->parent;
    while (parent && parent->right == node)
      node = parent, parent = node->parent;

    if (parent) return make_pair(true, parent->data);
    return make_pair(false, -1);
  }

  // Note: traversal here is incomplete inorder traversal. It will have only
  // search visited elements
  void successor_queries(deque<T>& queries, vector<T>& answer,
                         vector<T>& traversal) {
    if (queries.empty()) return;

    if (left && queries.front() < data) {
      left->successor_queries(queries, answer, traversal);

      if (queries.empty()) return;
    }

    // If the last element added in the traversal is the requested element
    // Then the current element is its successor! Catch it! That simple!
    if (!traversal.empty() && traversal.back() == queries.front()) {
      answer.push_back(data);
      queries.pop_front();

      if (queries.empty()) return;
    }
    traversal.push_back(data);

    // Observe the = : If target equal the cur data and we have right, then
    // successor on right Trace the root (e.g. 50)
    if (right && queries.front() >= data)
      right->successor_queries(queries, answer, traversal);
  }
};

template <typename T>
// non class member
bool is_degenerate(vector<T>& preorder) {
  // The more of solution: if degenerate is branch, we can compute [mn, mx]
  // per node for validation
  if (preorder.size() <= 2) return true;

  int mn = 1, mx = 1000;

  // Validate the generate branch is always fitting with updated range
  for (int i = 1; i < (int)preorder.size(); ++i) {
    if (preorder[i] < mn || preorder[i] > mx) return false;

    if (preorder[i] > preorder[i - 1])  // on its right subtree: so I am
                                        // smaller than all next
      mn = preorder[i - 1] +
           1;  // must be smaller than previous mn, we checked for interval
    else
      mx = preorder[i - 1] - 1;
  }
  return true;
  // Other approaches:
  // https://www.geeksforgeeks.org/check-if-each-internal-node-of-a-bst-has-exactly-one-child/
}

#endif  // !BINARYSEARCHTREE
