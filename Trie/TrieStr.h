#ifndef TRIE_STR
#define TRIE_STR

#include <bits/stdc++.h>

#include <map>
using namespace std;

class TrieStr {
 private:
  // The major change: instead of letter on edge, it will be a string
  map<string, TrieStr*> child;

  bool isLeaf{};

 public:
  TrieStr() {}

  void insert(const vector<string>& path) {
    TrieStr* cur = this;

    for (int idx = 0; idx < (int)path.size(); ++idx) {
      if (!cur->child.count(path[idx])) cur->child[path[idx]] = new TrieStr();
      cur = cur->child[path[idx]];
    }
    cur->isLeaf = true;
  }

  bool subpath_exist(const vector<string>& path) {
    TrieStr* cur = this;

    for (int idx = 0; idx < (int)path.size(); ++idx) {
      if (!cur->child.count(path[idx])) return false;  // such path don't exist
      cur = cur->child[path[idx]];
    }
    return true;
  }
};

#endif  // !TRIE_STR
