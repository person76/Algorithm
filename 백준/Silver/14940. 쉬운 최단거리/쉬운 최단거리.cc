#include <iostream>
#include <queue>
using namespace std;

int arr[1001][1001];
bool visited[1001][1001];

int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};

int n,m;
int v;

void BFS(int stY, int stX){
    arr[stY][stX]=0;
    queue<pair<int,int>> q;
    q.push({stY,stX});
    visited[stY][stX]=1;
    while(!q.empty()){
        int curY=q.front().first;
        int curX=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nextY = curY+dy[i];
            int nextX = curX+dx[i];
            if(nextY<0|| nextX<0|| nextY>=n || nextX>=m) continue;
            if(!visited[nextY][nextX] && arr[nextY][nextX]){
                q.push({nextY,nextX});
                visited[nextY][nextX]=1;
                arr[nextY][nextX]=arr[curY][curX]+1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m; //세로, 가로

    bool find2=false;
    int stY, stX;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(!find2 && arr[i][j]==2){
                stY=i;
                stX=j;
                find2=1;
            }
        }
    }

    BFS(stY,stX);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && arr[i][j]){
                arr[i][j]=-1;
            }
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }

}