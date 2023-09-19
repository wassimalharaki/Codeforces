#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2, s3 = "";
    cin >> s1 >> s2;

    loop(i, 0, s1.length()) {
        if (s1[i] == s2[i])
            s3 += '0';
        else
            s3 += '1';
    }

    cout << s3;

    return 0;
}