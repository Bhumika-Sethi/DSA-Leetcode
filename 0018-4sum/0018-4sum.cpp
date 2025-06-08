class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Better approach - TC - O(N^3)
        //                      - SC - O(No of quadruplet*4) + O(No of quadruplet*4)
        // Use set to remove one loop -> store elements between j and k in the set
        // In the j loop create set 
        // At the end-:last line of k loop -> add k into set
        // return an array of all the unique quadruplets -use set to store unique quad -> sort each quad to make it unique
        // 4th variable nums[l] = target-(nums[i]+nums[j]+nums[k])
        set<vector<int>> nonDuplicateQuadSet;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                // long long to maintain overflow as in set st we are storing 4th element which can overflow
                set<long long> st;
                for(int k = j+1; k<n; k++){
                    // To prevent overflow, intialise fourth variable as long long ans subtract one by one
                    long long fourthNum = target;
                    fourthNum -= nums[i];
                    fourthNum -= nums[j];
                    fourthNum -= nums[k];
                    // Ensure st is not empty and has fourthNum stored in it
                    if(!st.empty() && st.find(fourthNum)!=st.end()){
                        // If yes then store the sorted quaduplet in a set to maintain uniqueness
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(fourthNum);
                        // Sort and then insert in set to maintain uniqueness
                        sort(temp.begin(),temp.end());
                        nonDuplicateQuadSet.insert(temp);
                    }
                    st.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(nonDuplicateQuadSet.begin(),nonDuplicateQuadSet.end());
        return ans;
    }
};