int __builtin_ffs (unsigned int x)
����x�����һλ1���ǴӺ���ǰ�ڼ�λ������7368��1110011001000������4��
int __builtin_clz (unsigned int x)
����ǰ����0�ĸ�����
int __builtin_ctz (unsigned int x)
���غ����0����������__builtin_clz��ԡ�
int __builtin_popcount (unsigned int x)
���ض����Ʊ�ʾ��1�ĸ�����
int __builtin_parity (unsigned int x)
����x����żУ��λ��Ҳ����x��1�ĸ���ģ2�Ľ����

���⣬��Щ����������Ӧ��usigned long��usigned long long�汾��ֻ��Ҫ�ں������������l��ll�Ϳ����ˣ�����int __builtin_clzll��

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//�����
shuffle(a, a + n, rng);

struct cmp
{
    bool operator()(int a,int b)
    {
        return dvv[a]<dvv[b];
    }
}
priority_queue<int,vector<int>,cmp>q;

multiset<int,greater<int>>sa;

ios::sync_with_stdio(false);

//����һ��
getline(cin,s);

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>//��hash
using namespace __gnu_pbds;
cc_hash_table<long long,int>dp;
gp_hash_table<long long,int>dp;

struct pair_hash{inline size_t operator()(const pair<int,int> & p) const {return p.first*1007 + p.second;}};

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>s;
s.order_of_key(n)

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<long long, int, custom_hash> safe_map;
gp_hash_table<long long, int, custom_hash> safe_hash_table;