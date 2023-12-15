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

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    string keys[] = {"one", "two", "three",
                     "four", "five", "six",
                     "seven", "eight", "nine"};
    int n = sizeof(keys) / sizeof(keys[0]);
    struct Node *root = getNode();
    for (int i = 0; i < n; i++) {
        insert(root, keys[i]);
    }
    auto [floatingProfit, takeProfit] = search(root, "tw");  // [1, 0]
    auto [floatingProfit2, takeProfit2] = search(root, "two");  // [1, 1]
}