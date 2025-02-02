// 초6 수학
// 최소공배수 최대공약수

#include <iostream>
using namespace std;
#define fio() ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long

int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}

int lmc(int a, int b){
    return (a*b)/gcd(a,b);
}

int T, a, b;

signed main() {
    fio()

    cin >> T;
    for(int i=0; i<T; i++){
        cin >> a >> b;
        cout << lmc(a,b) << " " << gcd(a, b) << '\n';
    }

    return 0;
}

// __gcd(a, b)