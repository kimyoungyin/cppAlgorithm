#include <bits/stdc++.h>
using namespace std;
int main() {
    // 포인터와 역참조란
    string a = "hello";
    string * b = &a;
    cout << b << "\n"; 
    cout << *b << "\n";

    // array to pointer decay: 배열의 이름(변수)를 포인터에 할당하면 크기 정보 사라지고(decay) 첫 번째 요소의 주소가 바인딩됨
    // vector는 안돼용
    int d[3] = {1, 2, 3};
    int * c = d;
    cout << c << "\n"; // 배열의 첫 번째 요소의 메모리 주소
    cout << &d[0] << "\n"; // c와 같은 결과
    cout << c + 1 << "\n";
    cout << &d[1] << "\n";
    return 0; 
}