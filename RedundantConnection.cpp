//leecode 684
//使用DSU判断图是否有环。

class DSU {
public:
    vector<int> parent; //parent[x]表示x的根结点
    vector<int> rank; //rank[x]表示x的排名，如果x是根结点，排名会升高
    
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;++i) {
            parent[i]=i;
            rank[i]=0;
        }
    }
    
    int find(int x) { //查找x结点的根结点
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    
    bool merge(int x,int y) { //将x所属的结点集与y所属的结点集，合并
        int px=find(x),py=find(y);
        if(px==py) return false; //x和y的根结点一致，则说明x,y已经在一个集合中，仍然对x与y连接边，说明存在环
        if(rank[px]<rank[py]) { //py的排名高，说明py更合适当根结点
            parent[px]=py;
        }
        else if(rank[px]>rank[py]) { //px的排名高，说明px更合适当根结点
            parent[py]=px;
        }
        else{ //两个排名一致，那么px和py均可以当根结点，比如px当根结点后，需要将px的排名上升
            parent[py]=px;
            ++rank[px];
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU d(edges.size()+1);
        
        for(int i=0;i<edges.size();++i) {
            if (!d.merge(edges[i][0],edges[i][1])) return edges[i];
        }
        return vector<int>(2,0);
    }
};
