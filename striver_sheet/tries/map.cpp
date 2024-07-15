#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
class TrieNode
{
public:
    //  map<char, TrieNode *> mp;
    bool endofword;
    TrieNode() { endofword = false; }
};

class Trie
{
    TrieNode *root;

public:
    unordered_map<string, int> mp;
    // Trie() { this->root = new TrieNode(); }
    Trie()
    {
    }
    void insert(string &word) { mp[word]++; }

    int countWordsEqualTo(string &word)
    {
        if (mp.find(word) != mp.end())
            return mp[word];
        return 0;
    }
    int countWordsStartingWith(string &word)
    {
        int c = 0;
        for (auto i : mp)
        {
            string s = i.first;
            if (s.compare(0, word.size(), word) == 0)
                c += mp[s];
        }
        return c;
    }
    void erase(string &word)
    {
        mp[word]--;
        if (mp[word] == 0)
            mp.erase(word);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}