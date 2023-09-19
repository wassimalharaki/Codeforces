#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, student, count;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> student;
        if (student + k <= 5)
            count++;
    }

    cout <<  count / 3;

    return 0;
}