// 괄호 
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
#define fio() ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pp pair<int, int>
#define ll long long int
#define int long long

int T, L, R;
stack<string> stk;

signed main() {
    fio()

    cin >> T;
    vector<string> ps(T);
    for(int i=0; i<T; i++) cin >> ps[i];

    for(int i=0; i<T; i++){
        L = 0; R = 0;
        for(int j=0; j<ps[i].size(); j++){ 
            if(ps[i].at(j)=='(') L++;
            else if(ps[i].at(j)==')'){
                R++;
                if(L<R) break;
            }
        }

        // cout << L << R << '\n';

        if(L == R) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}

// // 그냥 개수 세서 비교하면 안되나
// 스택 ??

// '('보다 ')'가 많거나 적으면 안됨... 1 개수 같다
// 2 )가 많은 상태가 한번이라도 되면 예외 없이 제낌.

// // 지역 변수로 선언하고 int L, R = 0 ㅇㅈㄹ... 동시 할당 XXX