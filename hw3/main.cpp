#include <iostream>
#include <string>
#include <cmath>
using std::string;
using std::cin;
using std::cout;
using std::endl;
uint32_t valid(string string_num)
{
    uint32_t i = 0;
    uint32_t ans = 0;
    const string maxValue = std::to_string(std::numeric_limits<uint32_t>.max());
    if (n[0] == '0') { return -1; }
    if (!((string_num.size() < maxValue.size()) || ((string_num.size() == maxValue.size()) && (string_num <= maxValue))))
    {
        return -1;
    }
    while (i < string_num.size())
    {
        if (string_num[i] > '9' || string_num[i] < '0') { return -1; }
        ans += int(string_num[i] - '0') * pow(10, string_num.size() - i - 1);
        i++;
    }
    return ans;
}
int main()
{
    string string_num = "-1";
    uint32_t ans = 0;
    while (string_num != "5312")
    {
        cin >> string_num;
        uint32_t valid_string_num = valid(string_num);
        if (valid_string_num != -1) { ans += valid_string_num; }
        else
        {
            cout << "invalid syntax"<<'\n';
        }
    }
    cout << ans << endl;
}

