#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "ECUST";
    for (int S = 0; S <= (1 << 5) - 1; S++) {
        for (int i = 0; i < 5; i++) {
            if (S & (1 << (4 - i)))
                cout << (char)(s[i] - 'A' + 'a');
            else
                cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}