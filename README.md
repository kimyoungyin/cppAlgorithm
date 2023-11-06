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
    string s = "안녕하세요 반갑습니다!", d = " ";
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

## sort(): 배열 혹은 벡터 정렬

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    // 컨테이너들의 요소를 정렬하기: sort
    // sort(): 보통 array or vector 정렬 시에 쓰임. O(nlogn)
    // sort(first, last, *커스텀비교함수)
    // - 커스텀비교함수
    // 0. 기본은 오름차순(커스텀비교함수를 넣지 않았을 때)
    // 1. greater<타입>()을 넣어 내림차순 변경 가능
    // 2. less<타입>()을 넣어 오름차순 정렬
    cout << "배열 정렬"
         << "\n";
    int b[5];
    for (int i = 0; i < 5; i++) {
        b[4 - i] = i;
    }
    for (int i = 0; i < 5; i++)
        cout << b[i] << " ";
    cout << "\n";
    // 오름차순
    sort(b, b + 5);
    for (int i = 0; i < 5; i++)
        cout << b[i] << " ";
    cout << "\n";
    // 내림차순
    sort(b, b + 5, greater<int>());
    for (int i = 0; i < 5; i++)
        cout << b[i] << " ";
    cout << "\n\n";

    cout << "벡터 정렬"
         << "\n";
    vector<int> v;
    for (int i = 5; i >= 1; i--)
        v.push_back(i);
    for (int i : v)
        cout << i << " ";
    cout << "\n";
    sort(v.begin(), v.end());
    for (int i : v)
        cout << i << " ";
    cout << "\n";
    sort(v.begin(), v.end(), greater<int>());
    for (int i : v)
        cout << i << " ";
    cout << "\n";
    return 0;
    // 배열 정렬
    // 4 3 2 1 0
    // 0 1 2 3 4
    // 4 3 2 1 0

    // 벡터 정렬
    // 5 4 3 2 1
    // 1 2 3 4 5
    // 5 4 3 2 1
}
```

## `sort()` 후, `erase(unique())`로 벡터의 중복 제거하기 
```cpp
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
```

## `lower_bound()`, `upper_bound()`로 정렬된 배열의 특정 요소 시작 지점, 초과 지점 찾기
```cpp
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
```

## `accumulate()`, `max_element()`, `min_element()`: 배열에서 합, 최대값, 최소값 얻기
```cpp
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
```

# 자료구조
## `vector`
> `vector<타입> 변수명;`
- 동적 배열
- 컴파일 시점에 사용할 요소들의 개수를 모르면 vector를 써야 함
- '연속된 메모리 공간'에 위치한 '같은 타입'의 요소들의 모음
- 숫자 인덱스 기반으로 랜덤 접근 가능
- 중복 허용
- O(1): 탐색, 맨 뒤 요소 삭제 및 삽입
- O(n): 그 외 요소 삭제 및 삽입

### 함수([from,to))
1. `push_back()`: 뒤에서부터 요소 더함
2. `pop_back()`: 맨 뒤 요소 지움
3. `erase()`: 한 요소만 지운다(`vector.erase(position)`), 범위를 지운다(`vector.erase(from, to)`)
4. `find(from, to, value)`: 메서드 아님, STL 함수, 처음 찾는 요소를 가리키는 이터레이터 반환
5. `clear()`: 모든 요소를 지움
6. `fill(from, to, value)`: 일정 범위 혹은 전체 요소를 `value`로 초기화

### 범위 기반 for 루프
```cpp
for(<컨데이너가 들어있는 타입>) 임시 변수명: 컨테이너)
```

### vector의 정적 할당
- 크기가 0인 빈 vector가 아니라 특정 크기로 정해놓고 시작하고 싶을 때
- 물론 크기 고정은 안된다
```cpp
vector<int> v(5, 100); // 크기를 5, 값은 100으로 초기화
vector<int> v{10, 20, 30, 40, 50}; 
```

### 2차원 벡터
- 3가지 방법이 있다
```cpp
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
```
