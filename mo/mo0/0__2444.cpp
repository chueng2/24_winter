// 별 찍기 - 7
#include <iostream>
using namespace std;
#define fio() ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int n;

signed main() {
    fio()

    cin >> n;
    for(int i=1; i<2*n; i++){ 
        if(i<=n){
            for(int j=0; j<(n-i); j++) cout << ' ';
            for(int j=0; j<(2*i-1); j++) cout << '*';
            // for(int j=0; j<(n-i); j++) cout << ' ';
            cout << '\n';
        }
        if(i>n){
            for(int j=n; j>(2*n-i); j--) cout << ' ';
            for(int j=2*n; j>(2*i-2*n+1); j--) cout << '*'; // for(int j=0; j<(2*n-(2*i-(2*n-1))); j++) cout << '*';
            // for(int j=n; j>(2*n-i); j--) cout << ' ';
            if(i==2*n-1) break;
            cout << '\n';
        }
    }

    return 0;
}

// n줄까지 양 옆 하나씩 증가
// n+1줄부터 2*n-1줄 까지 양 옆 하나씩 줄이기 .. .. 
// 가운데 정렬