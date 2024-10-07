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

void fileIO(string fileName, string inExt=".in", string outExt=".out"){
    string fIn = fileName + inExt;
    string fOut = fileName + outExt; 
    freopen(fIn.c_str(), "r", stdin);
    freopen(fOut.c_str(), "w", stdout);
}

template <typename T>
void debug(T const &value, std::string valueName){
    cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}
template <typename T>
void debug(T const &value, std::string valueName, int index){
    cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}

template <typename T>
void print(T const &value, bool newLine=true){
    cout << value;
    if(newLine) cout << '\n';
}


// Alternative
typedef long long ll;


signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    // R - Red, O - Orange, Y - Yellow, G - Green, B - Blue, I - Indigo, P - Purple
    deque<char> target;
    deque<char> destroyer;
    int m, n;
    char tmp;
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        cin >> tmp;
        target.push_back(tmp);
    }
    for(int i = 0; i < n; i++){
        cin >> tmp;
        destroyer.push_back(tmp);
    }
    while(!destroyer.empty() && !target.empty()){
        if(target.back() == destroyer.front()){
            char curDestroyer = destroyer.front();
            destroyer.pop_front();
            while(!target.empty() && target.back() == curDestroyer){
                target.pop_back();
            }
        } else {
            target.push_back(destroyer.front());
            destroyer.pop_front();
        }
    }
    cout << (target.empty() ? "MENANG" : "KALAH");
}