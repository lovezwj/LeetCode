class Solution {
public:
    int maximumSwap(int num) {
        int ori_num = num;
        vector<int> bits;
        while(num!=0) {
            bits.push_back(num%10);
            num/=10;
        }
        //for(int i=0;i<bits.size(); ++i) cout<<bits[i]<<endl;
        
        bool flag = false;
        for(int end = bits.size()-1; end>=1; --end) {
            flag = update_bits(bits, end);
            //cout<<flag<<"\t"<<end<<endl;
            if(flag) break;
        }
        if(!flag) return ori_num;
        //for(int i=0;i<bits.size();++i) cout<<bits[i]<<endl;
        int res = 0, mul = 1;
        for(int i = 0; i < bits.size(); ++i) {
            res += bits[i] * mul;
            mul *= 10;
        }
        return res;
    }
    
    bool update_bits(vector<int> & bits, int end) {
        int lastOne = bits[end];
        int lastOne2 = -1, index = -1;
        for(int i = 0; i < end; ++i) {
            if(bits[i] > lastOne2) {
                index = i;
                lastOne2 = bits[i];
            }
        }
        if(lastOne >= lastOne2) return false;
        bits[end] = lastOne2;
        bits[index] = lastOne;
        //for(int i=0;i<bits.size();++i) cout<<bits[i]<<endl;
        return true;
    }
};
