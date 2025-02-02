// 수 찾기
// // 바보가 완전탐색 해서 시간 초과 뜸 ㅋ 
// 정렬, 이분탐색
// + 맵 쓰는 방법
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fio() ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define ll long long int
#define pp pair<int, int>

int n, m;

signed main(){
    fio()

    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    cin >> m;
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        int left = 0;
        int right = n;
        while (left + 1 < right){
            int mid = (left+right)/2;
            if (a[mid] <= x) left = mid;
            else right = mid;
        }

        if (a[left] == x) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}