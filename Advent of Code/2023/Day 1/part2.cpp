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
    cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}

template <typename T>
void print(T const &value, bool newLine = true) {
    cout << value;
    if (newLine) cout << '\n';
}

// Alternative
typedef long long ll;

struct Node {
    struct Node *children[26];
    bool isEnd;
};

struct Node *getNode(void) {
    struct Node *pNode = new Node;

    pNode->isEnd = false;

    for (int i = 0; i < 26; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(struct Node *root, string key) {
    struct Node *pCrawl = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEnd = true;
}
pair<bool, bool> search(struct Node *root, string key) {
    struct Node *pCrawl = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return {false, false};

        pCrawl = pCrawl->children[index];
    }
    return {true, pCrawl->isEnd};
}

string toStr(deque<char> arr) {
    return string(arr.begin(), arr.end());
}

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    string keys[] = {"one", "two", "three",
                     "four", "five", "six",
                     "seven", "eight", "nine"};
    string backKeys[] = {"eno", "owt", "eerht",
                         "ruof", "evif", "xis",
                         "neves", "thgie", "enin"};
    unordered_map<string, ll> hm = {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}};
    unordered_map<string, ll> hhm = {
        {"eno", 1},
        {"owt", 2},
        {"eerht", 3},
        {"ruof", 4},
        {"evif", 5},
        {"xis", 6},
        {"neves", 7},
        {"thgie", 8},
        {"enin", 9}};
    int n = sizeof(keys) / sizeof(keys[0]);
    struct Node *root = getNode();
    struct Node *backRoot = getNode();
    for (int i = 0; i < n; i++) {
        insert(root, keys[i]);
        insert(backRoot, backKeys[i]);
    }

    ll total = 0;
    string s;
    while (cin >> s) {
        // print(s);
        int left = 0;
        int right = s.length() - 1;
        string builder = "";
        bool leftDone = false;
        bool rightDone = false;
        deque<char> curLeft;
        deque<char> curRight;
        while (!isdigit(s[left]) && left < s.length()) {
            curLeft.push_back(s[left]);
            string cur = toStr(curLeft);
            auto [floatingProfit, takeProfit] = search(root, cur);
            while (!floatingProfit && !curLeft.empty()) {
                curLeft.pop_front();
                cur = toStr(curLeft);
                auto [newProfit, tp] = search(root, cur);
                floatingProfit = newProfit;
                takeProfit = tp;
            }
            if (takeProfit) {
                auto res = hm.find(cur);
                // print(cur);
                // print(res == hm.end());
                if (res == hm.end()) terminate();
                builder += to_string(res->second);
                leftDone = true;
                break;
            }
            left++;
        }
        if (!leftDone && isdigit(s[left])) builder += s[left];
        while (!isdigit(s[right]) && right >= 0) {
            curRight.push_back(s[right]);
            string cur = toStr(curRight);
            auto [floatingProfit, takeProfit] = search(backRoot, cur);
            while (!floatingProfit && !curRight.empty()) {
                curRight.pop_front();
                cur = toStr(curRight);
                auto [newProfit, tp] = search(backRoot, cur);
                floatingProfit = newProfit;
                takeProfit = tp;
            }
            if (takeProfit) {
                auto res = hhm.find(cur);
                if (res == hhm.end()) terminate();
                builder += to_string(res->second);
                rightDone = true;
                break;
            }
            right--;
        }
        if (!rightDone && isdigit(s[right])) builder += s[right];
        total += stoll(builder);
        if(total < 0) terminate();
    }
    cout << total;
}