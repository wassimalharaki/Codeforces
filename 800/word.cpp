#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string word;
    int lower = 0;
    int upper = 0;
    cin >> word;

    loop(i, 0, word.length()) {
        if (islower(word[i]))
            lower++;
        else
            upper++;
    }

    if (upper > lower)
        loop(i, 0, word.length())
            word[i] = toupper(word[i]);
    else
        loop(i, 0, word.length())
            word[i] = tolower(word[i]);

    cout << word;

    return 0;
}