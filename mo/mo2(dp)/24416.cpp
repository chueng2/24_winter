// 알고리즘 수업 - 피보나치 수 1
// dp (bottom up, upper bound)
#include <iostream>
#include <vector>
using namespace std;
#define fio() ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define ll long long int
#define pp pair<int, int>

int n, code1, code2;

int fib(int n){
    if (n == 1 || n == 2) {
        code1++;
        return 1;
    }
    else return (fib(n-1) + fib(n-2));
}

int f[40];

int fibonacci(int n){
    f[0] = 1; f[1] = 1;
    for(int i=2; i<n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        code2++;
    }
    return f[n-1];
}

signed main(){
    fio()

    cin >> n;

    fib(n);
    fibonacci(n);

    cout << code1 << ' ' << code2;

    return 0;
}



// 아래 의사 코드를 이용하여 n의 피보나치 수를 구할 경우 코드1 코드2 실행 횟수를 출력하자.

// 피보나치 수 재귀호출 의사 코드는 다음과 같다.

// fib(n) {
//     if (n = 1 or n = 2)
//     then return 1;  # 코드1
//     else return (fib(n - 1) + fib(n - 2));
// }

// 피보나치 수 동적 프로그래밍 의사 코드는 다음과 같다.

// fibonacci(n) {
//     f[1] <- f[2] <- 1;
//     for i <- 3 to n
//         f[i] <- f[i - 1] + f[i - 2];  # 코드2
//     return f[n];
// }