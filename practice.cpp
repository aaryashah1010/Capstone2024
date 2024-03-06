#include <iostream>
#include <fstream>
#include <vector>
#include "libxl.h"
using namespace std;

void FetchData(){
    Book* book = xlCreatebook();
    if (book->load("data.xlsx")){
        Sheet* sheet = book->getSheet(0);
        Cell* cell = sheet->getCell(1,1);
        double value = cell->getDoubleValue();
        cout<<value<<endl;
        book->release();
    }
    else{
        cout<<"File Not Exist"<<endl;
    }
}
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
    FetchData();
    return 0;

}