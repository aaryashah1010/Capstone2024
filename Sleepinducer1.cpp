#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class inmates {
public:
    string name;
    int ear_id;
    vector<int> sleep_time;
    int minutes;

    // Constructor to initialize name, ear_id, minutes, and sleep_time vector
    inmates(string name, int ear_id, int minutes, const vector<int>& sleep_time) : name(name), ear_id(ear_id), minutes(minutes), sleep_time(sleep_time) {
    }
};

class dorm {
public:
    string dorm_name;
    int channels_id;
    int music_id;
};

// Function to display inmate's data
void displayInmates(const inmates& inmate) {
    cout << "Name: " << inmate.name << endl;
    cout << "Ear ID: " << inmate.ear_id << endl;
    cout << "Minutes: " << inmate.minutes << endl;
    cout << "Sleep Time: ";
    for(int i = 0; i < 7; i++) {
        cout << inmate.sleep_time[i] << " ";
    }
    cout << endl;
}

int main() {
    
    vector<int> sleep_time = {8, 7, 8, 9, 7, 6, 8};
    
    inmates i1("Aarya", 202301036, 10, sleep_time); 
    displayInmates(i1);

    return 0;
}
