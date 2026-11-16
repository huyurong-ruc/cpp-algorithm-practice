#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

// 75分，Z大了超时。需改进大表旋转Z^2的复杂度。


using namespace std;
int z,m,n,k,key[999999]; //<=400
char a[500][500];

int main(){
    cin >> z;
    m=n=z;
    for(int i=1;i<=z;i++){
        for(int j=1;j<=z;j++){
            cin >> a[i][j];
        }
    }

    cin >> k;
    for(int i=1;i<=k;i++){
        cin >> key[i];
    }

    int t=key[1];
    for(int i=1;i<=t;i++){
        int begin=k-6*i+1;
        int op=key[begin];
        if(op==1){
            int u=key[begin+1],v=key[begin+2],L=key[begin+3],d=key[begin+4],r=key[begin+5];
            //把（u，v）开始的L*L大小子表顺时针旋转d度，再将整个图进行r次逆时针旋转90度
            //整个图顺时针r次90度
            r = r%4;
            char tmp[500][500];
            while(r--){
                for(int x=1;x<=z;x++){
                    for(int y=1;y<=z;y++){
                        tmp[x][y]=a[z+1-y][x];
                    }
                }
                for(int x=1;x<=z;x++){
                    for(int y=1;y<=z;y++){
                        a[x][y]=tmp[x][y];
                    }
                }
            }
            char b[L+1][L+1];
            if(d==90){
                //顺时针转3次
                for(int x=1;x<=L;x++){
                    for(int y=1;y<=L;y++){
                        b[x][y]=a[u+L-y][v-1+x];
                    }
                }
                for(int x=1;x<=L;x++){
                    for(int y=1;y<=L;y++){
                        a[x+u-1][y+v-1]=b[x][y];
                    }
                }

                for(int x=1;x<=L;x++){
                    for(int y=1;y<=L;y++){
                        b[x][y]=a[u+L-y][v-1+x];
                    }
                }
                for(int x=1;x<=L;x++){
                    for(int y=1;y<=L;y++){
                        a[x+u-1][y+v-1]=b[x][y];
                    }
                }

                for(int x=1;x<=L;x++){
                    for(int y=1;y<=L;y++){
                        b[x][y]=a[u+L-y][v-1+x];
                    }
                }
                for(int x=1;x<=L;x++){
                    for(int y=1;y<=L;y++){
                        a[x+u-1][y+v-1]=b[x][y];
                    }
                }
            }else if(d==180){
                for(int x=1;x<=L;x++){
                    for(int y=1;y<=L;y++){
                        b[x][y]=a[u+L-y][v-1+x];
                    }
                }
                for(int x=1;x<=L;x++){
                    for(int y=1;y<=L;y++){
                        a[x+u-1][y+v-1]=b[x][y];
                    }
                }

                for(int x=1;x<=L;x++){
                    for(int y=1;y<=L;y++){
                        b[x][y]=a[u+L-y][v-1+x];
                    }
                }
                for(int x=1;x<=L;x++){
                    for(int y=1;y<=L;y++){
                        a[x+u-1][y+v-1]=b[x][y];
                    }
                }
            }else{
                for(int x=1;x<=L;x++){
                    for(int y=1;y<=L;y++){
                        b[x][y]=a[u+L-y][v-1+x];
                    }
                }
                for(int x=1;x<=L;x++){
                    for(int y=1;y<=L;y++){
                        a[x+u-1][y+v-1]=b[x][y];
                    }
                }
            }
        }else{
            int u=key[begin+1],d=key[begin+2],l=key[begin+3],r=key[begin+4],o=key[begin+5];
            //把u-d行，l-r列抽出来，o=1上下翻转，o=-1左右翻转
            //int b[500][500];
            // for(int x=u;x<=d;x++){
            //     for(int )
            // }
            if(o==1){//上下翻转
                for(int x=u;x<=(d+u)/2;x++){
                    for(int y=l;y<=r;y++){
                        int target=d+u-x;
                        char tmp=a[x][y];
                        a[x][y]=a[target][y];
                        a[target][y]=tmp;
                        
                    }
                }
            }else{//左右翻
                for(int x=u;x<=d;x++){
                    for(int y=l;y<=(r+l)/2;y++){
                        int target=r+l-y;
                        char tmp=a[x][y];
                        a[x][y]=a[x][target];
                        a[x][target]=tmp;

                    }
                }
            }
        }
    }
    for(int i=1;i<=z;i++){
        if(a[i][1]=='?'){
            m=i-1;
            break;
        }
    }
    for(int i=1;i<=z;i++){
        if(a[1][i]=='?'){
            n=i-1;
            break;
        }
    }
    cout << m << " "<< n << endl;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout << a[i][j];
        }
        cout << endl;
    }

    
    return 0;
}
