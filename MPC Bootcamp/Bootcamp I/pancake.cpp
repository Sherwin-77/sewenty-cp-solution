#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void flip(std::vector<int> &arr, int k){
    std::cout << arr.size()-k << ' ';
    int start = 0;
    while(start < k){
        std::swap(arr[start], arr[k]);
        k--;
        start++;
    }
}

int maxIndex(std::vector<int> arr, int k){
    int index = 0;
    for(int i = 0; i < k; i++){
        if(arr[i] >= arr[index]) index = i;
    }
    return index;
}

void pancakeSort(std::vector<int> &arr){
    int n = arr.size();
    while(n > 1){
        int mi = maxIndex(arr, n);
        if(mi != n-1){
            if(mi == 0) flip(arr, n-1);
            else {
                flip(arr, mi);
                flip(arr, n-1);
            }
        }
        n--;
    }
}

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    string input;
    int temp;
    while(getline(cin, input)){
        vector<int> pancake;
        istringstream ss(input);
        while(ss >> temp) pancake.push_back(temp);
        cout << input << '\n';
        pancakeSort(pancake);
        // cout << "\nDEBUG PANCAKE\n";
        // for(int i: pancake){
        //     cout << i << ' ';
        // }
        // cout << "\nEND DEBUG\n";
        cout << "0\n";
    }
}