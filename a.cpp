#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    double b;
    char c;
    // 받는 변수에는 &가 필요
    scanf("%d %lf %c", &a, &b,&c); // scanf(형식, ...받는 인풋들)
    printf("%d ",a); 
    printf("%lf ",b);
    printf("%c",c);
    
    cout << "\n";
   
    // scanf로 실수타입을 정수 타입으로 받아보기
    int e, f;
    scanf("%d.%d", &e, &f);
    printf("%d.%d이 분리되어 %d와 %d로!", e,f,e,f);
    
    cout << "\n";

    string g;
    // 개행 문자까지 한 번에 받기
    getline(cin, g);
    cout << g << "\n";
    return 0;
}