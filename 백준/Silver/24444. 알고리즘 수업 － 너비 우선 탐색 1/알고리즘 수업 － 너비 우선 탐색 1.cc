#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[100001];
int arr[100001]={0,};
bool visited[100001];

void BFS(int st){
    queue<int> q;
    q.push(st);
    visited[st]=1;
    int cnt=0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        arr[cur]=++cnt;
        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i];
            if(!visited[next]){
                q.push(next);
                visited[next]=1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M,R;
    cin>>N>>M>>R;

    for(int i=0; i<M; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);

    }

    for(int i=0; i<=N; i++){
        sort(v[i].begin(), v[i].end());
    }

    BFS(R);

    for(int i=1; i<=N; i++){
        cout<<arr[i]<<'\n';
    }

}