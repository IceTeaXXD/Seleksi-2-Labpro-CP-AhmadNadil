#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M, K;
    cin >> N >> M >> K;
    vector<vector<long long>> table (N+1, vector<long long>(K+1, 0));

    // Base case
    for(int i = 1; i <= N; i++){
        table[i][0] = M;
    }

    // Recursive
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            table[i][j] = (table[i-1][j-1] * (M-1)) % 998244353;
            table[i][j] = (table[i][j] + table[i-1][j]) % 998244353;
        }
    }

    cout << table[N][K] % 998244353 << endl;
    return 0;
}