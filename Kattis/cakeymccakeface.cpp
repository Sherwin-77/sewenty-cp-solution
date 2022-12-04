#include <iostream>
#include <vector>
#include <set>


void fastscan(int &number)
{
    bool negative = false;
    int c;
  
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

int findModus(const std::multiset<int> &arr){
    int current=INT32_MIN, counter=0, best=0, bestCounter=-1;
    for(auto i: arr){
        if(i==current){
            counter++;
            continue;
        }
        if(current > 0 && counter > bestCounter){
            bestCounter = counter;
            best = current;
        }
        current = i;
        counter = 1;
    }
    if(current > 0 && counter > bestCounter){
        bestCounter = counter;
        best = current;
    }
    return best;
}

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Required variable
    int n, m, temp;
    vector <int> entryTimestamp, exitTimestamp;
    multiset <int, less<int>> notDP;

    // Handle input
    fastscan(n);
    fastscan(m);
    for(int i=0; i<n; i++){
        fastscan(temp);
        entryTimestamp.push_back(temp);
    }
    for(int i=0; i<m; i++){
        fastscan(temp);
        exitTimestamp.push_back(temp);
    }

    // Logic here
    for(auto i: exitTimestamp){
        for(auto j: entryTimestamp){
            if(j > i) continue;
            notDP.insert(i-j);
        }
    }
    cout << findModus(notDP) << '\n';
}
