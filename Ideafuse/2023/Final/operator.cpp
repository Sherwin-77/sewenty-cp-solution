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

template <typename T>
void debug(T const &value, std::string valueName) {
    cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}
template <typename T>
void debug(T const &value, std::string valueName, int index) {
    cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value
         << '\n';
}

template <typename T>
void print(T const &value, bool newLine = true) {
    cout << value;
    if (newLine) cout << '\n';
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == ':' || c == '*') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

// Alternative
typedef long long ll;
int digitCount(ll num) {
    int count = 1;
    if(num < 0) count++;
    num /= 10;
    while (abs(num) > 0) {
        num /= 10;
        count++;
    }
    return count;
}

void printCur(vector<ll> &num, vector<char> &op, int activeOp) {
    for (int i = 0; i < num.size(); i++) {
        if (i > 0) cout << op[i - 1];
        cout << num[i];
    }
    cout << '\n';
    for (int i = 0; i < num.size(); i++) {
        if (i > 0) {
            cout << (i - 1 == activeOp ? '-' : '.');
        }
        if (i == activeOp || i == activeOp + 1)
            cout << string(digitCount(num[i]), '-');
        else
            cout << string(digitCount(num[i]), '.');
    }
    cout << '\n';
}
void printCur(deque<ll> &num, deque<char> &op, int activeOp) {
    for (int i = 0; i < num.size(); i++) {
        if (i > 0) cout << op[i - 1];
        cout << num[i];
    }
    cout << '\n';
    for (int i = 0; i < num.size(); i++) {
        if (i > 0) {
            cout << (i - 1 == activeOp ? '-' : '.');
        }
        if (i == activeOp || i == activeOp + 1)
            cout << string(digitCount(num[i]), '-');
        else
            cout << string(digitCount(num[i]), '.');
    }
    cout << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    string s;
    cin >> s;
    vector<ll> num;
    vector<char> op;
    deque<char> dq;
    deque<ll> outputs;
    string builder = "";
    bool tryCatch = false;
    bool unary = false;
    int pos = 0;
    int priority = 0;
    for (char c : s) {
        if (isdigit(c)) {  // Is number
            builder += c;
            tryCatch = false;
        } else {  // Operator / unary
            if (builder.length() > 0) {
                num.push_back((unary ? -1 : 1) * stoll(builder));
                builder.clear();
                unary = false;
                // debug(num.front(), "Number");
                pos++;
            }
            if (c == '-') {
                if (pos == 0 || tryCatch) unary = true;
                else {
                    // debug(c, "PUSH");
                    op.push_back(c);
                }
            } else {
                // debug(c, "PUSH");
                op.push_back(c);
            }
            if (precedence(c) == 2) priority++;
            else if(!unary) dq.push_back(c);
            tryCatch = true;
        }
    }
    if (builder.length() > 0) {
        num.push_back((unary ? -1 : 1) * stoll(builder));
        pos++;
    }
    while(priority--){
        for(int i = 0; i < op.size(); i++){
            if(precedence(op[i]) == 2){
                printCur(num, op, i);
                if(op[i] == ':'){
                    num[i] /= num[i+1];
                } else if(op[i] == '*') {
                    num[i] *= num[i+1];
                }
                num.erase(num.begin()+i+1);
                op.erase(op.begin()+i);
                break;
            } 
        }
    }
    for(auto x: num) outputs.push_back(x);
    while(!dq.empty()){
        printCur(outputs, dq, 0);
        if(dq[0] == '+'){
            outputs[1] += outputs[0];
        } else if(dq.front() == '-'){
            outputs[1] = outputs[0] - outputs[1];
        }
        outputs.pop_front();
        dq.pop_front();
    }
    cout << outputs.front();
}