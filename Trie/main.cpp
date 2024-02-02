#include<iostream>
using namespace std;

class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;
    };

    TrieNode* root;

    TrieNode* getNode() {
        TrieNode* pNode = new TrieNode;

        pNode->isEndOfWord = false;

        for (int i = 0; i < 26; i++) {
            pNode->children[i] = nullptr;
        }

        return pNode;
    }

public:
    Trie() {
        root = getNode();
    }

    void insert(string key) {
        TrieNode* pCrawl = root;

        for (int i = 0; i < key.size(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index]) {
                pCrawl->children[index] = getNode();
            }

            pCrawl = pCrawl->children[index];
        }

        pCrawl->isEndOfWord = true;
    }

    bool search(string key) {
        TrieNode* pCrawl = root;

        for (int i = 0; i < key.size(); i++) {
            int index = key[i] - 'a';

            if (!pCrawl->children[index]) {
                return false;
            }
            pCrawl = pCrawl->children[index];
        }
        return pCrawl->isEndOfWord;
    }
};

int main() {
    Trie trie;

    string keys[] = { "the", "a", "there", "answer", "any", "by", "bye", "their" };
    int n = sizeof(keys) / sizeof(keys[0]);

    // Construct trie
    for (int i = 0; i < n; i++)
        trie.insert(keys[i]);

    // Search for different keys
    cout << "the" << " --- " << (trie.search("the") ? "Present in trie" : "Not present in trie") << endl;
    cout << "these" << " --- " << (trie.search("these") ? "Present in trie" : "Not present in trie") << endl;
    cout << "their" << " --- " << (trie.search("their") ? "Present in trie" : "Not present in trie") << endl;
    cout << "thaw" << " --- " << (trie.search("thaw") ? "Present in trie" : "Not present in trie") << endl;

    return 0;
}
