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
        print("Case " + to_string(n - t) + ":");
        int n, m;
        cin >> n >> m;
        deque<int> dq;
        for (int i = 0; i < m; i++) {
            string cmd;
            cin >> cmd;
            if (cmd == "pushLeft") {
                int x;
                cin >> x;
                if (dq.size() < n) {
                    dq.push_front(x);
                    print("Pushed in left: " + to_string(x));
                } else {
                    print("The queue is full");
                }
            } else if (cmd == "pushRight") {
                int x;
                cin >> x;
                if (dq.size() < n) {
                    dq.push_back(x);
                    print("Pushed in right: " + to_string(x));
                } else {
                    print("The queue is full");
                }
            } else if (cmd == "popLeft") {
                if (!dq.empty()) {
                    int x = dq.front();
                    dq.pop_front();
                    print("Popped from left: " + to_string(x));
                } else {
                    print("The queue is empty");
                }
            } else if (cmd == "popRight") {
                if (!dq.empty()) {
                    int x = dq.back();
                    dq.pop_back();
                    print("Popped from right: " + to_string(x));
                } else {
                    print("The queue is empty");
                }
            }
        }
    }
}