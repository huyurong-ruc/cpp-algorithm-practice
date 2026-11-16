// op={0,1},n<=10   30
// op=0,n<=10^5     20
// op={0,1},n<=10^5 30
// op=0,n<=10^7     10
// op={0,1},n<=10^7 10

// 暴力求解拿30分


#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
int op,n;
typedef long long ll;

int check(int a,int b,int c,int d,int e,int f,int g){
    int arr[10]={a,b,c,d,e,f,g};
    int cnt=0;
    int diff[10]={0};
    for(int i=0;i<=6;i++){
        int flag=0;
        for(int j=0;j<=cnt;j++){
            if(diff[j]==arr[i]){
                flag=1;
                break;
            }
        }
        if(flag)continue;
        diff[cnt++]=arr[i];
    }
    if(cnt==6){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    cin >> op >> n;
    if(n<=0){
        cout << 0;
        return 0;
    }
    ll res=0;
    if(op==0){//B<=n的所有情况，D之和
        for(int b=1;b<=n;b++){
            //b已固定
            for(int a=1;a<=b*b;a++){
                if(b*b%a==0){
                    int c=b*b/a;
                    //a,c固定
                    int f=0;
                    for(int tmp=1;tmp<=sqrt(a*b*c);tmp++){
                        if(tmp*tmp*tmp==a*b*c){
                            f=tmp;
                            break;
                        }
                    }
                    if(f<=0)continue;
                    //a,b,c,f固定
                    for(int e=1;e<=f*f;e++){
                        int g=0;
                        if(f*f%e==0){
                            g=f*f/e;
                        }else{
                            continue;
                        }
                        //a,b,c,e,f,g，还差d
                        for(int d=1;d<=a*b/e;d++){
                            if(a*b%e==0){
                                d=a*b/e;
                                res+=d;
                            }
                        }

                    }
                }
            }
        }
    }else{//B<=n的所有情况完美矩阵，D之和
        for(int b=1;b<=n;b++){
            //b已固定
            for(int a=1;a<=b*b;a++){
                if(b*b%a==0){
                    int c=b*b/a;
                    //a,c固定
                    int f=0;
                    for(int tmp=1;tmp<=sqrt(a*b*c);tmp++){
                        if(tmp*tmp*tmp==a*b*c){
                            f=tmp;
                            break;
                        }
                    }
                    if(f<=0)continue;
                    //a,b,c,f固定
                    for(int e=1;e<=f*f;e++){
                        int g;
                        if(f*f%e==0){
                            g=f*f/e;
                        }else{
                            continue;
                        }
                        //a,b,c,e,f,g，还差d
                        for(int d=1;d<=a*b/e;d++){
                            if(a*b%e==0){
                                d=a*b/e;
                                if(check(a,b,c,d,e,f,g)){
                                    res+=d;
                                }
                            }
                            
                        }

                    }
                }
            }
        }
    }

    cout << res%998244353;
    return 0;
}
