# Leetcode 677
# 使用Trie树来快速保存前缀子串的和
class Trie{
public:
    char c;
    bool isLeaf;
    int value;
    unordered_map<char, Trie*> nodes;
public:
    Trie() {
        this->c = ' ';
        this->isLeaf = false;
        this->value = 0;
    }
    
    Trie(char k) {
        this->c = k;
        this->isLeaf = false;
        this->value = 0;
    }
};

class MapSum {
public:
    /** Initialize your data structure here. */
    Trie* root;
    set<string> words;
    MapSum() {
        root=new Trie();
    }
    
    void insert(string key, int val) {
        bool has_flag = false; //需要这个变量，如果之前已经存了key，那么key这条路径中所有值均变为val，而非+val。
        auto ind = words.find(key);
        if(ind != words.end()) has_flag = true;
        else words.insert(key);
        Trie* cur = root;
        for(int i=0; i<key.length(); ++i) {
            char k = key[i];
            unordered_map<char, Trie*> & curNodes = cur->nodes;
            auto ind = curNodes.find(k);
            if(ind == curNodes.end()) {
                curNodes[k] = new Trie(k);
                cur = curNodes[k];
                cur->value = val;
            }
            else { 
                cur = ind->second;
                if(!has_flag)
                    cur->value += val;
                else cur->value = val;
            }
        }
        cur->isLeaf = true;
    }
    
    int sum(string prefix) {
        Trie* cur = root;
        for(int i = 0; i < prefix.length(); ++i) {
            char k = prefix[i];
            unordered_map<char, Trie*> curNodes = cur->nodes;
            auto ind = curNodes.find(k);
            if(ind == curNodes.end()) return 0;
            else {
                cur = ind->second;
            }
        }
        return cur->value;
    }
};



/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
