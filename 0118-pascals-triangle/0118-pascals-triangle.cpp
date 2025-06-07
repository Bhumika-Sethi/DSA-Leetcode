class Solution {
public:
    // TC for generate row = O(N)
    vector<int> generateRow(int rowNum){
        // Now for each row there are elements  = rowNumber
        vector<int> ans;
        // First number is always 1 so we'll add one and then run from 1 -> rowNum-1
        // Now notice for each element the formula is {row-1Ccol-1}-> we have 0 based indexing
        // -> So for element at index 1 and row 6th -> it is 5/2
        // -> For 2nd index, 6th row -> 5*4/2*1 -> answer*(row-i) -> answer/i
        ans.push_back(1);
        long long answer = 1;
        for(int i = 1; i<rowNum; i++){
            answer *= (rowNum-i);
            answer /= i;
            ans.push_back(answer);
        }
        return ans;
    }
    // Optimal Approach -> TC - O(N*N)
    //                 -> SC - O(1)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        // Run a loop to generate all the rows
        // As we can notice for i = 5, we have 5 rows
        for(int i = 1; i<=numRows; i++){
            // Here we will pass rowNum and the function will return row elements for generated row 
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};