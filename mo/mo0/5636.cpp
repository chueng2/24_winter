// 소수 부분 문자열
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define fio() ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define ll long long int
#define pp pair<int, int>

// int is_prime(int a, int b){

// }

// int n;
// vector<string> a;

// signed main() {
//     fio()

//     int i = 0;
//     while(a[i] != '0'){
//         cin >> a;
//         i++;
//     }

//     for(i=0; i<a[i].size(); i++){
//         if(is_prime()){
            
//         }
//     }

//     return 0;
// }


// // 소수의 배수는 소수가 아님 이다.
// // // 소수가 아닌 놈의 배수도 소수가 아님이다.
// // 시그마 i=1부터 n까지 [n/i] <= 시그마 i=1부터 n까지 (n/i), (i => x로, 구분구적법)
// a

int n;

signed main(){
    fio()



    return 0;
}
const int MAX = 10101010;
bool is_prime[MAX];
int primes[MAX];

void sieve() {
    fill(is_prime, is_prime+MAX, 1);
    for(int i = 1; i < MAX; i++) primes[i] = i;

    for(int i = 2; i*i < MAX; i++) {
        if (primes[i] != i) continue;
        for (int j = i*i; j < MAX; j += i) primes[j] = i;
    }

    // // 확인용
    // for (int i = 2; i <=100; i++) cout << i << ' ' << primes[i] << '\n';

    is_prime[0] = is_prime[1] = 0;

    for(int i = 1; i < MAX; i++) {
        if(!is_prime[i]) continue;
        for(int j = i + 1; j < MAX; j += i) is_prime[j] = 0;
    }

    // for (int i = 1; i <= 100; i++) {
    //     if (is_prime[i]) cout << i << '\n';
    // }
}

// void factorize(int x) {
//     while (x > 1) {
//         cout << primes[x] << '\n';
//         x /= primes[x];
//     }
// }


int main() {
    fio()
    
    sieve();

    int m, n;
    cin >> m >> n;

    for(int i = m; i <= n; i++) {
        if(!is_prime[i]) cout << i << '\n';
    }

    return 0;
}