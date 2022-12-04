#include <iostream>
#include <queue>

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
    queue<int> q;
    int a;
    fastscan(a);
    q.push(a);
    int val=0, temp;
    while(!q.empty()){
        int selector = q.front();;
        q.pop();
        temp = (selector/2) + (selector/3) + (selector/4);
        if(temp > selector){
            q.push(selector/2);
            q.push(selector/3);
            q.push(selector/4);
            continue;
        }
        val += selector;
    }
    cout << val << '\n';

}
