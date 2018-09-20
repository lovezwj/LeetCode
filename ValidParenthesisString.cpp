#leetcode 678
#字符串只有(,),*，*可以表示(,)或者空。
#判断字符串是否合法。比如：()则合法，((*)合法（因为*可以看成是')'），())则非法。
class Solution {
public:
    bool checkValidString(string s) {
        int low=0,high=0;
        for(int i=0;i<s.length();++i) {
            if(s[i]=='('){
                ++low;
                ++high;
            }
            else if(s[i] == '*') {
                --low;
                ++high;
            }
            else {
                --low;
                --high;
                if(high<0) break;
            }
            if(low<0) low=0;
        }
        return low==0;
    }
};
