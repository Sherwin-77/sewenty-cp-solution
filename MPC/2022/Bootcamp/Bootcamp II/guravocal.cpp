#include <iostream>
#include <cctype>
#include <unordered_set>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    unordered_set<char> hashmap({'a', 'o', 'y', 'e', 'u', 'i'});
    cin >> s;
    string res = "";
    for(int i = 0; i < s.size(); i++){
        s[i] = tolower(s[i]);
        if(hashmap.find(s[i]) != hashmap.end()) continue;
        res += '.';
        res += s[i];
    }
    cout << res;
}
