class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int r=mat.size();
        for(int i=0;i<r;i++){
            int indr=0;
            for(int j=0;j<r;j++){
                if(i!=j && mat[i][j]==1){
                    indr=1;
                    break;
                }
            }
            if(indr==0){
                for(int j=0;j<r;j++){
                    if(mat[j][i]==0){
                        indr=1;
                        break;
                    }
                }
            }
            if(indr==0)
                return i;
            
        }
        return -1;
    }
};