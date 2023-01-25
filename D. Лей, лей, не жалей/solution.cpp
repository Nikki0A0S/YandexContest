#include <iostream>
#include <map>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    multimap<pair<int,int>, int> myMap;
  
    for (int i = 0; i < n; i++) 
    {
        int start;
        cin >> start;

        int end;
        cin >> end;

        int price;
        cin >> price;

        myMap.emplace(make_pair(start, end), price);
    }

    int m;
    cin >> m;
  
    for (int j = 0; j < m; j++) 
    {
        int start;
        cin >> start;

        int end;
        cin >> end;

        int type;
        cin >> type;

        int res = 0;
      
        if (type == 1) 
        {
            for (auto &[range, price] : myMap) 
            {
                if ((range.first >= start) && (range.first <= end))
                {
                    res += price;
                }
            }
        } 
        else 
        {
            for (auto &[range, price] : myMap) 
            {
                if ((range.second >= start) && (range.second <= end)) 
                {
                    res += range.second - range.first;
                }
            }
        }
        cout << res << " ";
    }
    return 0;
}
