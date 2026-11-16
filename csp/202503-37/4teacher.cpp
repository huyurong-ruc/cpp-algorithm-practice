#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>


using namespace std;
typedef long long ll;

const ll mod=998244353;

int n;
int a[100005];

struct node{
    int gcd_value;//这一组区间的最大公约数
    ll sum_l;//这一组区间左端点之和
};

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    vector<node> list;//上一个右端点对应的所有gcd组
    ll res=0;

    for(int r=1;r<=n;r++){
        vector<node> newlist;

        //新出现的区间[r,r]
        newlist.push_back({a[r],r});

        //原来所有以r-1结尾的区间，现在都向右延伸一位
        for(int i=0;i<list.size();i++){
            int now_gcd=std::gcd(list[i].gcd_value,a[r]);

            //相邻两组的gcd相同，就把它们合并起来
            if(newlist.back().gcd_value==now_gcd){
                newlist.back().sum_l+=list[i].sum_l;
                newlist.back().sum_l%=mod;
            }else{
                newlist.push_back({now_gcd,list[i].sum_l});
            }
        }

        list=newlist;

        //题目要求累加 l*r*gcd(l,r)
        for(int i=0;i<(int)list.size();i++){
            ll now=list[i].gcd_value*list[i].sum_l%mod;
            now=now*r%mod;
            res=(res+now)%mod;
        }
    }

    cout << res;
    return 0;
}
