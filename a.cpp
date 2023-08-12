#include <bits/stdc++.h>
using namespace std;
// 일반 배열의 경우: 메서드 지원 X
int main() {
    int a[] = {1,2,3};
    do{
        for(int i: a) cout << i << " ";
        cout << "\n";
    }while(next_permutation(&a[0], &a[0]+3));
    // }while(next_permutation(a, a+3))
}

// // 벡터의 경우: begin, end 메서드 지원
// int main() {
//     vector<int> a = {1,2,3};
//     do{
//         for(int i: a) cout << i << " ";
//         cout << "\n";
//     }while(next_permutation(a.begin(), a.end()));
// }

// // 꼭 오름차순으로 정렳한 상태에서 진행: sort 메서드
// int main() {
//     vector<int> a = {2,1,3,100,200};
//     sort(a.begin(), a.end()); // 오름차순 정렬
//     do{
//         for(int i: a) cout << i << " ";
//         cout << "\n";
//     }while(next_permutation(a.begin(), a.end()));
// }

// // 응용: 순서 상관 있게 2개를 뽑아라
// int main ( ) {
//     vector<int> a = {2,1,3,100,200};
//     sort(a.begin(), a.end());
//     do{
//         for(int i = 0; i < 2; i++) {
//             cout << a[i] << " ";
//         }
//             cout << " \n";
//     }while(next_permutation(a.begin(), a.end()));
// }

// 공식: nPr = n!/(n-r)!