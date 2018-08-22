class TrieNode {
public:
    string word;
    TrieNode * children[26];
    
    TrieNode()
    {
        this->word = "";
        memset(this->children, 0, sizeof(TrieNode*)*26);
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode *root = build_tree(dict);
        string cur_word = "", res = "";
        for (int i = 0; i < sentence.length(); ++i) {
            if(sentence[i] == ' ') {
                if (cur_word != "") {
                    res += find_root(cur_word, root) + " ";
                }
                cur_word = "";
            }
            else cur_word += sentence[i];
        }
        if(cur_word != "") res += find_root(cur_word, root);
        return res;
    }
    
    string find_root(string successor, TrieNode * root) {
        TrieNode * cur = root;
        for(int i = 0; i < successor.length(); ++i) {
            char a = successor[i];
            if(cur->children[a-'a']==NULL)
                return successor;
            else {
                cur = cur->children[a-'a'];
                #cout<<cur->word<<"\t"<<successor<<endl;
                if (cur->word != "") return cur->word;
            }
        }
        return successor;
    }
    
    TrieNode* build_tree(vector<string> & dict) {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < dict.size(); ++i) {
            TrieNode* cur = root;
            for(int j = 0; j < dict[i].length(); ++j) {
                char a = dict[i][j];
                if (cur->children[a-'a'] == NULL) {
                    cur->children[a-'a'] = new TrieNode();
                }
                cur = cur->children[a-'a'];
            }
            cur->word = dict[i];
            #cout<<cur->word<<endl;
        }
        return root;
    }
};
