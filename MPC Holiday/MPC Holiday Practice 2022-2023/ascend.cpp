#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>


template <typename T>
void debug(T const &value, std::string valueName){
    std::cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}

template <typename T>
void debug(T const &value, std::string valueName, int index){
    std::cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}


int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int t, n;
    int tmp; 
    cin >> t;
    unordered_set<int> hashmap;
    for(int x = 0; x < t; x++){
        hashmap = unordered_set<int>();
        cin >> n;
        bool early = false;
        for(int i = 0; i < n; i++){
            cin >> tmp;
            if(early) continue;
            if(hashmap.find(tmp) == hashmap.end()) hashmap.insert(tmp);
            else {
                early = true;
            }
        }
        cout << (early ? "NO\n" : "YES\n");
    }

}