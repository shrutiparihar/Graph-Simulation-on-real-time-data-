#include "graph_simulator.h"
#include "graph_operations.h"
#include <fstream>
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{

    //Play around with these parameters to generate cpu and memory usage
    int n = 20, k = 4, source = 5;

    //starting clock----->
    auto earlier = high_resolution_clock::now();

    //generating graph------>
    generate_complete_graph_on_n_vertices(n);
    generate_empty_graph_on_n_vertices(n);
    generate_equivalence_mod_k_on_n_vertices(n, k);
    generate_cyclic_graph_on_n_vertices(n);

    ifstream in1, in2;
    ifstream in3, in4;

    in1.open("clique.txt");
    in2.open("empty.txt");
    in3.open("equivalence.txt");
    in4.open("cyclic.txt");

    int n1, n2, n3, n4, u, v;
    // Input graph from clique.txt

    in1 >> n1;
    Graph g1(n1);
    cout<<"THIS IS A COMPLETE GRAPH ------>";
    while(in1 >> u and in1 >> v)
    {
        g1.add_edge(u, v);
    }
    cout << "\n\n" << "Connected Components\n\n";
    vector < vector <int> > ccs = g1.connected_components();

    for(int cnt = 0 ; cnt < ccs.size() ; cnt++)
        {
            for(int x = 0 ; x < ccs[cnt].size() ; x++)
            {
                cout << ccs[cnt][x] << " ";
            }
            cout << '\n';
        }

    cout << "\n\n" << "Map of shortest Paths\n\n\n";
    map < int, vector <int> > sp = g1.shortest_paths(source);
    for(int s = 1 ; s <= n ; s++)
    {
        if(sp.find(s) != sp.end())
        {
            cout << s << " ";
            for(int x : sp[s])
                cout << x << " ";
            cout << '\n';
        }
    }

    cout << "\n\n" << "Cycle\n\n";
    // store any cycle present in graph 1 in cycle 1.
    vector <int> cycle1 = g1.one_cycle();
    // output the cycle 1 details
    for(int cnt = 0 ; cnt < cycle1.size() ; cnt++)
        {
            cout << cycle1[cnt] << " ";
        }

    //NEW GRAPH ------>
    cout << "\n\n Graph Change \n \n";

    //Input graph from empty.txt
    in2 >> n2;
    Graph g2(n2);
    cout<<"THIS IS AN EMPTY GRAPH ------>";
    while(in2 >> u and in2 >> v)
    {
        g2.add_edge(u, v);
    }
    cout << "\n\n" << "Connected Components\n\n";
    vector < vector <int> > ccs2 = g2.connected_components();
    for(int cnt = 0 ; cnt < ccs2.size() ; cnt++)
        {
            for(int x = 0 ; x < ccs2[cnt].size() ; x++)
                cout << ccs2[cnt][x] << " ";
            cout << '\n';
        }
    cout << "\n\n" << "Map of shortest Paths\n\n";
    map < int, vector <int> > sp2 = g2.shortest_paths(source);
    for(int s = 1 ; s <= n ; s++)
    {
        if(sp2.find(s) != sp2.end())
        {
            cout << s << " ";
            for(int x : sp2[s])
                cout << x << " ";
            cout << '\n';
        }
    }
    cout << "\n\n" << "Cycle\n\n";
    vector <int> cycle2 = g2.one_cycle();

    for(int cnt = 0 ; cnt < cycle2.size() ; cnt++)
        {
            cout << cycle2[cnt] << " ";
        }

    cout << "\n\n Graph Change \n \n";

    //Input graph from equivalence.txt
    in3 >> n3;
    Graph g3(n3);
    cout<<"THIS IS A EQUIVALENCE MOD K GRAPH ------>";
    while(in3 >> u and in3 >> v)
    {
        g3.add_edge(u, v);
    }
    cout << "\n\n" << "Connected Components\n\n";
    vector < vector <int> > ccs3 = g3.connected_components();
    for(int cnt = 0 ; cnt < ccs3.size() ; cnt++)
        {
            for(int x = 0 ; x < ccs3[cnt].size() ; x++)
                cout << ccs3[cnt][x] << " ";
            cout << '\n';
        }
    cout << "\n\n" << "Map of shortest Paths\n\n";
    map < int, vector <int> > sp3 = g3.shortest_paths(source);
    for(int s = 1 ; s <= n ; s++)
    {
        if(sp3.find(s) != sp3.end())
        {
            cout << s << " ";
            for(int x : sp3[s])
                cout << x << " ";
            cout << '\n';
        }
    }
    cout << "\n\n" << "Cycle\n\n";
    vector <int> cycle3 = g3.one_cycle();

    for(int cnt = 0 ; cnt < cycle3.size() ; cnt++)
        {
            cout << cycle3[cnt] << " ";
        }
    cout << '\n';


    cout << "\n\n Graph Change \n \n";

    //Input graph from equivalence.txt
    in4 >> n4;
    Graph g4(n4);
    cout<<"THIS IS A CYCLIC GRAPH ------>";
    while(in4 >> u and in4 >> v)
    {
        g4.add_edge(u, v);
    }
    cout << "\n\n" << "Connected Components\n\n";
    vector < vector <int> > ccs4 = g4.connected_components();
    for(int cnt = 0 ; cnt < ccs4.size() ; cnt++)
        {
            for(int x = 0 ; x < ccs4[cnt].size() ; x++)
                cout << ccs4[cnt][x] << " ";
            cout << '\n';
        }
    cout << "\n\n" << "Map of shortest Paths\n\n";
    map < int, vector <int> > sp4 = g4.shortest_paths(source);
    for(int s = 1 ; s <= n ; s++)
    {
        if(sp4.find(s) != sp4.end())
        {
            cout << s << " ";
            for(int x : sp4[s])
                cout << x << " ";
            cout << '\n';
        }
    }
    cout << "\n\n" << "Cycle\n\n";
    vector <int> cycle4 = g4.one_cycle();

    for(int cnt = 0 ; cnt < cycle4.size() ; cnt++)
        {
            cout << cycle4[cnt] << " ";
        }
    cout << '\n';

    in1.close();
    in2.close();
    in3.close();
    in4.close();

    auto later = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(later - earlier);
    cout << "Time taken for "<< n <<" nodes and k = "<<k<<" is : "<< duration.count() << " microseconds" << endl;

    char ch ;
    cin>>ch;
    return 0;

}
