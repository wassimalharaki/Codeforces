#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    loop(i, 0, n) {
        int a;
        cin >> a;
        if (a == 1) {
            cout << "HARD";
            return 0;
        }
    }
    cout << "EASY";

    return 0;
}