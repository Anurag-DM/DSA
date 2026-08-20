/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

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

class Trie
{

public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(string &word, int i, TrieNode *root)
    {
        if (i == word.length())
        {
            root->isTerminal = true;
            return;
        }

        int index = word[i] - 'a';
        TrieNode *child;

        if (root->children[index])
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[i]);
            root->children[index] = child;
        }

        insertUtil(word, i + 1, child);
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        insertUtil(word, 0, root);
    }

    bool searchUtil(string &word, int i, TrieNode *root)
    {
        if (i == word.length())
            return root->isTerminal;

        int index = word[i] - 'a';

        if (root->children[index])
            return searchUtil(word, i + 1, root->children[index]);
        else
            return false;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        return searchUtil(word, 0, root);
    }

    bool startsWithUtil(string &prefix, int i, TrieNode *root)
    {
        if (i == prefix.length())
            return true;

        int index = prefix[i] - 'a';
        TrieNode *child = root->children[index];

        if (child)
            return startsWithUtil(prefix, i + 1, child);

        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return startsWithUtil(prefix, 0, root);
    }
};