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


int highestBeforeX(vector<ll>& arr, ll x){
    int l = 0, r = arr.size()-1;
    while(l < r){
        int mid = l + (r-l+1)/2;
        if(arr[mid] > x){
            r = mid-1;
        }else{
            l = mid;
        }
    }
    return l;
}

int lowestAfterX(vector<ll>& arr, ll x){
    int l = 0, r = arr.size()-1;
    while(l < r){
        int mid = l + (r-l)/2;
        if(arr[mid] < x){
            l = mid+1;
        }else{
            r = mid;
        }
    }
    return l;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    vector<bool> isPrime(100001, true);
    vector<ll> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 100000; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 100000; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= 100000; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    vector<int> links(primes.size(), 0);
    vector<int> lengths(primes.size(), 1);

    for(int i = 0; i < primes.size(); i++) {
        links[i] = i;
    }
    for (int i = 2; i < primes.size(); i++) {
        if (primes[i] - primes[i - 1] == primes[i - 1] - primes[i - 2]) {
            links[i] = i - 1;
            if (links[i - 1] == i - 1) {
                links[i - 1] = i - 2;
                lengths[i - 1] = 2;
            }
            lengths[i] = lengths[links[i]] + 1;
        }
    }

    ll a, b;

    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        if (a > b) swap(a, b);
        ll start = lowestAfterX(primes, a);
        ll end = highestBeforeX(primes, b);
        
        vector<bool> marked(primes.size(), false);
        vector<pair<ll, deque<int>>> chains;
        for(int i = end; i >= start; i--) {
            if (lengths[i] >= 3 && !marked[i]) {
                marked[i] = true;
                deque<int> chain;
                int lastJ = i;
                if (links[i+1] == i && primes[i+1] - primes[i] == primes[i] - primes[i-1]) {
                    continue;
                }
                for (int j = i; j != links[j]; j = links[j]) {
                    marked[j] = true;
                    lastJ = j;
                    chain.push_front(primes[j]);
                    if (lengths[j] == 2) break;
                }
                int lowest = links[lastJ];
                if (lowest < start) {
                    continue;
                }
                chain.push_front(primes[lowest]);
                chains.push_back({primes[lowest], chain});
            }
        }
        sort(chains.begin(), chains.end(), [](const pair<ll, deque<int>>& a, const pair<ll, deque<int>>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second.size() < b.second.size();
        });
        for (auto chain : chains) {
            ll curDiff = chain.second[1] - chain.second[0];
            ll lastI = -1;
            for (int i : chain.second) {
                cout << i;
                if (i != chain.second.back()) {
                    cout << ' ';
                }
                if (lastI != -1) {
                    if (i - lastI != curDiff) {
                        terminate();
                    }
                }
                lastI = i;
            }
            cout << '\n';
        }
    }  
}