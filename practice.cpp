#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector <int>v(5);
    for(int i=0;i<5;i++)
    {
        cin>>v[i];
    }
    ofstream fout;
    fout.open("zoom.txt");
    for(int i=0;i<5;i++)
    {
        fout<<v[i];
    }
    fout.close();
    return 0;

}