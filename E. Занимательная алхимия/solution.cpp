#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    map<int, pair<pair<int,int>,vector<int>>> myMap;
  
    for (int i = 0; i < n-2; i++)
    {
        int k;
        cin >> k;
        
        int a = 0;
        int b = 0;
        vector<int> buf;
        
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
          
            if (x == 1)
            {
                a++;
            }
            else if (x == 2)
            {
                b++;
            }
            else
            {
                buf.push_back(x);
            }
        }
      
        myMap.insert({i+3,{{a,b},buf}});
    }

    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        
        int b;
        cin >> b;
        
        int c;
        cin >> c;
        
        map<int, pair<pair<int,int>,vector<int>>>::iterator it = myMap.find(c);
      
        if (it == myMap.end())
        {
            cout << 0;
            continue;
        }
        
        bool fl = false;
      
        while (!fl)
        {
            bool flG = false;
            int l = 0;
          
            for (int p = l; p < (it->second).second.size(); p++)
            {
                map<int, pair<pair<int,int>,vector<int>>>::iterator itG = myMap.find((it->second).second[p]);
                
                if(itG == myMap.end())
                {
                    flG = true;
                    break;
                }
                
                ((it->second).first).first += ((itG->second).first).first;
                ((it->second).first).second += ((itG->second).first).second;
              
                for (auto &vectVect:(itG->second).second)
                {
                    if (vectVect == it->first)
                    {
                        flG = true;
                        break;
                    }
                    (it->second).second.push_back(vectVect);
                }
                l++;
            }
            if (flG)
            {
                break;
            }
            if ((it->second).second.size() == l)
            {
                fl = true;
                vector<int>().swap((it->second).second);
            }
        }
        if ((!fl) || (((it->second).first).first > a) || (((it->second).first).second > b))
        {
            fl = false;
        }
        cout << fl;
    }
    return 0;
}
