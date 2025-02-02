// 블랙잭
#include <iostream>
#include <vector>
using namespace std;
#define fio() ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pp pair<int, int>
#define ll long long int
#define int long long

int N, M, ans;

signed main() {
    fio()

    cin >> N >> M;
    vector<int> v(N);
    for(int i=0; i<N; i++) cin >> v[i];
    // for(auto& vi : v) cin >> vi;

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            for(int k=j+1; k<N; k++){
                int sum = v[i] + v[j] + v[k];
                if(sum<=M) ans = (ans > sum) ? ans : sum; // ans = max(ans, sum);
            }
        }
    }

    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //         for(int k=0; k<N; k++){
    //             if(i != j && j != k && k != i){
    //                 int sum = v[i] + v[j] + v[k];
    //                 if(sum<=M) ans = (ans > sum) ? ans : sum;
    //             }
    //         }
    //     }
    // }

    cout << ans << '\n';

    return 0;
}