#include <bits/stdc++.h>
using namespace std;
// c/cpp는 함수 내 함수 선언은 불가하다.
// vector<pair<int, int>>를 "내림차순:오름차순"으로 정렬하고 싶다면
bool cmp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }

int main() {
    // 컨테이너들의 요소를 정렬하기: sort
    // sort(): 보통 array or vector 정렬 시에 쓰임. O(nlogn)
    // sort(first, last, *커스텀비교함수)
    // - 커스텀비교함수
    // 0. 기본은 오름차순(커스텀비교함수를 넣지 않았을 때)
    // 1. greater<타입>()을 넣어 내림차순 변경 가능
    // 2. less<타입>()을 넣어 오름차순 정렬
    cout << "배열 정렬"
         << "\n";
    int b[5];
    for (int i = 0; i < 5; i++) {
        b[4 - i] = i;
    }
    for (int i = 0; i < 5; i++)
        cout << b[i] << " ";
    cout << "\n";
    // 오름차순
    sort(b, b + 5);
    for (int i = 0; i < 5; i++)
        cout << b[i] << " ";
    cout << "\n";
    // 내림차순
    sort(b, b + 5, greater<int>());
    for (int i = 0; i < 5; i++)
        cout << b[i] << " ";
    cout << "\n\n";

    cout << "벡터 정렬"
         << "\n";
    vector<int> v;
    for (int i = 5; i >= 1; i--)
        v.push_back(i);
    for (int i : v)
        cout << i << " ";
    cout << "\n";
    sort(v.begin(), v.end());
    for (int i : v)
        cout << i << " ";
    cout << "\n";
    sort(v.begin(), v.end(), greater<int>());
    for (int i : v)
        cout << i << " ";
    cout << "\n\n";

    cout << "pair 기반 벡터"
         << "\n";
    vector<pair<int, int>> pairV;
    for (int i = 10; i >= 1; i--)
        pairV.push_back({i, 10 - i});
    for (pair<int, int> i : pairV)
        cout << i.first << ":" << i.second << " ";
    cout << "\n";
    sort(pairV.begin(), pairV.end());
    for (auto i : pairV)
        cout << i.first << ":" << i.second << " ";
    cout << "\n";

    // {내림차순, 오름차순} 하고 싶다면?: cmp 함수를 만들어 넣자
    sort(pairV.begin(), pairV.end(), cmp);
    for (auto i : pairV)
        cout << i.first << ":" << i.second << " ";
    cout << "\n";
    return 0;
    // 배열 정렬
    // 4 3 2 1 0
    // 0 1 2 3 4
    // 4 3 2 1 0

    // 벡터 정렬
    // 5 4 3 2 1
    // 1 2 3 4 5
    // 5 4 3 2 1

    // pair 기반 벡터
    // 10:0 9:1 8:2 7:3 6:4 5:5 4:6 3:7 2:8 1:9
    // 1:9 2:8 3:7 4:6 5:5 6:4 7:3 8:2 9:1 10:0
    // 10:0 9:1 8:2 7:3 6:4 5:5 4:6 3:7 2:8 1:9
}