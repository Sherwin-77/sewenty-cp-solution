#include <iostream>
#include <algorithm>
#include <set>

void fastscan(int &number)
{
    bool negative = false;
    register int c;
  
    number = 0;

    c = getchar();
    if (c=='-')
    {
        negative = true;
  
        c = getchar();
    }
  
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
  
    if (negative)
        number *= -1;
}

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, placeholder;
    // multiset less<int> starts from smallest value 
    multiset <int, less<int>> arr;
    fastscan(n);
    for(int i=0; i<n; i++){
        fastscan(placeholder);
        arr.insert(placeholder);
    }
    int current=INT32_MIN, counter=0, best=INT32_MIN, best_counter=0;
    for(auto i:arr){
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
