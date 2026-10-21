// 3863. Minimum Operations to Sort a String
// Time : O(n) where n is length of string
// Space : O(1)
class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        vector<int> freq(26, 0);

        bool start = false; // true will indicate start character needs to be moved
        bool end = false; // true will indicate end character needs to be moved

        char smallest = 'z';
        char largest = 'a';

        for(char c : s){
            freq[c - 'a']++;

            if(c > largest)
                largest = c;
            
            if(c < smallest)
                smallest = c;
        }

        if(s[0] != smallest)
            start = true;
        
        if(s[n-1] != largest)
            end = true;
        
        if(start && end){
            if(s.length() == 2)
                return -1;
            
            if(s[n-1] == smallest && freq[smallest - 'a'] == 1 && s[0] == largest && freq[largest - 'a'] == 1)
                return 3;
            
            return 2;
        }
        else if(start || end){
            return 1;
        }
        else{
            for(int i = 0; i<n-1; i++){
                if(s[i] > s[i+1])
                    return 1;
            }

            return 0;
        }
        

    }
};