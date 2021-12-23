#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

struct movie_rating {
    int customerId;
    char rating;
    string date;
};
ifstream in[4]; //To read data from four ".txt" files
vector <struct movie_rating> data[20000];// there are only 20000 movie titles


void read()
{
    in[0].open("ratings_data_1.txt");
    in[1].open("ratings_data_2.txt");
    in[2].open("ratings_data_3.txt");
    in[3].open("ratings_data_4.txt");

    int id=0;
    for(int i = 0 ; i < 4 ; i++)
    {
        string buf;
        while(getline(in[i], buf))
        {
            int len = buf.size();
            if(buf[len-1] == ':')
                id++;
            else
            {
                string customerid = buf.substr(0, buf.find(','));
                int pos = buf.find(',');
                char rating = buf[pos+1];
                string date = buf.substr(pos+3);

                movie_rating mr;
                mr.customerId = stoi(customerid);
                mr.rating = rating;
                mr.date = date;
                data[id].push_back(mr);
            }
        }
    }
}

