#include "ds/Trie.h"
#include "gtest/gtest.h"

TEST(TrieTest, TrieE2E) {
  Trie t;
  t.insert("a");
  t.insert("abc");

  EXPECT_TRUE(t.contains(""));

  EXPECT_TRUE(t.contains("a"));
  EXPECT_TRUE(t.contains("ab"));
  EXPECT_TRUE(t.contains("abc"));

  EXPECT_FALSE(t.contains("ac"));
  EXPECT_FALSE(t.contains("abd"));

  EXPECT_FALSE(t.contains("b"));
  EXPECT_FALSE(t.contains("bc"));
}

TEST(TrieTest, LongestPrefix) {
  Trie t;
  t.insert("abc");

  EXPECT_EQ(t.longestPrefix(""), "");

  EXPECT_EQ(t.longestPrefix("a"), "a");
  EXPECT_EQ(t.longestPrefix("ab"), "ab");
  EXPECT_EQ(t.longestPrefix("abc"), "abc");
  EXPECT_EQ(t.longestPrefix("abcd"), "abc");

  EXPECT_EQ(t.longestPrefix("b"), "");
}