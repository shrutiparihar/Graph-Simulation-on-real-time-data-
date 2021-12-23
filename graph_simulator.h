#include <fstream>

using namespace std;

void generate_complete_graph_on_n_vertices(int n)
{
    ofstream out;

    out.open("clique.txt", ios::out);
    //Number of vertices in the graph
    out << n << '\n';

    //Undirected edge in the graph between each u and v
    for(int v = 1 ; v <= n ; v++)
        for(int u = v+1 ; u<= n ; u++)
            out << v << " " << u << '\n';
    out.close();
}


void generate_empty_graph_on_n_vertices(int n)
{
    ofstream out;

    out.open("empty.txt", ios::out);
    //Number of vertices in the graph
    out << n << '\n';

    out.close();
}

void generate_equivalence_mod_k_on_n_vertices(int n, int k)
{
    ofstream out;

    out.open("equivalence.txt", ios::out);
    //Number of vertices in the graph
    out << n << '\n';

    for(int v = 0 ; v <= n ; v++)
        for(int u = v+1 ; u<= n ; u++)
            if( (u - v) % k == 0)
                out << v+1 << " " << u+1 << '\n';

    out.close();
}


void generate_cyclic_graph_on_n_vertices(int n)
{
    ofstream out;

    out.open("cyclic.txt", ios::out);

    out<<n<<"\n";

    for(int v=1 ; v<=n ; v++){
        for(int u = v+1 ; u<=n ; u++){
            if(u-v == 1 || u-v == -1 || u-v == n-1 || u-v == 1-n){
                out << v <<" "<< u << '\n';
            }
        }
    }
    out.close();
}


