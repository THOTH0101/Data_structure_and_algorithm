#include <bits/stdc++.h>

#include "Trie.h"
#include "TrieStr.h"
using namespace std;

void test();
void test1();
void test2();
void test3();
void test4();
void test5();

int main() {
  // test();
  // test1();
  // test2();
  // test3();
  test4();
  test5();

  return 0;
}

void test() {
  cout << "------- start test -------" << endl;
  trie root;

  root.insert("xyz");
  root.insert("xyzwfe");

  cout << root.first_word_prefix("xyzee") << "\n";
  cout << "------- end test -------" << endl << endl;
}
void test1() {
  cout << "------- start test -------" << endl;
  trie root;

  root.insert_rev("abcd");
  root.insert_rev("xyz");
  root.insert_rev("abf");
  root.insert_rev("xn");
  root.insert_rev("ab");
  root.insert_rev("bcd");

  cout << "is \"cd\" suffix of root: " << boolalpha << root.suffix_exist("cd")
       << "\n";
  cout << "is \"cc\" suffix of root: " << boolalpha << root.suffix_exist("cc")
       << "\n";
  cout << "------- end test -------" << endl << endl;
}
void test2() {
  cout << "------- start test -------" << endl;
  TrieStr tree;

  vector<string> path;

  path = {"home", "software", "eclipse"};
  tree.insert(path);

  path = {"home", "software", "eclipse", "bin"};
  tree.insert(path);

  path = {"home", "installed", "gnu"};
  tree.insert(path);

  path = {"user", "mostafa", "tmp"};
  tree.insert(path);

  path = {"user", "mostafa", "tmp"};
  cout << "is path a subpath: " << tree.subpath_exist(path) << "\n";  // 1

  path = {"user", "mostafa"};
  cout << "is path a subpath: " << tree.subpath_exist(path) << "\n";  // 1

  path = {"user", "mostafa", "private"};
  cout << "is path a subpath: " << tree.subpath_exist(path) << "\n";  // 0
  cout << "------- end test -------" << endl << endl;
}

void test3() {
  cout << "------- start test -------" << endl;
  trie tree;

  tree.insert("abcd");
  tree.insert("xyz");
  tree.insert("a");
  tree.insert("ab");
  tree.insert("xyzw");
  tree.insert("bcd");

  vector<string> res;
  tree.get_all_strings(res);
  for (int i = 0; i < (int)res.size(); ++i) cout << res[i] << "\n";
  cout << "------- end test -------" << endl << endl;
}

void test4() {
  cout << "------- start test -------" << endl;
  trie tree;

  tree.insert("abcd");
  tree.insert("ab");
  tree.insert("abx");
  tree.insert("abyz");
  tree.insert("xyz");
  tree.insert("a");
  tree.insert("bcd");

  vector<string> res;
  tree.auto_complete("ab", res);
  for (int i = 0; i < (int)res.size(); ++i) cout << res[i] << "\n";
  cout << "------- end test -------" << endl << endl;
}

void test5() {
  cout << "------- start test -------" << endl;
  vector<string> queries{"xy", "ab", "t", "yz"};
  list_substrs("heyabcdtwxyw", queries);
  cout << "------- end test -------" << endl << endl;
}
