#include <bits/stdc++.h>
using namespace std;
int answer[26];
string str;
// https://www.acmicpc.net/problem/10808
int main() {
    fill(answer, answer + 26, 0);
    cin >> str;
    for (char c : str)
        answer[(int)c - 97]++;
    for (int i : answer)
        cout << i << " ";
    cout << "\n";
    return 0;
}