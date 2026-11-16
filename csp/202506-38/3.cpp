#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
int n;


int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        char message[80];
        fgets(message,72,stdin);
        if(message[0]==0){
            //easy message
            char receiver[30],sender[30],location[20];
            for(int j=1;j<=28;j++){
                receiver[j]=message[j];
            }
            for(int j=1;j<=28;j++){
                sender[j]=message[28+j];
            }
            for(int j=1;j<=15;j++){
                location[j]=message[56+j];
            }

            //这里先遍历存储的代号、散列值对照表，如果出现过一样的散列值直接输出，否则尝试是不是典型代号的短数字表示，先加上2^25，对这个数字求26进制下的各个数字，求出原始代号。
        }else{//1
            //complex message
            char people1[60],people2[20],flag=message[71];
            for(int j=1;j<=58;j++){
                people1[j]=message[j];
            }
            for(int j=1;j<=12;j++){
                people2[j]=message[58+j];
            }
            if(flag==0){
                //people1是发送方且为代号,people2是接收方且为散列
                //所以输出people1时直接输出不需要#。我觉得就是不断除38？相当于38进制，找出之前的数，但是我困惑的点在于一个58位数字怎么进行数学运算？我连读取都不太会，只会fgets读成char类型。反正就是一顿处理之后就得到一堆数字对应着数字、大写字母、下划线，直接输出就行了

                //people2就是12位散列，通过散列倒推代号。那这里也就是要存储之前得到过的所有数字代号，同时存储对应的12位散列值，直接for循环遍历对照一下是否有散列值一样的，如果没有就是###，有的话就是#+代号名
            }else{
                //people2是发送方,people1是接收方
            }
            

        }
    }

    
    return 0;
}
