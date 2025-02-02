// 파도반 수열
// 다이나믹 프로그래밍
#include <iostream>
#include <vector>
using namespace std;
#define fio() ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define ll long long int
#define pp pair<int, int>

int T, n;
int d[101];

int dp(int n){
    d[0] = 1; d[1] = 1; d[2] = 1;
    for (int i = 3; i < n; i++) d[i] = d[i - 2] + d[i - 3];
    return d[n-1];
}

signed main(){
    fio()

    cin >> T;
    dp(100);
    for (int i = 0; i < T; i++){
        cin >> n;
        // dp(n);
        cout << d[n-1] << '\n';
    }

    return 0;
}

// 근데 이것도 똑같을 걸 다시 쓰는 거 아닌가 싶어서 .. 
// dp(100) 으로 다 해두고 돌려도 맞긴 하네유