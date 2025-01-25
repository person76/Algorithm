#include <iostream>
using namespace std;

int main(){
    int N, K; //N = 현재 물병 개수, K = 가능한 최대 비어있지 않은 물병 개수
    cin>>N>>K;
    int temp = 1;
    while(N>=temp*2){
        temp*=2;
    }

    int res=0;

    while(N>0 && K>0){
        while(N<temp){
            temp/=2;
        }
        N-=temp;
        K--;
    }

    if(N==0){
        cout<<0;
    }
    else{
        cout<<temp-N;
    }
}