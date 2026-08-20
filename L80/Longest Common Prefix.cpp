// Time Complexity:  O(n × m)
// Space Complexity: O(1)

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    for(int i = 0; i<arr[0].length(); i++){
        char ch = arr[0][i];
        for(int j = 1; j<arr.size(); j++){
            if(arr[j].size() <= i || arr[j][i] != ch)
                return ans;
        }

        ans.push_back(ch);
    }

    return ans;
}


/*Trie solution
Time Complexity: O(n × m)
Space Complexity: O(n × m)

where n = number of strings and m = maximum length of a string.


class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char data){
        this->data = data;

        for(int i = 0; i<26; i++){
            children[i] = NULL;
        }

        childCount = 0;
        isTerminal = false;
    }
};

class Trie {

public:
    TrieNode* root;
    
    Trie() {
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
            root->childCount++;
        }

        insertUtil(word, i + 1, child);
    }

    // Inserts a word into the trie. 
    void insert(string word) {
        insertUtil(word, 0, root);
    }

    string lcpUtil(TrieNode* root, string &ans){
        if(root->childCount == 1 && !root->isTerminal){
            for(int i = 0; i<26; i++){
                if(root->children[i]){
                    TrieNode* child = root->children[i];
                    ans.push_back(child->data);
                    lcpUtil(child, ans);
                }
            }
        }

        return ans;
    }

    string lcp(){
        string ans = "";
        return lcpUtil(root, ans);
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* t = new Trie();

    for(int i = 0; i<n ; i++){
        t->insert(arr[i]);
    }

    return t->lcp();
}



*/