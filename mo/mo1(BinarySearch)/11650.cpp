// 11650 좌표 정렬하기, 11651 (2)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fio() ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define ll long long int
#define pp pair<int, int>

int n, x, y;
// vector<vector<int>> a;
vector<pp> a;

bool compare(pp x, pp y){
    if(x.second == y.second) return x.first < y.first;
    return x.second < y.second;
} // second 기준

signed main(){
    fio()

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        a.push_back(make_pair(x, y));
    }

    // sort(a.begin(), a.end()); // first 기준
    sort(a.begin(), a.end(), compare); // second 기준

    for(int i=0; i<n; i++) cout << a[i].first << " " << a[i].second << '\n';

    return 0;
}