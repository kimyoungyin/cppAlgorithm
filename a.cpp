#include <bits/stdc++.h>
using namespace std;
int main() {
    // unique: 앞 요소부터 중복 부분만 제거하면서 채워나가고, 나머지 자리에는
    // 기존의 원소가 채워진다.
    //
    // unique(start, end) => 유니크한 요소 바로 다음 기존과 동일한 요소의 시작
    // 이터레이터 반환
    //
    // O(n)
    //
    // vector.erase(시작, 끝): [시작, 끝) 범위가 삭제 이 두 함수를 통해 유니크한
    // 벡터를 반환할 수 있다.

    vector<int> v;
    for (int i = 1; i <= 5; i++) {
        v.push_back(i);
        v.push_back(i);
    }
    for (int i : v)
        cout << i << " ";
    cout << "\n";
    auto nextIterator = unique(v.begin(), v.end());
    for (int i : v)
        cout << i << " ";
    cout << "\n";
    // unique와 erase를 동시 사용(추천)
    // v.erase(unique(v.begin(), v.end()), v.end());
    v.erase(nextIterator, v.end());
    for (int i : v)
        cout << i << " ";
    cout << "\n";
    return 0;
    // 1 1 2 2 3 3 4 4 5 5
    // 1 2 3 4 5 3 4 4 5 5
    // 1 2 3 4 5
}