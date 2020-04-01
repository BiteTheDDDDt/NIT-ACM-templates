int __builtin_ffs (unsigned int x)
返回x的最后一位1的是从后向前第几位，比如7368（1110011001000）返回4。
int __builtin_clz (unsigned int x)
返回前导的0的个数。
int __builtin_ctz (unsigned int x)
返回后面的0个个数，和__builtin_clz相对。
int __builtin_popcount (unsigned int x)
返回二进制表示中1的个数。
int __builtin_parity (unsigned int x)
返回x的奇偶校验位，也就是x的1的个数模2的结果。

此外，这些函数都有相应的usigned long和usigned long long版本，只需要在函数名后面加上l或ll就可以了，比如int __builtin_clzll。

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//随机数
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

//读入一行
getline(cin,s);

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>//用hash
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