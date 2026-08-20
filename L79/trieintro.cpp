#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(string &word, int i, TrieNode* root){
        if(i == word.length()){
            root->isTerminal = true;
            return;
        }

        int index = word[i] - 'a';
        TrieNode* child;

        if(root->children[index]){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[i]);
            root->children[index] = child;
        }

        insertUtil(word, i + 1, child);
    }

    void insertWord(string word){
        insertUtil(word, 0, root);
    }

    bool searchUtil(string &word, int i, TrieNode* root){
        if(i == word.length())
            return root->isTerminal;

        int index = word[i] - 'a';

        if(root->children[index])
            return searchUtil(word, i + 1, root->children[index]);
        else
            return false;
    }

    bool searchWord(string word){
        return searchUtil(word, 0, root);
    }

    bool deleteUtil(string &word, int i, TrieNode* root){

        // Word reached
        if(i == word.length()){
            root->isTerminal = false;

            // If no children, this node can be deleted
            for(int j = 0; j < 26; j++){
                if(root->children[j])
                    return false;
            }

            return true;
        }

        int index = word[i] - 'a';

        // Word doesn't exist
        if(root->children[index] == NULL)
            return false;

        TrieNode* child = root->children[index];

        bool deleteChild = deleteUtil(word, i + 1, child);

        if(deleteChild){
            delete child;
            root->children[index] = NULL;

            // Current node can also be deleted if:
            // 1. It isn't the end of another word
            // 2. It has no other children
            if(!root->isTerminal){
                for(int j = 0; j < 26; j++){
                    if(root->children[j])
                        return false;
                }

                return true;
            }
        }

        return false;
    }

    void deleteWord(string word){
        deleteUtil(word, 0, root);
    }
};

int main(){
    Trie* t = new Trie();

    t->insertWord("abcd");
    t->insertWord("abc");

    cout << t->searchWord("abcd") << endl;  // 1
    cout << t->searchWord("abc") << endl;   // 1

    t->deleteWord("abcd");

    cout << t->searchWord("abcd") << endl;  // 0
    cout << t->searchWord("abc") << endl;   // 1

    return 0;
}