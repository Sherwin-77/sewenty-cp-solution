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
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) cout << k;
            else cout << '0';
            cout << ' ';
        }
        cout << '\n';
    }

}