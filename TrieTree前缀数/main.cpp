#include <iostream>

/**
 *  前缀树模版
 */
using namespace std;
class TrieNode{
public:
    TrieNode* links[26];
};

class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            char currentChar = word[i];
            if (node->links[currentChar-'a'] == nullptr) {
                node->links[currentChar - 'a'] = new TrieNode();
            }
            node = node->links[currentChar - 'a'];
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for(int i = 0;i < word.length(); i++){
            char currentChar = word[i];
            if(node -> links[currentChar - 'a'] == nullptr){
                return false;
            }
            node = node->links[currentChar - 'a'];
        }
        return true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i =0 ; i < prefix.length(); i++){
            char currentChar = prefix[i];
            if(node -> links[currentChar - 'a'] == nullptr){
                return false;
            }
            node = node->links[currentChar - 'a'];
        }
        return true;
    }
};

int main() {
    Trie t;
    t.insert("askfljsfkjsd");
    bool  result = t.startsWith("asf");
    cout << result;
    return 0;
}