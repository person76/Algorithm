#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[11];
vector<long long> v; // 9,876,543,210

void dfs(long long cur){
    v.push_back(cur);
    for(int i=0; i<10; i++){
        if(!visited[i] && cur%10 > i){
            visited[i]=true;
            dfs(cur*10+i);
            visited[i]=false;
        }
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N; //N<=1,000,000

    v.push_back(-1);

    for(int i=0; i<10; i++){
        visited[i]=true;
        dfs(i);
        for(int j=0; j<10; j++){
            visited[j]=0;
        }
    }

    sort(v.begin(), v.end());

    if(N>1023){
        cout<<-1;
    }
    else{
        cout<<v[N];
    }
    
}