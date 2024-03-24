#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// #define int long long

void fileIO(string fileName, string inExt = ".in", string outExt = ".out") {
    string fIn = fileName + inExt;
    string fOut = fileName + outExt;
    freopen(fIn.c_str(), "r", stdin);
    freopen(fOut.c_str(), "w", stdout);
}

template <typename T>
void debug(T const &value, std::string valueName) {
    cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}
template <typename T>
void debug(T const &value, std::string valueName, int index) {
    cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}

template <typename T>
void print(T const &value, bool newLine = true) {
    cout << value;
    if (newLine) cout << '\n';
}

bool checkComparison(string opening, string closing) {
    if (opening == "(" && closing == ")") return true;
    if (opening == "[" && closing == "]") return true;
    if (opening == "{" && closing == "}") return true;
    if (opening == "<" && closing == ">") return true;
    if (opening == "(*" && closing == "*)") return true;
    return false;
}

// Alternative
typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    string s;
    while (cin >> s) {
        stack<string> last;
        bool isStar = false;
        bool isValid = true;
        // bool outside = false;
        int offset = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<') {
                last.push(string(1, s[i]));
                isStar = false;
                continue;
            } else if (s[i] == ')' || s[i] == ']' || s[i] == '}' || s[i] == '>') {
                string toCompare = string(1, s[i]);
                if (isStar && toCompare == ")") {
                    toCompare = "*)";
                    offset++;
                }
                isStar = false;
                if (last.empty() || !checkComparison(last.top(), toCompare)) {
                    cout << "NO " << i - offset + 1 << '\n';
                    isValid = false;
                    break;
                } else {
                    last.pop();
                    continue;
                }
            }
            isStar = s[i] == '*';
            if (isStar && i > 0 && s[i - 1] == '(') {
                last.pop();
                last.push("(*");
                isStar = false;
                offset++;
            }
        }
        if (isValid) {
            if (!last.empty())
                cout << "NO " << s.length() - offset + 1 << '\n';
            else
                cout << "YES\n";
        }
    }
}