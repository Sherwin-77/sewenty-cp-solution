#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <string>

using namespace std;
// #define int long long

template <typename T>
void debug(T const &value, std::string valueName){
    cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}
template <typename T>
void debug(T const &value, std::string valueName, int index){
    cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}

template <typename T>
void print(T const &value, bool newLine=false){
    cout << value;
    if(newLine) cout << '\n';
}


// Alternative
typedef long long ll;


int pos[26] = {};
signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    fill_n(pos, 26, -1);
    int ans = -1;
    /*
    abcdeaefge
    abcde  
    abcd  e
        e  fge
          efge
    ========== (2nd)
    abcdeae 
    abcdea   e
    ========== (3rd)
    max length = start -> last occurence & currenct ocurence -> end
    */
    for(int i = 0; i < n; i++){
        char c = s[i];
        if(pos[c-'a'] != -1){
            ans = max(ans, pos[c-'a'] + (n-i));
        }
        pos[c-'a'] = i;
    }
    cout << ans;
}