#include <iostream>
#include <iomanip>


using namespace std;
int n,na,nb;
int a[500],b[500];


void init(){
    cin >> n >> na >> nb;
    for(int i=0;i<na;i++){
        cin >> a[i];
    }
    for(int i=0;i<nb;i++){
        cin >> b[i];
    }
}

int ascore(int x,int y){
    if((x==0&&(y==2 || y==3)) || (x==1&&(y==0|| y==3)) || (x==2&&(y==1||y==4)) || (x==3 && (y==4 || y==2)) || (x==4&&(y==0 || y==1))){
        return 1;
    }else if(x==y){
        return 0;
    }else{
        return -1;
    }
}


int main(){
    init();
    int resa=0,resb=0;
    for(int i=0;i<n;i++){
        int new_a=i%na;
        int new_b=i%nb;
        // cout << "NO." << i << ": " << new_a << " " << new_b << " ";
        int score=ascore(a[new_a],b[new_b]);
        // cout <<  score << endl;
        if(score==1)resa++;
        if(score==-1)resb++;
    }
    cout << resa << " " << resb;

    
    return 0;
}
// 1 0