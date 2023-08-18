#include <bits/stdc++.h>
using namespace std;
int main() {
    // 정렬된 배열에서 어떤 값이 나오는 첫 번째 지점 혹은 초과하는 지점의 위치를
    // 찾으려면
    // lower_bound(처음, 끝, 찾는 값): 어떤 값이 나오는 첫 번째 지점
    // 이터레이터 반환
    // upper_bound(처음, 끝, 찾는 값): 어떤 값이 초과하는 첫
    // 번째 지점 이터레이터 반환
    vector<int> v{1, 3, 5, 3, 2, 2, 5};
    sort(v.begin(), v.end());
    cout << "정렬된 배열"
         << "\n";
    for (int i : v)
        cout << i << " ";
    cout << "\n";
    cout << lower_bound(v.begin(), v.end(), 3) - v.begin() << "\n";
    cout << upper_bound(v.begin(), v.end(), 3) - v.begin() << "\n";
    return 0;
    // 정렬된 배열
    // 1 2 2 3 3 5 5
    // 3
    // 5
}