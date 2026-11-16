#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

// n,q <=100
using namespace std;
int n,q;
int b[1000005];

int win(int left,int right){
    int a[1000005];
    for(int i=1;i<=right-left+1;i++){
        a[i]=b[left+i-1];
    }
    int res=a[1];
    for(int i=3;i<=right-left+1;i+=2){
        res=res^b[i];
    }
    
    if(res==0)return 1;
    return 0;
}

//如果大的异或是0，子序列一定是0。大的win，子一定win。所以只需要继续拆
int main(){
    cin >> n >> q;//n个仓库，q个询问
    for(int i=1;i<=n;i++){
        cin >> b[i];//各仓库石子个数
    }
    while(q--){//cout每个询问能得到的必胜子游戏数量的最大值
        int L,R;
        cin >> L >> R;
        int cnt=0;
        while(1){
            if(win(L,R)){

            }
        }
    }

    
    return 0;
}
