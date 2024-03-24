#include <iostream>
#include <cctype>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool exist[26];
    fill(exist, exist+26, false);
    int total = 0;
    const short offset = 97;
    for(auto c: s){
        // cout << int(c)-offset << '\n';
        c = tolower(c);
        exist[int(c)-offset] = true;
    }
    for(auto x: exist){
        if(!x){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
