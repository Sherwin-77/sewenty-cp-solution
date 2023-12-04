#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>


template <typename T>
void debug(T const &value, std::string valueName){
    std::cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}

template <typename T>
void debug(T const &value, std::string valueName, int index){
    std::cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}


// Naive solution. If anyone have better solution feel free to suggest

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n, tmp;
    cin >> n;
    unordered_set<int> hashmap;
    unordered_map<int, int> idx;
    int mult = -1;
    int shortcut = 0;
    for(int i=0; i < n; i++){
        cin >> tmp;
        bool found = hashmap.find(tmp) != hashmap.end();
        if(!found){ 
            hashmap.insert(tmp);
            idx.emplace(tmp, i);
        }
        else {
            if(mult != -1 && mult != tmp) {
                cout << "TIDAK SESUAI";
                return 0;
            }
            mult = tmp;
        }
    }
    if(hashmap.size()>1){
        if((hashmap.size() == 2 && n > 2) || hashmap.size() > 3) cout << "TIDAK SESUAI";
        else{
            int a, b, c;
            bool isA=false;
            bool isB=false;
            for(auto x: hashmap){
                if(!isA){ 
                    a = x;
                    isA = true;
                }
                else{
                    if(x == mult && hashmap.size() > 2) continue;
                    if(!isB){
                        b = x;
                        isB = true;
                    }
                    else c = x;
                }
            }
            if(hashmap.size() == 2){
                if(a < b) swap(a, b);
                if((a-b)%2 != 0) cout << "TIDAK SESUAI";
                else cout << (a-b)/2 << ' ' << idx[a]+1 << ' ' << idx[b]+1;
                return 0;
            }

            if(mult != -1 && ((a > mult && b > mult) || (mult > a && mult > b))) cout << "TIDAK SESUAI";
            else {
                if(mult == -1){
                    int high = max(a, max(b, c));
                    int low = min(a, min(b, c));
                    int mid = a+b+c - high - low;
                    if(high-mid != mid-low) cout << "TIDAK SESUAI";
                    else cout << high-mid << ' ' << idx[high]+1 << ' ' << idx[low]+1;
                } else {
                    if(a-mult != mult-b) cout << "TIDAK SESUAI";
                    else{
                        if(a < b) swap(a, b);
                        cout << a-mult << ' ' << idx[a]+1 << ' ' << idx[b]+1;
                    }
                }
            }
        }
    } else cout << "SESUAI";
}