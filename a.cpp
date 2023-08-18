#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v = {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
    for (int i : v)
        cout << i << " ";
    cout << "\n";
    // 합 = accumulate(시작, 끝, 초기값)
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << "\n";

    // 최대값 이터레이터 = max_element(시작, 끝)
    int a = *max_element(v.begin(), v.end()); // 최대값
    auto b = max_element(v.begin(), v.end()); // 이터레이터
    cout << "최대값은 " << a << "\n";
    // 이터레이터 - 이터레이터 = 인덱스
    cout << "최대값의 인덱스는 " << b - v.begin() << "\n";

    // 최소값 이터레이터 = min_element(시작, 끝)
    int c = *min_element(v.begin(), v.end()); // 최대값
    auto d = min_element(v.begin(), v.end()); // 이터레이터
    cout << "최소값은 " << c << "\n";
    // 이터레이터 - 이터레이터 = 인덱스
    cout << "최소값의 인덱스는 " << d - v.begin() << "\n";
    return 0;
    // 1 2 3 4 5 10 9 8 7 6
    // 55
    // 최대값은 10
    // 최대값의 인덱스는 5
    // 최소값은 1
    // 최소값의 인덱스는 0
}