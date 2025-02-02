// 01타일
// 다이나믹 프로그래밍
#include <iostream>
#include <vector>
using namespace std;
#define fio() ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define ll long long int
#define pp pair<int, int>

int n;
int d[1010101];

void dp(int n){
    d[0] = 1; d[1] = 2;
    for (int i = 2; i < n; i++) d[i] = (d[i - 1] + d[i - 2]) % 15746;
}

signed main(){
    fio()

    cin >> n;

    dp(n);

    cout << d[n-1] << '\n';

    return 0;
}

// 피보나치 수열의 값이 매우 커질 수 있기 때문에 int 가 아닌 long long 타입으로 표현해야 함.
// long long 타입을 넘어서는 값을 방지하기 위해 15746 나머지 연산이 미리(굵은글씨 혹은 느낌표) 필요하다.

// 첫 번째 줄에 지원이가 만들 수 있는 길이가 N인 모든 2진 수열의 개수를 15746으로 나눈 나머지를 출력한다. 
// () % 15746 (?)