#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


typedef std::pair <int, int> item;

bool compare (const item &a, const item &b)
{
    return a.second > b.second;
}

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
    int n, p, q;
    fastscan(n);
    fastscan(p);
    fastscan(q);
    set <int, greater<int>> ally;
    vector<item> ourMoney;
    vector<int> cost;
    int placeholder;
    long long value;
    for(int i=0; i<n; i++){
        fastscan(placeholder);
        cost.push_back(placeholder);
    }
    for(int i=0; i<p; i++){
        fastscan(placeholder);
        ally.insert(placeholder);
        value += cost[placeholder-1];
    }
    for(int i=0; i<q; i++){
        fastscan(placeholder);
        if(ally.find(placeholder) != ally.end()){
            ally.erase(placeholder);
            ourMoney.emplace_back(placeholder, cost[placeholder-1]);
            value -= cost[placeholder-1];
        }
    }
    sort(ourMoney.begin(), ourMoney.end(), compare);
    bool attack=true;
    for(const item &c: ourMoney){
        if(attack){
            value += c.second;
        }
        attack = !attack;
    }
    cout << value << '\n';




}
