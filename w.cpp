#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int w = 0;
    int a = 0;
    int d = 0;
    int u = 0;
    int h = 0;
    vector<string> s(n);
    for (int i = 0 ; i < n ; i++){
        cin >> s[i];
    }
    for (int i = 0 ; i < n ; i++){
        for (auto c : s[i]){
            if (c == 'w'){
                w++;
            }
            else if (c == 'a'){
                a++;
            }
            else if (c == 'd'){
                d++;
            }
            else if (c == 'u'){
                u++;
            }
            else if (c == 'h'){
                h++;
            }
        }
    }

    int ans = 0;
    while (w >= 1 && a >= 1 && d >= 1 && u >= 1 && h >= 1){
        ans++;
        w--;
        a--;
        d--;
        u--;
        h--;
    }
    cout << ans << endl;

    return 0;
}