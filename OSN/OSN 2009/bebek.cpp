#include <iostream>
#include <vector>

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
    int n, m, x;
    vector<int> bebekAjg; // bebek ajg yes
    fastscan(n);  // n is number of bebek
    fastscan(m);  // m is target number to say
    fastscan(x);  // x is round of game
    int left = n, selector = 0;
    /*
    So we put list of bebek in set
    when m reached, coresponding i-th bebek will quit and repeat until x
    bebekAjg is 0 based index
    */
      for (int i=1; i<=n; i++)
   {
       bebekAjg.push_back(i);
   }
   while(x-- && bebekAjg.size()>1){
       selector = (selector+m-1) % bebekAjg.size();
       bebekAjg.erase(bebekAjg.begin()+selector);
   }
   for (auto i = bebekAjg.begin(); i != bebekAjg.end(); i++){
       cout << *i << '\n';
   }
   
   

}
