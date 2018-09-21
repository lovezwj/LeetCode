// leetcode 680
//判断一个字符串是否为回文（注意：字符串允许删除一个字符），比如：abca是回文（因为可以删除b或者c）


class Solution {
public:
    bool isPalindrome(string & s, int start, int end) {
        int i = start, j = end;
        while(i<j) {
            if(s[i]!=s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
    bool validPalindrome(string s) {
        for(int i = 0; i < s.length()/2; ++i) {
            if(s[i]!=s[s.length()-1-i]) {
                return isPalindrome(s, i+1, s.length()-1-i) || isPalindrome(s, i, s.length()-2-i);
            }
        }
        return true;
    }
};
