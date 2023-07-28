#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    deque<int> pembalap(n);
    for (int i = 0; i < n; i++) {
        cin >> pembalap[i];
    }

    vector<int> tukar(q);
    for (int i = 0; i < q; i++) {
        cin >> tukar[i];
    }

    vector<deque<int>> query(q);
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < tukar[i]; j++) {
            int temp;
            cin >> temp;
            query[i].push_back(temp);
        }
    }

    for (int i = 0 ; i < q ; i++){
        while (!query[i].empty()){
            int first = query[i].front() - 1;
            int last = query[i].back() - 1;
            if (first == last){
                if (query[i].size() == 1){
                    pembalap.erase(pembalap.begin() + first);
                    break;
                } else {
                    query[i].pop_front();
                    query[i].pop_back();
                    continue;
                }
            } else {
                int temp = pembalap[first];
                pembalap[first] = pembalap[last];
                pembalap[last] = temp;
                query[i].pop_front();
                query[i].pop_back();
            }
        }
    }

    if (pembalap.empty()) {
        cout << "Tidak ada pemenang" << endl;
    } else {
        cout << pembalap.size() << " " << pembalap[0] << endl;
    }

    return 0;
}
