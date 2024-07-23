#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <bits/stdc++.h>

#include <algorithm>
#include <cctype>
#include <deque>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
using namespace std;

template <typename T>
class BinaryTree {
 private:
  struct Node {
    T data{};
    Node *left{};
    Node *right{};

    Node(int data) { this->data = data; }
  };
  Node *root;

  /******** Helper function *********/
  void print_inorder(Node *cur) {
    if (!cur) return;

    print_inorder(cur->left);
    cout << cur->data << " ";
    print_inorder(cur->right);
  }

  void print_preorder(Node *cur) {
    if (!cur) return;

    cout << cur->data << " ";
    print_preorder(cur->left);
    print_preorder(cur->right);
  }

  void print_reverse_preorder(Node *cur) {
    if (!cur) return;

    cout << cur->data << " ";
    print_reverse_preorder(cur->right);
    print_reverse_preorder(cur->left);
  }

  void print_postorder(Node *cur) {
    if (!cur) return;

    print_postorder(cur->left);
    print_postorder(cur->right);
    cout << cur->data << " ";
  }

  int tree_max(Node *cur) {
    int res = cur->data;

    if (cur->left) res = max(res, tree_max(cur->left));

    if (cur->right) res = max(res, tree_max(cur->right));

    return res;
  }

  int tree_height(Node *cur) {
    int res = 0;

    if (cur->left) res = 1 + tree_height(cur->left);

    if (cur->right) res = max(res, 1 + tree_height(cur->right));

    return res;
  }

  int total_nodes(Node *cur) {
    int sum = 1;

    if (cur->left) sum += total_nodes(cur->left);

    if (cur->right) sum += total_nodes(cur->right);

    return sum;
  }

  int count_leaf(Node *cur) {
    int res = !cur->left && !cur->right;

    if (cur->left) res += count_leaf(cur->left);

    if (cur->right) res += count_leaf(cur->right);

    return res;
  }

  bool is_exists(int key, Node *cur) {
    bool res = cur->data == key;

    if (!res && cur->left) res = is_exists(key, cur->left);

    if (!res && cur->right) res = is_exists(key, cur->right);

    return res;
  }

  bool is_perfect(Node *cur, int h = -1) {
    if (h == -1) h = tree_height(cur);

    // check the leaf node to leaf node
    if (!cur->left && !cur->right) return h == 0;

    // node with one child is not a perfect tree
    if (!cur->left && cur->right || !cur->right && cur->left) return false;

    return is_perfect(cur->left, h - 1) && is_perfect(cur->right, h - 1);
  }

  void traverse_left_boundry(Node *cur) {
    if (!cur) return;

    cout << cur->data << " ";

    // if there's no left then go right
    if (!cur->left) traverse_left_boundry(cur->right);
    traverse_left_boundry(cur->left);
  }

  // https://leetcode.com/problems/diameter-of-binary-tree
  pair<int, int> tree_diameter(Node *cur) {
    pair<int, int> res = make_pair(0, 0);

    if (!cur->left && !cur->right) return res;

    pair<int, int> left_diam = make_pair(0, 0);
    pair<int, int> right_diam = make_pair(0, 0);

    if (cur->left)
      left_diam = tree_diameter(cur->left), res.first += 1 + left_diam.second;

    if (cur->right)
      right_diam = tree_diameter(cur->right),
      res.first += 1 + right_diam.second;

    // diameter of the tree
    res.first = max(res.first, max(left_diam.first, right_diam.first));

    // height of the tree
    res.second = 1 + max(left_diam.second, right_diam.second);

    return res;
  }

  bool is_just_num(Node *cur) { return !cur->left && !cur->right; }

  void print_inorder_expression(Node *cur) {
    if (cur->left) {
      if (!is_just_num(cur->left)) cout << '(';

      print_inorder_expression(cur->left);

      if (!is_just_num(cur->left)) cout << ')';
    }

    cout << cur->data << " ";

    if (cur->right) {
      if (!is_just_num(cur->right)) cout << '(';

      print_inorder_expression(cur->right);

      if (!is_just_num(cur->right)) cout << ')';
    }
  }

  void print_node_level(int level, Node *cur) {
    if (level == 0)
      cout << cur->data << " ";

    else if (level) {
      if (cur->left) print_node_level(level - 1, cur->left);

      if (cur->right) print_node_level(level - 1, cur->right);
    }
  }

  void add(deque<int> &preorder, deque<int> &inorder, Node *cur,
           int inorder_start = 0, int inorder_end = -1) {
    if (inorder_end == -1) inorder_end = (int)inorder.size() - 1;

    // next preorder is the current root
    cur->data = preorder[0];  // change the dummy value to data
    preorder.pop_front();

    // Find where is this root in the inorder current sequence
    for (int split = inorder_start; split <= inorder_end; split++) {
      if (inorder[split] == cur->data) {
        if (inorder_start < split) {
          cur->left = new Node(0);
          add(preorder, inorder, cur->left, inorder_start, split - 1);
        }

        if (split < inorder_end) {
          cur->right = new Node(0);
          add(preorder, inorder, cur->right, split + 1, inorder_end);
        }
        return;
      }
    }
  }

