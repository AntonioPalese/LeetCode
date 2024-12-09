#include <iostream>
#include <string>
#include <unordered_map>

class TrieNode {
public:
    bool isEnd;
    std::unordered_map<char, TrieNode*> children;

    TrieNode() : isEnd(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->isEnd;
    }

    bool startsWith(const std::string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    std::cout << (trie.search("apple") ? "true" : "false") << std::endl;
    std::cout << (trie.search("app") ? "true" : "false") << std::endl;
    std::cout << (trie.startsWith("app") ? "true" : "false") << std::endl;
    trie.insert("app");
    std::cout << (trie.search("app") ? "true" : "false") << std::endl;
    return 0;
}