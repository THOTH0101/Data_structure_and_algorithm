#include <bits/stdc++.h>

#include <exception>

#include "PhoneHashTable.h"
using namespace std;

// function definition
int hash_num(int value, int n_ = 65407);
int hash_string(string str, int n = 65407);
int hash_string_lower_upper_digits(string str, int n_ = 65407);
int hash_string_folding(string str, int n_ = 65407);
int count_unique_substrings(const string& str);
int count_substrings_match(const string& str1, const string& str2);

struct SomeObject {
  const static int INTERNAL_LIMIT = 2147483647;
  string str1, str2;
  int number;

  // Convert all 3 elements as a hash value
  int hash() {
    // Adding both can result in overflow. Use long long
    long long res = hash_string_lower_upper_digits(str1 + str2, INTERNAL_LIMIT);
    res += hash_num(number, INTERNAL_LIMIT);
    return res % INTERNAL_LIMIT;
  }
};

string to_str(int val) {
  ostringstream oss;
  oss << val;
  return oss.str();
}

int main() {
  cout << "Hash folding for aabcdefgAxT334gfg: "
       << hash_string_folding("aabcdefgAxT334gfg") << endl;
  cout << "Unique substrings count: " << count_unique_substrings("aaab")
       << "\n";  // 7
  cout << "Unique substrings count: " << count_unique_substrings("aaaaa")
       << "\n";  // 5
  cout << "Unique substrings count: " << count_unique_substrings("aaaba")
       << "\n";  // 11
  cout << "Unique substrings count: " << count_unique_substrings("abcdef")
       << "\n";  // 21
  cout << "Common substrings:" << endl;
  cout << count_substrings_match("aaab", "aa") << "\n";      // 2
  cout << count_substrings_match("aaab", "ab") << "\n";      // 3
  cout << count_substrings_match("aaaaa", "xy") << "\n";     // 0
  cout << count_substrings_match("aaaaa", "aaaaa") << "\n";  // 5

  // try {
  //   PhoneHashTable table;
  //
  //   for (int i = 0; i < 100; ++i) {
  //     table.put(PhoneEntry(to_str(i), to_str(i * 10)));
  //   }
  // } catch (exception& ex) {
  //   cout << ex.what() << endl;
  // }

  return 0;
}

// function implementation
int hash_num(int value, int n_) {
  long long n = n_;
  return (value % n + n) % n;
}

int hash_string(string str, int n) {
  long long nn = n;
  long long sum = 0;
  for (int i = 0; i < (int)str.size(); ++i)
    sum = (sum * 26 + str[i] - 'a') % nn;
  return sum % nn;
}

int hash_string_lower_upper_digits(string str, int n_) {
  int base = 2 * 26 + 10;  // lower, upper and 10 digits
  long long n = n_;
  long long sum = 0;

  for (int i = 0; i < (int)str.size(); ++i) {
    // lowers from [0-25], upper [26-51] and digits [52-61]
    int value = 0;
    if (islower(str[i]))
      value = str[i] - 'a';
    else if (isupper(str[i]))
      value = 26 + str[i] - 'A';
    else if (isdigit(str[i]))
      value = 26 + 26 + str[i] - '0';
    else
      assert(false);
    sum = sum * base + value;  // base 26 number
    sum %= n;                  // reduce to minimize overflows
  }
  return sum;
}

int hash_string_folding(string str, int n_) {
  long long n = n_;
  long long sum = 0;
  for (int i = 0; i < (int)str.size(); i += 4) {
    string block = str.substr(i, 4);
    sum += hash_string_lower_upper_digits(block);
    sum %= n;
  }
  return sum;
}

int count_unique_substrings(const string& str) {
  // O(L^3)
  // Try all possible substrings (L^2) and insert in hashset
  // Hashing a string is typically O(L)

  unordered_set<string> s;
  // List all substrings and add to the set
  for (int start = 0; start < (int)str.size(); ++start) {
    for (int end = start; end < (int)str.size(); ++end) {
      // cout<<str.substr(start, end - start + 1)<<", ";
      s.insert(str.substr(start, end - start + 1));
    }
  }

  return s.size();  // unique elements
                    // Note: Using a trie: we can efficiently solve it in O(L^2)
                    // Don't create the string and add to trie
  // For every stating position: let the second loop keep inserting
  // In trie letter by letter and mark as leaf
  // Hence overall only 2 loops
}

int count_substrings_match(const string& str1, const string& str2) {
  // Add all substrings
  unordered_set<string> s1;
  for (int start = 0; start < (int)str1.size(); ++start) {
    for (int end = start; end < (int)str1.size(); ++end) {
      s1.insert(str1.substr(start, end - start + 1));
    }
  }

  unordered_set<string> s2;
  for (int start = 0; start < (int)str2.size(); ++start) {
    for (int end = start; end < (int)str2.size(); ++end) {
      s2.insert(str2.substr(start, end - start + 1));
    }
  }
  int cnt = 0;
  for (string str : s1) cnt += s2.count(str);

  return cnt;
}
