#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        set<char> mySet;

        int k =0;
        
        char ch;
      
        cin.get(ch);
        cin.get(ch);
      
        mySet.insert(ch);
        
        int buf = 0;
      
        char g = char(tolower(ch, locale()));
      
        buf = ((int)g - 96);
        buf *= 256;
      
        int res = buf;
        
        while (k < 3)
        {
            cin.get(ch);
            if (ch == ',')
            {
                k++;
            }
            else
            {
                mySet.insert(ch);
            }
        }
        
        res += mySet.size();
        
        buf = 0;
        
        while (k < 5)
        {
            cin.get(ch);
            if (ch == ',')
            {
                k++;
            }
            else
            {
                buf += (int) ch - 48;
            }
        }
      
        res += buf * 64;
        
        cin.get(ch);
        cin.get(ch);
        cin.get(ch);
        cin.get(ch);
        
        stringstream ss;
        ss << uppercase << hex << res;
      
        string out (ss.str());
        
        cout << out[out.size()-3] << out[out.size()-2] << out[out.size()-1] << endl;
    }
    return 0;
}
