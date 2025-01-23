#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<pair<int,int>> v[401];
int arr[401][401];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V,E;
    cin>>V>>E; 

    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            arr[i][j]=INF;
        }
    }

    // 그래프 생성
    for(int i=0; i<E; i++){
        int a,b,c;
        cin>>a>>b>>c; // 출발노드, 도착노드, 가중치
        v[a].push_back({b,c});
        arr[a][b]=c; 
    }

    // 플로이드 워셜
    for(int k=1; k<=V; k++){
        for(int a=1; a<=V; a++){
            for(int b=1; b<=V; b++){
                arr[a][b] = min(arr[a][b], arr[a][k]+ arr[k][b]);
            }
        }
    }
    int res= INF;
    for(int i=1; i<=V; i++){
        res=min(arr[i][i], res);
    }

    if(res==INF){
        cout<<-1;
    }
    else{
        cout<<res;
    }

}