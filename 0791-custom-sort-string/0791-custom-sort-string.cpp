class Solution {
public:
    inline static vector<int> rank;
    static bool charComp(char a, char b){
        return rank[a-'a'] < rank[b-'a'];
    }
    string customSortString(string order, string s) {
        rank.assign(26,100);
        for(int i = 0; i<order.size(); i++){
            rank[order[i]-'a'] = i;
        }

        sort(s.begin(),s.end(),charComp);
        return s;
    }
};