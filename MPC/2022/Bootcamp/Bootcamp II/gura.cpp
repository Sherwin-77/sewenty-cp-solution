#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    vector<char> arr;
    for(char c: s){
        if(c == '+') continue;
        arr.push_back(c);
    }
    sort(arr.begin(), arr.end());
    bool first = true;
    for(auto i: arr){
        if(first){
            cout << i;
            first = false;
        } else cout << '+' << i;
    }
}
