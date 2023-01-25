#include <iostream>
#include <vector>
#include <string>
 
using namespace std;

int main() 
{
    string j;
	cin >> j;

	string s;
    cin >> s;
 
    int res = 0;

    for (auto &ch : s) 
    {
    	res += j.find(ch) != string::npos;
    }
 
    cout << res;
 
    return 0;
}
