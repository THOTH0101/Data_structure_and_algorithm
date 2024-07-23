#ifndef TRIE
#define TRIE

#include <bits/stdc++.h>
using namespace std;

class trie {
 private:
  static const int MAX_CHAR = 26;
  trie* child[MAX_CHAR];
  bool isLeaf{};

 public:
  trie() {
    // set an array to 0s. Here pointers to null
    memset(child, 0, sizeof(child));
  }

  void insert(string str, int idx = 0) {
    if (idx == (int)str.size())
      isLeaf = 1;
    else {
      int cur = str[idx] - 'a';
      if (child[cur] == 0) child[cur] = new trie();
      child[cur]->insert(str, idx + 1);
    }
  }
  // by reversing a string, we can trivially check for suffixes!

  void insert_rev(string str) {
    reverse(str.begin(), str.end());

    trie* cur = this;

    for (int idx = 0; idx < (int)str.size(); ++idx) {
      int ch = str[idx] - 'a';
      if (!cur->child[ch]) cur->child[ch] = new trie();
      cur = cur->child[ch];
    }
    cur->isLeaf = true;
  }

  bool suffix_exist(string str) {
    reverse(str.begin(), str.end());
    trie* cur = this;

    for (int idx = 0; idx < (int)str.size(); ++idx) {
      int ch = str[idx] - 'a';
      if (!cur->child[ch]) return false;  // such path don't exist
      cur = cur->child[ch];
    }
    return true;
  }

  string first_word_prefix(const string& str) {
    trie* cur = this;

    for (int idx = 0; idx < (int)str.size(); ++idx) {
      int ch = str[idx] - 'a';
      if (!cur->child[ch]) break;

      // Does this child marked as word? we forund a prefix that is a word
      if (cur->child[ch]->isLeaf) return str.substr(0, idx + 1);
      cur = cur->child[ch];
    }
    return str;
  }

  // O(NL) where N number of words and L is word length.
  void get_all_strings(vector<string>& res, string cur_str = "") {
    if (isLeaf) res.push_back(cur_str);

    for (int i = 0; i < MAX_CHAR; ++i)
      if (child[i]) child[i]->get_all_strings(res, cur_str + (char)(i + 'a'));
  }

  void auto_complete(const string& str, vector<string>& res) {
    trie* cur = this;

    for (int idx = 0; idx < (int)str.size(); ++idx) {
      int ch = str[idx] - 'a';
      if (!cur->child[ch]) return;
      cur = cur->child[ch];
    }
    cur->get_all_strings(res, str);
  }

  void print_all_matches(const string& str, int starting_pos = 0) {
    trie* cur = this;

    for (int idx = starting_pos; idx < (int)str.size(); ++idx) {
      int ch = str[idx] - 'a';
      if (!cur->child[ch]) return;
      cur = cur->child[ch];

      if (cur->isLeaf)
        cout << str.substr(starting_pos, idx - starting_pos + 1) << "\n";
    }
  }
};

/*
 * Reverse thinking using trie.
 *
 * Add the queries themselves to the trie
 *
 * For the string, generate all its suffixes
 * For each suffix, iterate over the trie and print all words you meet.
 * These words are prefixes of this suffix ==> are sub-strings from original
 * string
 */
void list_substrs(const string& str, vector<string>& queries) {
  trie tree;

  // O(QL)
  for (int i = 0; i < (int)queries.size(); ++i) tree.insert(queries[i]);

  // O(SL): observe, we won't iterate in the tree MORE than L steps
  for (int i = 0; i < (int)str.size() - 1; ++i) tree.print_all_matches(str, i);

  // total: O(QL + SL) vs previsouly O(QL + SS)
}

#endif  // !TRIE
