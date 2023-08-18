#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v{1, 2, 3};
    vector<int> ret(3);
    // copy: 벡터, 배열 모두 깊은 복사 가능
    // copy(원본 시작 iterator, 원본 끝 이터레이터(마지막 + 1), 복사받는 시작
    // 이터레이터);
    // 1. 벡터 copy
    copy(v.begin(), v.end(), ret.begin());
    for (int i : ret)
        cout << i << " ";
    cout << "\n";
    ret[1] = 100;
    cout << "변경된 사본 벡터 1 인덱스 값: " << ret[1] << "\n";
    cout << "원본 벡터 1 인덱스 값: " << v[1] << "\n";

    // 2. 배열
    const int ARRAY_N = 3;
    int a[ARRAY_N] = {1, 2, 3};
    int retA[ARRAY_N];
    // copy(복사당할 배열 이름(시작 이터레이터), 복사당할 배열 끝 + 1, 복사할
    // 배열 이름(시작))
    copy(a, a + ARRAY_N, retA);
    for (int i : a)
        cout << i << " ";
    cout << "\n";
    retA[1] = 10;
    cout << "변경된 사본 배열 1 인덱스 값: " << retA[1] << "\n";
    cout << "원본 배열 1 인덱스 값: " << v[1] << "\n";

    return 0;
}