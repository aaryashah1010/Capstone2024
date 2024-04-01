#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

class DailySleep {
public:
    int day;
    string sleep_time;
};

class Inmate {
public:
    string name;
    int ear_id;
    int minutes;
    vector<vector<DailySleep>> daily_sleep; // Vector to hold daily sleep time
    int members;
};

class Dorm {
public:
    string dorm_name;
    int channels_id;
    string music_id;    
};

void displayInmates(const Inmate& inmate) {
    cout << endl;
    cout << "Name: " << inmate.name << endl;
    cout << "Ear ID: " << inmate.ear_id << endl;
    cout << "Minutes: " << inmate.minutes << endl;
    cout << "Daily Sleep Time:" << endl;
    for (const auto& day : inmate.daily_sleep) {
        for (const auto& sleep : day) {
            cout << "Day " << sleep.day << ": " << sleep.sleep_time << endl;
        }
    }
}

void insertdata(vector<Inmate>& inmatesList) {
    ifstream fin("cap1.txt");
    if (!fin.is_open()) {
        cout << "Unable to open file" << endl;
        return;
    }

    string line;

    while (getline(fin, line)) {
        if (line.empty()) continue; // Skip empty lines
        Inmate i1;
        stringstream ss(line);

        ss >> i1.name >> i1.ear_id >> i1.minutes;

        int day = 1;
        while (!ss.eof()) {
            DailySleep daily;
            daily.day = day++;

            string sleepTime;
            ss >> sleepTime;
            daily.sleep_time = sleepTime;

            i1.daily_sleep.push_back({daily});
        }
        inmatesList.push_back(i1);
    }

    fin.close();
    cout << "Total inmates: " << inmatesList.size() << endl;
}

int main() {
    vector<Inmate> inmatesList;
    vector<Dorm> dormlist;

    insertdata(inmatesList);

    for (int i = 0; i < inmatesList.size(); ++i) {
        displayInmates(inmatesList[i]);
    }

    return 0;
}
