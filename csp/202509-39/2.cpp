#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
int n,l;
int a[300][300];
int tmp[300][300];
int tong[70000];

int biaozhun[10][10]={
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,0,1,1,0,1,0},
    {0,0,1,1,0,0,0,0,0,1},
    {0,0,1,1,1,1,0,0,1,1},
    {0,0,0,0,0,0,0,0,1,1}
};


int check(int x,int y){//从（x，y）作为左上角开始比较
    for(int p=1;p<=5;p++){
        for(int q=1;q<=9;q++){
            if(tmp[x+p-1][y+q-1]!=biaozhun[p][q])return 0;
        }
    }
    return 1;
}

void change(int k){
    for(int r=1;r<=n;r++){
        for(int t=1;t<=n;t++){
            if(a[r][t]>=k)tmp[r][t]=0;
            else tmp[r][t]= 1;
        }
    }

}

int main(){
    cin >> n >> l;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    // for(int k=0;k<=l-1;k++){
    //     change(k);
    //     int flag=0;
    //     for(int i=1;i<=n-4;i++){
    //         for(int j=1;j<=n-8;j++){
    //             if(check(i, j)){
    //                 cout<<k<<endl;
    //                 flag=1;
    //                 break;
    //             }
    //         }
    //         if(flag)break;
    //     }

    // }
    for(int i=1;i<=n-4;i++){
        for(int j=1;j<=n-8;j++){ //从（i，j）为左上角扫描
            int l=70000,r=-1;
            
            for(int x=1;x<=5;x++){
                for(int y=1;y<=9;y++){
    
                    if(biaozhun[x][y]==0){//白色，>=k
                        l=min(l,a[i+x-1][j+y-1]);
                    }else{
                        r=max(r,a[i+x-1][j+y-1]);
                    }
                }
            }
            int lower=r+1;
            int upper=l;
            if(lower<=upper){
                tong[lower]++;
                tong[upper+1]--;
            }

        }
    }
    int res=0;
    for(int k=0;k<=l-1;k++){
        res+=tong[k];
        if(res)cout << k << endl;
    }



    
    return 0;
}
