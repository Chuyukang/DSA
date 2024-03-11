#include <algorithm>
#include <string>
#include <string_view>
#include <vector>

using std::string;
using std::string_view;
using std::vector;

class Trie {
public:
    Trie();

    ~Trie();

    void insert(string_view word);

    bool contains(string_view word);

    string longestPrefix(string_view word);
private:
    struct TrieNode {
        TrieNode() : value_('\0') {}

        explicit TrieNode(char value) : value_(value) {}

        ~TrieNode() {
            for (auto child: children_) {
                delete child;
            }
        }

        char value_;
        vector<TrieNode *> children_;
    };

    TrieNode *root_;
};
