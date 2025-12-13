class Solution {
public:
const int MOD = 1e9 + 7;
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

       vector<long long> next(m+1, 0), curr(m+1, 0);
        next[m] = 1;

        for (int i = n-1; i >= 0; i--) {
            curr[m] = 1;
            for (int j = m-1; j >= 0; j--) {
                long long notPick = next[j];
                long long pick = (s[i] == t[j]) ? next[j+1] : 0;
                curr[j] = (pick + notPick) % MOD;
            }
            next = curr;
        }

        return next[0];
    }
};
