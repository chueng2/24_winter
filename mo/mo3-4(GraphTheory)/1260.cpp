// DFS와 BFS
// 그래프 
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

// dfs, bfs, 스택, 큐
// 방문 여부를 살피기 위한 배열 (visit)
// 루트 노드(시작 정점) -> 인접 정점들의 방문 순서!
// 인접한 정점이 여러 개인 경우 정점 번호가 작은 순으로


int n, m, v;  // 정점 개수, 간선 개수, 시작 정점
bool visit[1010];  // 방문 여부 배열
vector<int> graph[1010];  // 각 정점에 대한 인접 리스트

// dfs(재귀)
void dfs(int now){
    visit[now] = 1;  // 방문한 곳 표시
    cout << now << ' ';  // 현재 방문한 정점 출력

    // 인접 정점 순회
    // graph[now]는 now에 연결된 모든 인접 노드들의 리스트.
    // next는 리스트에 순서대로 저장된 인접 노드의 값들이 될 것이다.
    for(auto next : graph[now]){
        if(!visit[next]) dfs(next);  // visit[next]가 1이 아닌 상태 -> 방문하지 않음
        // next 정점을 방문하지 않았을 경우 next에 대해 재귀적으로 dfs 호출
    }
}

// // dfs(스택)

// bfs
void bfs(int start){
    queue<int> q;
    q.push(start);  // 시작 추가
    visit[start] = 1;  // 시작점 방문 표시

    while(!q.empty()){  // 큐가 다 비워질 때까지 (push와 pop을 하며 반복)
        int now = q.front();  // q 에 start 부터 시작해서 이후 push되는 값들이 now가 될 예정
        q.pop();
        cout << now << ' ';

        for(auto next : graph[now]){
            if(!visit[next]){  // next에 방문한 적이 없을 경우
                // next 방문 처리, q에 추가
                visit[next] = 1;
                q.push(next);
                // 모두 방문한 상태면 push되는 값이 없기 때문에 while문 종료
            }
        }
    }
}

signed main(){
    fio()

    cin >> n >> m >> v;

    for(int i = 0; i < m; i++){  // 간선 수 만큼 연결 관계 받기
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);  // u와 연결된 정점에 v 추가
        graph[v].push_back(u);  // 양방향 간선
    }

    // 정점 번호 작은 것부터 순서대로 방문하도록 정렬
    for(int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());

    dfs(v);
    cout << '\n';

    // dfs 사용 후 방문 기록 초기화... -> bfs 정상 작동
    for (int i = 1; i <= n; i++) {
        visit[i] = 0;
    }

    bfs(v);
    cout << '\n';

    return 0;
}




// memset -> #include <cstring>        어데에 쓰는지는 여전히 모르고


/*
/ 스택 <stack>
.push(value) : value를 스택의 뒤에 ?? 추가
pop() : 스택의 뒤에서 원소를 하나 제거
top() : 맨 위(가장 바깥) 원소 반환
empty() : 스택이 비어있으면 true 반환
size() : 스택의 크기 즉, 원소의 수 반환

9012 괄호
1874 스택 수열
9935 문자열 폭발


/ 큐 <queue>
push(value) : value를 큐의 뒤에 추가
pop() : 큐의 앞(front)의 원소 하나 제거
front() : 맨 앞(가장 바깥) 원소 반환
empty() : 큐가 비어있으면 true 반환
size() : 큐의 크기 즉, 원소의 수 반환

2164 카드2
11866 요세푸스 문제0


/ 덱 <deque>
push_front(), push_back()
pop_front(), pop_back()
front(), back()
empty()
size()

10866 덱
5430 AC
27497 알파벳 블록


/ 집합 셋 <set>
insert(value) : value를 집합에 넣음
erase(value) : value를 집합에서 뺌
find(value) : value의 위치를 반환
count(value) : value의 갯수를 반환
empty()
size()
.....................
/ 맵 <map>
map[key] = value;
map<type, type> : (멀티맵 multimap)

1269 대칭 차집합
1620 나는야 포켓몬 마스터 이다솜
4358 생태학
2015 수들의 합4
28137 뭐라고? 안들려
28132 기백을 안배운다고?
*/