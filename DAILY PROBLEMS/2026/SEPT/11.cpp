// 3483. Unique 3-Digit Even Numbers
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for(int i:digits){
            freq[i]++;
        }

        int distinctDigits = 0; 

        for(int i = 0; i< 10; i++){
            if(freq[i] > 0)
                distinctDigits++;
        }

        int ans = 0;

        for(int i = 0; i<9; i += 2){ //i indicates the last digit

            if(freq[i] == 0)
                continue;

            freq[i]--;

            for(int first = 1; first <= 9; first++){
                if(freq[first] == 0)
                    continue;
                
                freq[first]--;

                for(int second = 0; second <= 9; second++){
                    if(freq[second] > 0)
                        ans++;
                }

                freq[first]++;
            }

            freq[i]++;
        }

        return ans;

    }
};