#include <iostream>
#include <set>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, temp;
    // multiset less<int> starts from smallest value 
    multiset <int, less<int>> arr;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        arr.insert(temp);
    }
    int current=INT32_MIN, counter=0, best=INT32_MIN, best_counter=0;
    for(auto i:arr){
        // TODO: Fix logic?
        if(i==current){
            counter++;
            continue;
        }
        // This prioritize larger value
        // To prioritize smaller value just remove '='
        if(counter>=best_counter){
            best_counter = counter;
            best = current;
        }
        current = i;
        counter = 1;
    }
    if(counter>=best_counter){
        best = current;
        best_counter = counter;
    }
    cout << best << '\n';

}
