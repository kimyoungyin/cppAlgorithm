#include <bits/stdc++.h>
using namespace std;
// 1. 타입으로 선언
vector<vector<int>> v;
// 2. 타입으로 선언 후 초기화까지
vector<vector<int>> v2(10, vector<int>(10, 0));
// 3. 1차원만 생성 후 이후 요소를 빈 배열로 채우기
vector<int> v3[10];
int main() {
    for (int i = 0; i < 10; i++) {
        // 빈 배열로 요소를 채우기
        vector<int> temp;
        v.push_back(temp);
    }
    return 0;
}