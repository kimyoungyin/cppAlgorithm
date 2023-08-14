# 타입

## void

## char: 문자

## string: 문자열

영어: 1글자 = 1바이트
한글: 1글자 = 3바이트
기본 메서드: `begin()`, `end()`, `size()`, `insert(위치, 문자열)`, `erase(위치, 크기)`. `pop_back()`, `find(문자열)`, `substr(위치, 크기)`, `reverse()`

만들어야 하는 메서드: `split()`

    ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    vector<string> split(string input, string delimiter) {
        vector<string> ret;
        long long pos = 0;
        string token = "";
        while ((pos = input.find(delimiter)) != string::npos) {
            token = input.substr(0, pos);
            ret.push_back(token);
            input.erase(0, pos + delimiter.length());
        } ret.push_back(input); return ret;
    }

    int main(){
        string s = "안녕하세요 큰돌이는 킹갓제너럴 천재입니다 정말이에요!", d = " ";
        vector<string> a = split(s, d);
        for(string b : a) cout << b << "\n";
    }
    ```

## bool: 참과 거짓(1 or 0)

## int: 4바이트 정수

int끼리 계산한 경우 소수점 아래 수는 모두

## long long: 8바이트짜리 정수

## double: 실수

float보다 정확하므로 이걸 쓰자

## unsigned long long: 8바이트짜리 '양'의 정수

## (추가)pair, tuple

-   pair: 두 변수를 가지는 클래스, 두 가지 값을 담을 떄 사용
-   tuple: 세 변수 이상을 가지는 클래스, 세 값 이상을 담을 떄 사용

```cpp
// 만들기
pair<int, int> pi;
tuple<int, int, int> tl;
int main() {
    pi = {1, 2};
    // 혹은 pi = make_pair(1, 2)
    tl = {1, 2, 3};
    // 혹은 pi = make_tuple(1, 2, 3)


    // 값 끄집어내기
    tie(a, b) = pi
    // 혹은 a = pi.first
    tie(a, b, c) = tl
    // 혹은 a = get<0>(ti)
}
```

## auto: 타입 추론

## 타입 변환: `(바꿀 타입)기존 변수`

    같은 타입으로 변환 후 계산하는 것이 '맞왜틀'에서 벗어날 수 있는 방법

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    double ret = 2.12345;
    intn=2;
    int a = (int)round(ret / double(n)); cout << a << "\n";
    return 0;
}
```

```cpp
// vector의 경우 vector.size()는 unsigned int이므로 주희
// bad
int main(){
    vector<int> a = {1, 2, 3};
    cout << a.size() - 10 << '\n'; // 18446744073709551609
    return 0;
}
// good
int main(){
    vector<int> a = {1, 2, 3};
    cout << (int)a.size() - 10 << '\n'; // -7
    return 0;
}
```

# 포인터: 메모리 주소를 담는 타입

`&변수`: 변수의 메모리 주소

`int * 변수 = &i`: \*(에스터리스크, asterisk operator)와 함꼐 메모리 주소를 저장 가능. 이 때 변수가 '포인터'. (타입을 동일하게 해줘야 할 듯)

## 역참조

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a = "hello";
    string * b = &a;
    cout << b << "\n";
    cout << *b << "\n";
    return 0;
}
```
