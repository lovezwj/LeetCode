class Solution {
public:
    int countSubstrings(string s) {
        #Manacher algorithm to find palindromic substring.
        string new_s = "$#";
        for (int i = 0; i < s.length(); ++i) {
            new_s += s[i];
            new_s += "#";
        }
        vector<int> dp(new_s.length() + 1, 0);
        int center = 0, right = 0;
        for (int i = 0; i < new_s.length(); ++i) {
            if (i < right) {
                dp[i] = min(dp[2*center - i],right-i);
            }
            while(new_s[i-dp[i]]==new_s[i+dp[i]]) ++dp[i];
            if (i + dp[i] > right) {
                right = i + dp[i];
                center = i;
            }
        }
        //If we want to get the maximum of palindromic substring, we can get:
        int max_len = 0;
        for (int i = 0; i < dp.size(); ++i) {
          if (max_len < dp[i]) max_len = dp[i] - 1;
        }
        //cout<<new_s<<endl;
        //for(int i = 0; i < dp.size(); ++i) cout<<dp[i]<<endl;
        int res = 0;
        for (int i = 0; i < dp.size(); ++i) {
            res += (dp[i]) / 2;
        }
        return res;
    }
};
