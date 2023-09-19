#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string word;
    cin >> word;

    word[0] = toupper(word[0]);

    cout << word;
    return 0;
}