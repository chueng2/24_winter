// 등차수열의 합
#include <iostream>
#include <vector>
using namespace std;
#define fio() ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define ll long long int
// #define int long long

int n;
int m = 1;

signed main() {
    fio()

    cin >> n;
    vector<int> a(n);

    for(int i=0; i<n; i++) cin >> a[i];

    for(int i=0; i<n-1; i++){
        if(i==0){
            if(n==1) break;
            continue;
        }
        if(a[i]-a[i-1] == a[i+1]-a[i]) m = 1;
        else{
            m = 0;
            break;
        }
    }

    if(m==1){
        cout << "YES" << '\n'; // tlqkf Yes 라고 적었어
        for(int j=0; j<n; j++) cout << a[j]+2*(j+1) << " ";
        cout << '\n';
        for(int j=0; j<n; j++) cout << -2*(j+1) << " ";
        // for(int j=0; j<n; j++) cout << a[j] << " ";
        // cout << '\n';
        // for(int j=0; j<n; j++) cout << 0 << " ";
    }
    else cout << "NO" << '\n';

    return 0;
}

// a(i)-a(i-1) 등차수열인지 확인
// 등차수열 b, c는... ?
// 걍 무지성 해버림.. 몰라