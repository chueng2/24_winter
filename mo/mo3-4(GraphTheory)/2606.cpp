// 바이러스
// dfs 아님 bfs 아무거나 하면 될듯 
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define fio() ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define ll long long int
#define pp pair<int, int>

int n, m, cnt;
bool visit[101];
vector<int> graph[101];

void dfs(int now){
    visit[now] = 1;

    for(auto next : graph[now]){
        if(!visit[next]){
            cnt ++;
            dfs(next);
        }
    }
}

signed main(){
    fio()

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // '서로 연결된' 이라 무향(양방향) 그래프 -> 안 해주면 dfs 탐색 시 다시 돌아올 수 없다
    }

    for(int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());

    dfs(1);
    cout << cnt << '\n';

    return 0;
}