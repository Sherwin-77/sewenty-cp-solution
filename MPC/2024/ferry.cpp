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

// Alternative
typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int testCases;
    cin >> testCases;
    while (testCases--) {
        /**
         * If there are more than n, those that have been waiting the longest are loaded
         * If there are no cars waiting on either bank, the ferry waits until one arrives,
         * loads it (if it arrives on the same bank of the ferry), and crosses the river
         * n - max cars to cross
         * t - time to cross the river
         * m - number of cars
         */
        queue<pair<int, int>> leftBank;
        queue<pair<int, int>> rightBank;
        bool ferryIsAtLeftBank = true;
        int runningTime = 0;
        int n, t, m;
        int tmp;
        string bank;
        cin >> n >> t >> m;
        vector<int> arriveTime(m, 0);
        for (int i = 0; i < m; i++) {
            cin >> tmp >> bank;
            if (bank == "left") {
                leftBank.push({i, tmp});
            } else {
                rightBank.push({i, tmp});
            }
        }
        // int maxIteration = 10;
        while (!leftBank.empty() || !rightBank.empty()) {
            int availableLoad = n;
            bool isLoading = false;
            if (ferryIsAtLeftBank) {
                while (!leftBank.empty() && leftBank.front().second <= runningTime && availableLoad > 0) {
                    arriveTime[leftBank.front().first] = runningTime + t;
                    leftBank.pop();
                    isLoading = true;
                    availableLoad--;
                }
                if (isLoading) {
                    runningTime += t;
                    ferryIsAtLeftBank = !ferryIsAtLeftBank;
                } else {
                    bool moveBank = leftBank.empty() || (!rightBank.empty() && leftBank.front().second > rightBank.front().second);
                    if (moveBank) {
                        if(!rightBank.empty() && rightBank.front().second > runningTime){
                            runningTime = rightBank.front().second;
                        }
                        runningTime += t;
                        ferryIsAtLeftBank = !ferryIsAtLeftBank;
                        continue;
                    } else {
                        runningTime = leftBank.front().second;
                    }
                }
            } else {
                while (!rightBank.empty() && rightBank.front().second <= runningTime && availableLoad > 0) {
                    arriveTime[rightBank.front().first] = runningTime + t;
                    rightBank.pop();
                    isLoading = true;
                    availableLoad--;
                }
                if (isLoading) {
                    runningTime += t;
                    ferryIsAtLeftBank = !ferryIsAtLeftBank;
                } else {
                    bool moveBank = rightBank.empty() || (!leftBank.empty() && rightBank.front().second > leftBank.front().second);
                    if (moveBank) {
                        if(!leftBank.empty() && leftBank.front().second > runningTime){
                            runningTime = leftBank.front().second;
                        }
                        runningTime += t;
                        ferryIsAtLeftBank = !ferryIsAtLeftBank;
                        continue;
                    } else {
                        runningTime = rightBank.front().second;
                    }
                }
            }
            // if (maxIteration-- == 0) break;
        }
        for (int i = 0; i < m; i++) {
            cout << arriveTime[i] << '\n';
        }
        if(testCases) cout << '\n';
    }
}