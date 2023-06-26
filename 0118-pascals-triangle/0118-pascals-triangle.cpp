class Solution {
    vector<int> generateRow(int row){
        vector<int> res;
        int ans = 1;
        res.push_back(ans);
        for(int i = 1; i<row; i++){
            ans *= row-i;
            ans /= i;
            res.push_back(ans);
        }
        return res;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        
        for(int i = 1; i<=numRows; i++){
            vector<int> temp = generateRow(i);
            result.push_back(temp);
        }
        return result;
    }
};