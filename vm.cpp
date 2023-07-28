#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    int n;
    map<char, int> m;
    cin >> n;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        m[c]++;
    }
    int max = 0;
    char max_char;
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second > max){
            max = it->second;
            max_char = it->first;
        }
    }
    cout << max_char << endl;
}
