#include <bits/stdc++.h>
using namespace std;

int main(){
    // input
    int n,cup;
    cin >> n >> cup;
    vector<int> arrPos(n);
    for (int i = 0; i < n; i++) {
        cin >> arrPos[i];
    }
    sort(arrPos.begin(), arrPos.end()); // sorting aquariumnya biar enak

    int ans = -1;
    int kiri = 1;
    int kanan = arrPos[n-1];

    // binary search
    while (kiri < kanan){
        int tengah = (kiri + kanan) / 2; // cari nilai tengahnya

        // ngecek apakah posisi tsb valid apa gak
        bool valid = false;
        int pos = arrPos[0];
        int l = 1;
        for (int i = 0 ; i < n ; i++){
            if (arrPos[i] - pos >= tengah){ // kalo jaraknya lebih dari mid, berarti bisa ditaro
                pos = arrPos[i];
                l++;
                if (l == cup){ // kalo udh cukup, berarti valid
                    valid = true;
                    break;
                }
            }
        }

        // kalo msh valid, berarti geser ke kanan lagi
        if (valid){
            ans = max(ans, tengah);
            kiri = tengah + 1;
        } else{
            kanan = tengah;
        }
    }

    cout << ans << endl;
    return 0;
}