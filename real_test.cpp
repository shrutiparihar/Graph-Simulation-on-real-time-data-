#include "graph_operations.h"
#include "graph_make.h"
#include <set>
#include <map>

using namespace std;

int main()
{
    read();
    //it should be 17000 but crashing for such a big value
    int countMovies = 10;

    set<int> S;
    for(int m = 1 ; m <= countMovies ; m++)
    {
        for(auto it : data[m])
        {
            S.insert(it.customerId);
        }
    }
    map<int,int> mp;
    int countCustomers = S.size();

    // Compress customer ids so that they start from 1
    int compress = 1;
    for(auto it : S)
    {
        mp[compress++] = it;
    }

    Graph g1(countMovies);

    for(int i = 1 ; i <= countCustomers ; i++)
    {
        for(int j = i+1 ; j <= countCustomers ; j++)
        {
            bool I = false, J = false;
            for(int m = 1 ; m <= countMovies ; m++)
            {
                for(auto it : data[m])
                {
                    if(mp[i]==it.customerId)
                        I = true;
                    if(mp[j]==it.customerId)
                        J = true;
                    if(I and J)
                        break;
                }
                if(I and J)
                    break;
            }
            g1.add_edge(i, j);
        }
    }

    vector < vector <int> > ccs = g1.connected_components();

    cout << "There are" << ccs.size() << '\n' << "number of components";
    for(int i  = 0 ; i < ccs.size() ; i++)
        cout << "Size of each component is : " << ccs[i].size() << '\n';

    char ch;
    cin>>ch;

    return 0;
}
