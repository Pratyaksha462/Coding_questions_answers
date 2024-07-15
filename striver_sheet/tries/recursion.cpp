#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

// Insertion Implementation
class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }
    void InsertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // all word will be in caps
        int index = word[0] - 'A';
        TrieNode *child;
        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        { // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // recursion
        InsertUtil(child, word.substr(1));
    }
    void InsertNode(string word)
    {
        InsertUtil(root, word);
    }
    bool SearchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return SearchUtil(child, word.substr(1));
    }
    bool searchWord(string word)
    {
        return SearchUtil(root, word);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    Trie *t = new Trie();
    t->InsertNode("abcd");
    cout << "Present" << t->searchWord("abcd") << endl;
    return 0;
}