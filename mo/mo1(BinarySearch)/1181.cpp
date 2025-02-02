// 단어 정렬
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define fio() ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define ll long long int
#define pp pair<int, int>

int n;

bool str_size(string a, string b){
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

signed main(){
    fio()

    cin >> n;

    vector<string> strs(n);
    for(int i=0; i<n; i++){
        cin >> strs[i];
    }

    sort(strs.begin(), strs.end(), str_size);

    for(int i=0; i<n; i++){
        if(i != 0 && strs[i] == strs[i-1]) continue;
        cout << strs[i] << '\n';
    }

    return 0;
}