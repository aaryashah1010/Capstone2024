#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class inmates {
public:
    string name;
    int ear_id;
    vector<int> sleep_time;
    int minutes;
    int members;
};

class dorm {
public:
    string dorm_name;
    int channels_id;
    int music_id;
};

void displayInmates(const inmates& inmate) {
    cout << endl;
    cout << "Name: " << inmate.name <<endl;
    cout << "Ear ID: " << inmate.ear_id <<endl;
    cout << "Minutes: " << inmate.minutes <<endl;
    cout << "Sleep Time: ";
    for(int i = 0; i < inmate.sleep_time.size(); i++) {
        cout << inmate.sleep_time[i];
        if(i < inmate.sleep_time.size() - 1)
            cout << ", ";
    }
    cout << endl;
}

void insertdata(vector<inmates> &inmatesList) {
    ifstream fin("cap.txt");
    if (!fin.is_open()) {
        cout << "Unable to open file" << endl;
        return;
    }

    string line;

    while (getline(fin, line)) {
        inmates i1;
        stringstream ss(line);
        
        getline(ss, i1.name, ',');
        ss >> i1.ear_id;
        ss.ignore();
        ss >> i1.minutes;
        ss.ignore();
        
      
        if (!ss.eof()) {
            int sleepHour;
            while (ss >> sleepHour) {
                i1.sleep_time.push_back(sleepHour);
                if (ss.peek() == ',')
                    ss.ignore(); 
            }
        }
        
        inmatesList.push_back(i1);
    }

    fin.close();
    cout << "Total inmates: " << inmatesList.size() << endl;
}
void assigndorm(vector<inmates>&inmatesList,vector<dorm>&dormlist)
{
    cout<<endl;
     for(int i=0;i<inmatesList.size();i=i+2)
     {
        if(i+1<inmatesList.size())
        {
            dorm d;
            d.dorm_name="Dorm"+to_string(i/2+1);
            dormlist.push_back(d);
            inmatesList[i].members=2;
            inmatesList[i+1].members=2;
            cout << "Assigned inmates " << inmatesList[i].name << " and " << inmatesList[i + 1].name << " to " << d.dorm_name << endl;
        }
        else{
            dorm d;
            d.dorm_name="Single dorm "+to_string(i/2+1);
            dormlist.push_back(d);
            inmatesList[i].members=1;
            cout << "Assigned inmate " << inmatesList[i].name << " to " << d.dorm_name << endl;
        }
     }
}


int main() {
    vector<inmates> inmatesList; 
    vector<dorm>dormlist;  
    insertdata(inmatesList);
    for (int i = 0; i < inmatesList.size(); ++i) {
        displayInmates(inmatesList[i]);
    }                 
    
    assigndorm(inmatesList,dormlist);
    return 0;
}
