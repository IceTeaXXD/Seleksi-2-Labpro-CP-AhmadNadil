#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> num(4);
    for(int i = 0; i < 4; i++){
        cin >> num[i];
    }
    for (int i = 0 ; i < 3 ; i++){
        sort(num.begin(), num.end());
        char op;
        cin >> op;
        if (op == '+'){
            int a = num.back();
            num.pop_back();
            int b = num.back();
            num.pop_back();
            int c = a + b;
            num.push_back(c);
        } else if (op == '*'){
            int a = num.front();
            num.pop_front();
            int b = num.front();
            num.pop_front();
            int c = a * b;
            num.push_front(c);
        }
    }
    cout << num.front() << endl;
    return 0;
}