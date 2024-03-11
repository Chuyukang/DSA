#include "ds/Trie.h"

Trie::Trie() { root_ = new TrieNode(); }
Trie::~Trie() { delete root_; }

void Trie::insert(string_view word) {
  auto cur_parent = root_;

  for (auto ch : word) {
    auto itr =
        std::find_if(cur_parent->children_.begin(), cur_parent->children_.end(),
                     [ch](auto x) { return x->value_ == ch; });
    if (itr != cur_parent->children_.end()) {
      cur_parent = *itr;
    } else {
      auto *node = new TrieNode(ch);
      cur_parent->children_.push_back(node);
      cur_parent = node;
    }
  }
}

bool Trie::contains(string_view word) {
  auto cur_parent = root_;

  for (auto ch : word) {
    auto itr =
        std::find_if(cur_parent->children_.begin(), cur_parent->children_.end(),
                     [ch](auto x) { return x->value_ == ch; });
    if (itr == cur_parent->children_.end()) {
      return false;
    } else {
      cur_parent = *itr;
    }
  }

  return true;
}

string Trie::longestPrefix(string_view word) {
  auto cur_parent = root_;

  string res;
  for (auto ch : word) {
    auto itr =
        std::find_if(cur_parent->children_.begin(), cur_parent->children_.end(),
                     [ch](auto x) { return x->value_ == ch; });
    if (itr == cur_parent->children_.end()) {
      return res;
    } else {
      cur_parent = *itr;
      res.push_back((*itr)->value_);
    }
  }

  return res;
}
