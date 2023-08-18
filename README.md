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

# 프로세스 메모리 구조와 정적할당, 동적할당

## 운영체제의 프로세스에 메모리 할당

-   스택(stack)

    -   위 주소부터 할당
    -   지역변수, 매개변수, 함수 저장
    -   컴파일 시에 크기 결정
    -   런타임 시에도(함수 호출 등) 크기 결정(동적인 특징)

-   힙(heap)
    -   아래 주소부터 할당
    -   동적 할당 시 사용됨
    -   런타임 시 크기 결정(동적인 특징)
-   데이터 영역(BSS segnemt, Data segment)

    -   BSS 영역 + Data 영역
    -   정적 할당에 관한 부분(정적인 특징)

-   코드 영역(code segment)
    -   소스코드 들어감(정적인 특징)

## 정적 할당: 컴파일 단계에서 메모리를 할당

-   BSS segment, Data segment, code/text segment로 나뉘어 저장됨
    -   BSS segment: 전역변수, static, const로 선언된 변수 중 0 혹은 초기화되지 않은 변수들이 이 메모리 영역에 할당
    -   Data segment: 전역변수, static, const로 선언된 변수 중 0이 아닌 값으로 초기화된 변수가 이 메모리 영역에 할당
    -   code/text segment: 프로그램의 코드

## 동적 할당: 런타임 단계에서 메모리를 할당

-   Stack, Heap
    -   Stack: 지역변수, 매개변수, 실행되는 함수에 의해 늘어나거나 줄어듦. 함수가 호출될 때마다 호출될 때 환경 등 특정 정보가 stack에 계속해서 저장
    -   Heap: 동적으로 할당되는 변수를 담음. `malloc()`, `free()` 함수를 통해 관리할 수 있으며 동적으로 관리되는 자료구조는 이 영역을 사용함(예: `vector`).

# 함수: 코딩 테스트에 자주 나오는

##   `fill()`과 `memset()`: 배열 초기화. `fill()`을 주로 사용
-  `fill()`: 모든 숫자로 초기화 가능, O(n)

    -   메모리 주소로 초기화하기

        ```cpp
        #include <bits/stdc++.h>
        using namespace std;
        int a[10];
        int b[10][10];
        int main() {
            // void fill(시작 메모리 주소, 끝+1 메모리 주소, 초기화 값)
            fill(&a[0], &a[10], 100);

            for(int i = 0; i < 10; i++){
                cout << a[i] " ";
            }
            cout << "\n";
            fill(&b[0][0], &b[9][10], 2);
            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    cout << b[i][j] << " ";
                }
                cout << "\n";
            }
            return 0;
        }
        ```

    -   배열의 이름(배열 시작 주소)으로 시작하기: 1차원 배열만 가능(2차원은 불가)
        ```cpp
        #include <bits/stdc++.h>
        using namespace std;
        int a[10];
        int b[10][10];
        int main() {
            fill(a, a + 10, 100);
            for (int i = 0; i < 10; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
            fill(&b[0][0], &b[0][0] + 10 * 10, 2);
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    cout << b[i][j] << " ";
                }
                cout << "\n";
            }
            return 0;
        }
        ```
    > 주의: 배열의 크기보다 작은 정사각형 요소만 초기화 할 수 없다. 
    > 
    >1열 => 2열 => 3열 순으로 초기화가 진행되기 때문에!
-   `memset()`: 0, -1, char으로만 초기화 가능
    ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    const int MAX_N = 50;
    int a[MAX_N];
    int b[MAX_N][MAX_N];
    int main() {
        // void(배열 이름, 초기화 값, sizeof(배열 이름));
        memset(a, -1, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 0; i < MAX_N; i++)
            cout << a[i] << " ";
        cout << "\n";
        for (int i = 0; i < MAX_N; i++) {
            for (int j = 0; j < MAX_N; j++) {
                cout << b[i][j] << " ";
            }
            cout << "\n";
        }
        return 0;
    }               
    ```



## `memcpy()`와 `copy()`: 배열 혹은 벡터 초기화
```cpp
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
```