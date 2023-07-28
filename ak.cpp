#include <iostream>
#include <vector>
using namespace std;

bool find(int m, vector<int>& uang) {
    // BASIS
    if (m == 0) {
        return true;
    }
    if (m < 0 || uang.empty()) {
        return false;
    }

    // REKURENS
    for (int i = 0; i < uang.size(); i++) {
        int curr = uang[i];
        uang.erase(uang.begin() + i);
        bool flag = find(m - curr, uang);
        uang.insert(uang.begin() + i, curr);
        if (flag) {
            return true;
        }
    }
    return false;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> uang(n);
    for (int i = 0; i < n; i++) {
        cin >> uang[i];
    }

    bool flag = find(m, uang);

    if (flag) {
        cout << "YA" << endl;
    } else {
        cout << "TIDAK" << endl;
    }

    return 0;
}
