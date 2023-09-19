#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s = "I hate ";
    loop(i, 1, n) {
        s += "that I ";
        if (i % 2 == 0)
            s += "hate ";
        else
            s += "love ";
    }
    s += "it";
    cout << s;

    return 0;
}