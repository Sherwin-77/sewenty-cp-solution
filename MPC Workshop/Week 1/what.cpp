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


int what(int n){
    int counter = 1;
    while (n != 1){
        if(n % 2 == 1) n = 3 * n + 1;
        else n /= 2;
        counter++;
    }
    return counter;
}

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int a, b;
    while(cin >> a >> b){
        int best = 0;
        cout << a << ' ' << b << ' ';
        if(a > b) swap(a, b);
        for(int i = a; i <= b; i++){
            best = max(best, what(i));
        }
        cout << best << '\n';
    }
}