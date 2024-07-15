#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    bool isword;
    TrieNode *word[26];
    TrieNode()
    {
        isword = false;
        for (int i = 0; i < 26; i++)
        {
            word[i] = 0;
        }
    }
};
int count(string &s)
{
    TrieNode *root = new TrieNode();

    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        TrieNode *temp = root;
        for (int j = i; j < s.length(); j++)
        {
            if (temp->word[s[j] - 'a'] == NULL)
            {
                temp->word[s[j] - 'a'] = new TrieNode();
                temp->isword = true;
                count++;
            }
            temp = temp->word[s[j] - 'a'];
        }
    }
    return count + 1;
}

int countDistinctSubstrings(string &s)
{
    //    Write your code here.

    return count(s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        count(s);
    }
    return 0;
}