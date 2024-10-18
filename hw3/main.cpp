#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int valid(string n)
{
    int i = 0;
    long int ans = 0;
    while (i < n.size())
    {
        const string maxValue = "2147483647";
        if(n[0] == 48) { return -1; }
        if (n[i] > 57 || n[i] < 48) { return -1; }
        if (!(n.size() < maxValue.size() || n.size() == maxValue.size() && n <= maxValue))//не смог придумать сам взял у умных дядек
        {
            return -1;
        }
        ans += int(n[i] - 48) * pow(10, n.size() - i - 1);
        i++;
    }
    
    return ans;
}
int main()
{
    string n = "-1";
    int ans = 0;
    while (n != "5312")
    {
        cin >> n;
        if (valid(n) != -1) { ans += valid(n); }
        else
        {
            cout << "invalid sintaxis"<<'\n';
        }
    }
    cout << ans;
}

