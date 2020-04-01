struct Discretization
{
    vector<int>v;
    void init(){v.clear();}
    void insert(int x){v.push_back(x);}
    void sortV(){sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());}
    int getPos(int x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
    int getVal(int pos){return v[pos-1];}
    int getSize(){return v.size();}
}D;