  void add(queue<pair<int, int>> &preorder_queue, Node *cur) {
    pair<int, int> pre = preorder_queue.front();
    preorder_queue.pop();

    cur->data = pre.first;

    if (!pre.second) {
      if (preorder_queue.size()) {
        cur->left = new Node(0);
        add(preorder_queue, cur->left);
      }

      if (preorder_queue.size()) {
        cur->right = new Node(0);
        add(preorder_queue, cur->right);
      }
    }
  }

  string toStr(int n) {
    // Convert integer to string
    ostringstream oss;
    oss << n;
    return oss.str();
  }

  string parenthesize(vector<string> &all_repres, Node *cur) {
    // save the representation of every subtree
    string repr = "(" + toStr(cur->data);

    if (cur->left)
      repr += parenthesize(all_repres, cur->left);
    else
      repr += "()";

    if (cur->right)
      repr += parenthesize(all_repres, cur->right);
    else
      repr += "()";
    repr += ")";

    if (cur->left || cur->right)  // nodes > 1
      all_repres.push_back(repr);

    return repr;
  }

  string parenthesize_canonical(Node *cur) {
    string repr = "(" + toStr(cur->data);

    vector<string> v;

    if (cur->left)
      v.push_back(parenthesize_canonical(cur->left));
    else
      v.push_back("()");

    if (cur->right)
      v.push_back(parenthesize_canonical(cur->right));
    else
      v.push_back("()");

    sort(v.begin(), v.end());

    for (int i = 0; i < (int)v.size(); ++i) repr += v[i];

    repr += ")";

    return repr;
  }

  bool is_mirror(Node *first, Node *second) {
    if (!first && !second) return true;

    if (!first && second || first && !second || first->data != second->data)
      return false;  // one subtree only or different values

    // 2 trees will have 4 sub-trees. We need to make sure of 2 mirroring
    return is_mirror(first->left, second->right) &&
           is_mirror(first->right, second->left);
  }

 public:
  BinaryTree(int data) { root = new Node(data); }

  /******** Binary tree constructor ********/
  BinaryTree(string postfix) {
    stack<Node *> tree;

    for (int i = 0; i < (int)postfix.size(); i++) {
      Node *cur = new Node(postfix[i]);

      if (!isdigit(postfix[i])) {
        cur->right = tree.top();
        tree.pop();
        cur->left = tree.top();
        tree.pop();
      }
      tree.push(cur);
    }

    root = tree.top();
  }

  BinaryTree(deque<int> &preorder, deque<int> &inorder) {
    root = new Node(0);  // initialize with a dummy value
    add(preorder, inorder, root);
  }

  BinaryTree(queue<pair<int, int>> &preorder_queue) {
    root = new Node(0);
    add(preorder_queue, root);
  }

  /******** Binary tree destroyer ********/
  ~BinaryTree() { clear(); }

  void clear() {
    if (root->left) {
      delete root->left;
      root->left = nullptr;
    }

    if (root->right) {
      delete root->right;
      root->left = root->right;
    }
  }

  /******** Binary tree printer ********/
  void print_inorder() {
    if (!root) cout << "tree is empty!" << endl;
    print_inorder(root);
    cout << endl;
  }

  void print_preorder() {
    if (!root) cout << "tree is empty!" << endl;
    print_preorder(root);
    cout << endl;
  }

  void print_reverse_preorder() {
    print_reverse_preorder(root);
    cout << endl;
  }

  void print_postorder() {
    if (!root) cout << "tree is empty!" << endl;
    print_postorder(root);
    cout << endl;
  }

  void print_inorder_iterative() {
    if (!root) cout << "tree is empty!" << endl;

    stack<pair<Node *, bool>> nodes;

    nodes.push(make_pair(root, false));

    while (!nodes.empty()) {
      Node *current = nodes.top().first;
      bool is_done = nodes.top().second;
      nodes.pop();

      if (is_done)
        cout << current->data << " ";
      else {
        if (current->right) nodes.push(make_pair(current->right, false));

        nodes.push(make_pair(current, true));

        if (current->left) nodes.push(make_pair(current->left, false));
      }
    }

    cout << endl;
  }

  void traverse_left_boundry() {
    if (!root) throw runtime_error("tree is empty!");
    traverse_left_boundry(root);
    cout << endl;
  }

  pair<int, int> tree_diameter() {
    if (!root) throw runtime_error("tree is empty!");
    return tree_diameter(root);
  }

  void print_inorder_expression() {
    print_inorder_expression(root);
    cout << endl;
  }

