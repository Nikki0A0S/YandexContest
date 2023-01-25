#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    multimap<pair<int,int>, char> myMap;
  
    for (int i = 0; i < n; i++)
    {
        int date;
        cin >> date;
        
        int hour;
        cin >> hour;
        
        int minute;
        cin >> minute;
        
        int id;
        cin >> id;
        
        char status;
        cin >> status;
        
        date *= 60*24;
        date += hour*60 + minute;
      
        if (status != 'B')
        {
            myMap.insert({{id, date}, status});
        }
    }
    
    map<int,int> res;
  
    int curId = -1;
  
    for (multimap<pair<int,int>, char>::reverse_iterator rit = myMap.rbegin(); rit != myMap.rend(); ++ rit)
    {
        if ((rit->first).first != curId)
        {
            curId = (rit->first).first;
            res[curId] = 0;
        }
        
        if ((rit->second == 'S') || (rit->second == 'C'))
        {
            res[curId] += (rit->first).second;
        } 
        else if (rit->second == 'A')
        {
            res[curId] -= (rit->first).second;
        }
    }
    
    for(map<int,int>::iterator it = res.begin(); it != res.end(); ++it)
    {
        cout << it->second << " ";
    }
    return 0;
}
