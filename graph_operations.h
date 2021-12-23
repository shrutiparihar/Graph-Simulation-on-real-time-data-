#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <iostream>
using namespace std;
#define maxNodes 10005

class  Graph
{
private:
    
    //Nodes are indexed from 1 to countNodes
    int countNodes;                  
    vector <int> adjacencyList[maxNodes];
    bool isNodeVisited[maxNodes];
    vector <int> cc;
    int parent[maxNodes];
    int end1;
    int end2;
public:
    Graph(int countVertices);
    void add_edge(int u, int v);
    void dfs(int source);
    void isCyclic(int s, int root);
    vector < vector<int> > connected_components();
    vector <int> one_cycle();
    map<int, vector<int> > shortest_paths(int s);
    
};

Graph::Graph(int countVertices)
{
    countNodes  = countVertices;
    for(int node = 1 ; node <= countNodes ; node++)
        adjacencyList[node].clear();
    memset(isNodeVisited, false, sizeof(isNodeVisited));
    memset(parent, 0, sizeof(parent));
    end1 = -1;
    end2 = -1;
}
void Graph::add_edge(int u, int v)
{
    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u);
}

void Graph::dfs(int source)
{
    if(isNodeVisited[source])
        return;
    isNodeVisited[source] = true;
    cc.push_back(source);
    for(int vertex : adjacencyList[source])
    {
        if(isNodeVisited[vertex] == false)
        {
            dfs(vertex);
        }
    }   
}
void Graph::isCyclic(int s, int root)
{
    
    if(end1 != -1 and end2 != -1)
        return;
    isNodeVisited[s] = true;
    for(int vertex : adjacencyList[s])
    {
        if(isNodeVisited[vertex] == false)
        {
            parent[vertex] = s;
            isCyclic(vertex, root);
        }
        else
        {
            if(parent[s] != vertex and s != root)
            {
                end1 = s;
                end2 = vertex;
                return;
            }
        }
    } 
}
vector <vector<int> > Graph::connected_components()
{
    memset(isNodeVisited, false, sizeof(isNodeVisited));
    vector < vector <int> > ccs;
    for(int node = 1 ; node <= countNodes ; node++)
    {
        if(isNodeVisited[node] == false)
        {
            cc.clear();
            dfs(node);
            ccs.push_back(cc);
            
        }
    }
    
    return ccs;
}
vector <int> Graph::one_cycle()
{
    memset(parent, -1, sizeof(parent));
    memset(isNodeVisited, false, sizeof(isNodeVisited));
    bool flag = false;
    
    for(int node = 1 ; node <= countNodes ; node++)
    {
        if(isNodeVisited[node] == false)
        {
            isCyclic(node, node);
            if(end1 != -1 and end2 != -1)
            {
                flag = true;
                break;
            }
        }
    }
    vector <int> cycle;
    if(flag == false)
        return cycle;
    else
    {
        
        int cur = end1;
        while(cur != end2)
        {
            cycle.push_back(cur);
            cur = parent[cur];
        }
        cycle.push_back(end2);
        return cycle;
    }
}
map< int, vector<int> > Graph::shortest_paths(int s)
{
    memset(isNodeVisited, false, sizeof(isNodeVisited));
    int dist[countNodes+1];
    int prev[countNodes+1];
    for(int i = 1 ; i <= countNodes ; i++)
        {
            dist[i] = 1e9;  //assuming 1e9 to be infinity
            prev[i] = -1;
        }
    dist[s] = 0;

    typedef pair <int, int> pii;
    priority_queue <pii, vector <pii>, greater<pii> > Q;

    Q.push(make_pair(0,s));
    while(!Q.empty())
    {
        pii data = Q.top();
        Q.pop();
        int u = data.second;
        if(isNodeVisited[u]) continue;
        isNodeVisited[u] =  true;
        for(int v : adjacencyList[u])
        {
            int alt = dist[u] + 1;
            if(alt < dist[v])
            {
                dist[v] = alt;
                prev[v] = u;
                Q.push(make_pair(dist[v], v));
            }
        }

    }
    map <int, vector <int> > mp;
    for(int x = 1 ; x <= countNodes ; x++)
    {
        if(dist[x] != 1e9)
        {       
            int cur = x;     
            while(cur != s)
            {
                mp[x].push_back(cur);
                cur = prev[cur];
            }
            mp[x].push_back(s);
        }
    }

    return mp;
} 