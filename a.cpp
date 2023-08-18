#include <bits/stdc++.h>
using namespace std;
int main() {
    int v[3] = {1, 2, 3};
    int ret[3];
    // memcpy: Array만 깊은 복사 가능
    // void memcpy(복사할 배열 이름(포인터), 원본 배열 이름(포인터), 복사할
    // 데이터의 길이)
    memcpy(ret, v, sizeof(v));
    cout << ret[1] << "\n";
    ret[1] = 100;
    cout << "복사하고 변경된 사본: " << ret[1] << "\n";
    cout << "원본은 그대로인 " << v[1] << "\n";
    return 0;
}