#include <bits/stdc++.h>
using namespace std;
int main() {
    // unique: 앞 요소부터 바로 옆과 비교하여 중복 부분만 제거하면서 채워나가고,
    // 나머지 자리에는 기존의 원소가 채워진다.
    //
    // unique(start, end) => 유니크한 요소 바로 다음 기존과 동일한 요소의 시작
    // 이터레이터 반환
    //
    // O(n)
    //
    // vector.erase(시작, 끝): [시작, 끝) 범위가 삭제 이 두 함수를 통해 유니크한
    // 벡터를 반환할 수 있다.
    //
    // unique는 바로 옆이랑만 비교하므로, 꼭 sort()로 정리한 후 시작하자.

    // sort를 사용하지 않았을 때
    vector<int> v1{4, 3, 3, 5, 1, 2, 3};
    cout << "원본\n";
    for (int i : v1)
        cout << i << " ";
    cout << "\n";
    v1.erase(unique(v1.begin(), v1.end()), v1.end());
    cout << "sort를 사용하지 않는다면\n";
    for (int i : v1)
        cout << i << " ";
    cout << "\n";
    // sort 후
    // v.erase(unique(v.begin(), v.end()), v.end());
    vector<int> v2{4, 3, 3, 5, 1, 2, 3};
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    cout << "sort를 사용한다면\n";
    for (int i : v2)
        cout << i << " ";
    cout << "\n";

    return 0;
}