  void level_order_traversal_recursive() {
    // Time complexity is n(0^2)
    int h = tree_height();  // get current tree height

    for (int level = 0; level <= h; level++) {
      cout << "Level " << level << ": ";  // print current level
      print_node_level(level, root);
      cout << endl;
    }
  }

  void level_order_traversal_spiral() {
    // allow to push to both ends for easy reverse
    deque<Node *> nodes;
    nodes.push_back(root);

    int level = 0;
    bool forward_level = true;

    while (!nodes.empty()) {
      int size = nodes.size();

      cout << "Level " << level << ": ";  // print current level
      while (size--) {
        Node *cur;

        if (forward_level) {
          // print node level in normal
          cur = nodes.front();
          nodes.pop_front();

          if (cur->left) nodes.push_back(cur->left);

          if (cur->right) nodes.push_back(cur->right);
        } else {
          // print node level in reverse
          cur = nodes.back();
          nodes.pop_back();

          if (cur->right) nodes.push_front(cur->right);

          if (cur->left) nodes.push_front(cur->left);
        }

        cout << cur->data << " ";
      }

      forward_level = !forward_level;
      level++;
      cout << "\n";
    }
  }

  void level_order_traversal_sorted() {
    priority_queue<pair<int, Node *>> heaps[2];

    int flag = 0;
    heaps[flag].push(make_pair(root->data, root));

    while (!heaps[flag].empty()) {
      int sz = heaps[flag].size();

      while (sz--) {
        pair<int, Node *> cur_pair = heaps[flag].top();
        heaps[flag].pop();
        Node *cur = cur_pair.second;
        cout << cur_pair.first << " ";

        if (cur->left) heaps[!flag].push(make_pair(cur->left->data, cur->left));

        if (cur->right)
          heaps[!flag].push(make_pair(cur->right->data, cur->right));
      }
      cout << "\n";
      flag = !flag;
    }
  }

  void print_duplicate_subtrees() {
    vector<string> all_repres;
    parenthesize(all_repres, root);

    sort(all_repres.begin(), all_repres.end());
    all_repres.push_back("#");

    for (int i = 0; i < (int)all_repres.size();) {
      // Find a group of equal strings
      int j = i + 1;
      while (j < (int)all_repres.size() && all_repres[i] == all_repres[j]) j++;

      if (j > i + 1) cout << all_repres[i] << "\n";
      i = j;
    }
  }

  /******** Binary tree generator *******/
  void add(vector<int> data, vector<char> direction) {
    if (data.size() != direction.size())
      throw runtime_error("Incomplete node path!");

    Node *cur = this->root;

    for (int i = 0; i < direction.size(); i++) {
      if (direction[i] == 'L') {
        if (!cur->left)
          cur->left = new Node(data[i]);
        else if (cur->left->data != data[i])
          throw runtime_error(
              "Current node is not equal previous node in the path!");
        cur = cur->left;
      } else {
        if (!cur->right)
          cur->right = new Node(data[i]);
        else if (cur->right->data != data[i])
          throw runtime_error(
              "Current node is not equal previous node in the path!");
        cur = cur->right;
      }
    }
  }

  /******** Binary tree other function ********/
  int tree_max() {
    if (!root) throw runtime_error("tree is empty!");
    return tree_max(root);
  }

  int tree_height() {
    if (!root) throw runtime_error("tree is empty!");
    return tree_height(root);
  }

  int total_nodes() {
    if (!root) throw runtime_error("tree is empty!");
    return total_nodes(root);
  }

  int count_leaf() {
    if (!root) throw runtime_error("tree is empty!");
    return count_leaf(root);
  }

  bool is_exists(int key) {
    if (!root) throw runtime_error("tree is empty!");
    return is_exists(key, root);
  }

  bool is_perfect() {
    if (!root) throw runtime_error("tree is empty!");
    return is_perfect(root);
  }

  bool is_perfect_fomula() {
    int h = tree_height();
    int n = total_nodes();
    return pow(2, h + 1) - 1 == n;
  }

  string parenthesize_canonical() { return parenthesize_canonical(root); }

  bool is_mirror() { return is_mirror(root->left, root->right); }

  // https://leetcode.com/problems/check-completeness-of-a-binary-tree
  bool is_complete() {
    queue<Node *> nodes;
    nodes.push(root);

    // Once there is a single missing node (left before right)
    // Nothing else should be there: on this level or next level
    bool no_more_allowed = false;

    while (!nodes.empty()) {
      int size = nodes.size();

      while (size--) {
        Node *cur = nodes.front();
        nodes.pop();

        if (cur->left) {
          if (no_more_allowed) return false;

          nodes.push(cur->left);
        } else
          no_more_allowed = true;

        if (cur->right) {
          if (no_more_allowed) return false;

          nodes.push(cur->right);
        } else
          no_more_allowed = true;
      }
    }
    return true;
  }
};

#endif
