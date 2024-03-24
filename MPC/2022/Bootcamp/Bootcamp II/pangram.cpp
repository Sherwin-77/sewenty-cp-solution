#include <iostream>
#include <vector>
#include <cctype>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<bool> exist(26, false);
    int n;
    cin >> n;
    if(n < 26){
        cout << "NO";
        return 0;
    }
    string s;
    cin >> s;
    for(char c: s){
        int i = tolower(c) - 'a';
        exist[i] = true;
    }
    for(bool b: exist){
        if(!b){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
