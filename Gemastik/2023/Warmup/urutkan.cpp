#include <iostream>
#include <vector>
#include <algorithm>


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
    string a, b;
    int n;
    cin >> n;
    cin >> a >> b;
    bool swapped = false;
    int res = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > b[i]){
            if(!swapped){
                swapped = true;
                res++;
            }
        }
        if(a[i] < b[i]) swapped = false;
    }
    cout << res;
}