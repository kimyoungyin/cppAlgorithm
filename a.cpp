#include <bits/stdc++.h>
using namespace std;
vector<int> v = {1, 5, 100, 3, 7};

void printV(vector<int> v, int r) {
    for (int i = 0; i < r; i++) {
        cout << v[i] << " ";
    }
    cout << '\n';
}
void p(int n, int r, int depth = 0) {
    if (r == depth) {
        printV(v, r);
        return;
    }

    for (int i = depth; i < n; i++) {
        swap(v[i], v[depth]);
        p(n, r, depth + 1);
        swap(v[i], v[depth]);
    }
    return;
}

int main() {
    p(5, 2);
    return 0;
}