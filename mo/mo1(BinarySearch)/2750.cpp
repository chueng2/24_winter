// 2750 수 정렬하기, 2751 (2)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fio() ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long

int n;

signed main(){
    fio()

    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    for(int i=0; i<n; i++) cout << a[i] << '\n';

    return 0;
}