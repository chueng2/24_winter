// 일곱 난쟁이
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fio() ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<int> a(9);
int sum, result;
int idx1, idx2;

signed main() {
    fio()

    for(int i=0; i<9; i++) cin >> a[i];

    sort(a.begin(), a.end());

    // for(int i=0; i<3; i++){
    //     sum = 0;
    //     for(int j=0; j<7; j++){
    //         sum += a[i+j];
    //         b.push_back(a[i+j]);
    //         if(sum > 100) break;
    //     }
    //     if(sum == 100) break;
    //     b.clear();
    // }

    for(int i=0; i<9; i++) sum += a[i];

    for(int i=0; i<9; i++){
        for(int j=i; j<9; j++){
            idx1 = i, idx2 = j;
            result = sum - (a[i] + a[j]);
            if(result == 100) break;
        }
        if(result == 100) break;
    }

    for(int i=0; i<9; i++){
        if(i==idx1 || i==idx2) continue;
        cout << a[i] << '\n';
    }

    return 0;
}

// 오름차순 정렬 (내림차순 : rbegin(), rend())
// 뇌에서 굴리기 너무 힘들다
// nCr ? // nCr = n-1Cr-1 + n-1Cr // 

// int com(int n, int r){ // 9C7... 은 알겠는데..... 
//     if(n == r || r == 0) return 1;
//     else return com(n-1, r-1) + com(n-1, r);
// }

// 2개만 빼고 나머지를 더한다.. 어떻게 하나요...

// 겜하고 싶다
// 춥고 배고프다
// 왜이렇죠 난방좀 더요 제발 기숙사