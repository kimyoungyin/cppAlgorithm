#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 50;
int a[MAX_N];
int b[MAX_N][MAX_N];
int main() {
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