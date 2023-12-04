#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

template <typename T>
void debug(T const &value, std::string valueName)
{
    std::cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}

template <typename T>
void debug(T const &value, std::string valueName, int index)
{
    std::cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n, tmp;
    cin >> n;
    set<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.insert(tmp);
    }
    bool hasStart = false;
    int beginCounter = 0;
    int prev = -1;
    for (auto x : arr)
    {
        if (prev + 1 == x)
        {
            prev = x;
            beginCounter++;
            continue;
        }
        if (prev == -1)
        {
            prev = x;
        }
        else
        {
            if (hasStart)
                cout << ',';
            if (beginCounter == 0)
                cout << prev;
            else
            {
                cout << prev - beginCounter << '-' << prev;
            }
            hasStart = true;
        }
        beginCounter = 0;
        prev = x;
    }
    if (hasStart)
        cout << ',';
    if (beginCounter == 0)
        cout << prev;
    else
    {
        cout << prev - beginCounter << '-' << prev;
    }
}