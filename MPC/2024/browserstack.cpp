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
typedef unsigned long long ull;

const ll DEFAULTMOD = 1000000007;

signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int t;
    cin >> t;
    int n = t;
    while(t--) {
        cout << "Case " << n - t << ":\n";
        stack<string> front;
        stack<string> back;
        string current = "http://www.lightoj.com/";
        string cmd;
        string arg;
        while(true) {
            cin >> cmd;
            if (cmd == "VISIT") {
                cin >> arg;
                back.push(current);
                current = arg;
                front = stack<string>();
                print(current);
            } else {
                if (cmd == "QUIT") {
                    break;
                }
                if (cmd == "BACK") {
                    if (!back.empty()) {
                        front.push(current);
                        current = back.top();
                        back.pop();
                        print(current);
                    } else {
                        print("Ignored");
                    }
                } else {
                    if (!front.empty()) {
                        back.push(current);
                        current = front.top();
                        front.pop();
                        print(current);
                    } else {
                        print("Ignored");
                    }
                }
            }
        }
        
    }
}