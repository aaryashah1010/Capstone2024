#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
<<<<<<< HEAD
#include <unordered_map>
=======
#include <iomanip>
>>>>>>> 1e4ed3848a8483c5b8dde74292211d444b667b6f
using namespace std;

class DailySleep {
public:
    int day;
    string sleep_time;
};

class Inmate {
public:
    string name;
<<<<<<< HEAD
    int earpod_id;
    vector<string> sleep_times;
    int time_to_fall_asleep;
=======
    int ear_id;
    int minutes;
    vector<DailySleep> daily_sleep; // Vector to hold daily sleep time
    int members;
>>>>>>> 1e4ed3848a8483c5b8dde74292211d444b667b6f
};

class Dorm {
public:
    string dorm_name;
<<<<<<< HEAD
    int num_channels;
    vector<int> music_channels;
    vector<int> music_per_channel;
};

void readData(vector<Inmate>& inmatesList, unordered_map<string, Dorm>& dormMap) {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "Unable to open file!" << endl;
=======
    int channels_id;
    string music_id;    
};

void displayInmates(const Inmate& inmate) {
    cout << endl;
    cout << "Name: " << inmate.name << endl;
    cout << "Ear ID: " << inmate.ear_id << endl;
    cout << "Minutes: " << inmate.minutes << endl;
    cout << "Daily Sleep Time:" << endl;
    for (const auto& daily : inmate.daily_sleep) {
        cout << "Day " << daily.day << ": " << daily.sleep_time << endl;
    }
}

void insertdata(vector<Inmate>& inmatesList) {
    ifstream fin("cap1.txt");
    if (!fin.is_open()) {
        cout << "Unable to open file" << endl;
>>>>>>> 1e4ed3848a8483c5b8dde74292211d444b667b6f
        return;
    }

    string line;
<<<<<<< HEAD
    string recordType;

    while (getline(file, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        iss >> recordType;

        if (recordType == "Inmate") {
            Inmate inmate;
            getline(file, inmate.name);
            file >> inmate.earpod_id;
            string sleepTime;
            for (int i = 0; i < 7; ++i) {
                file >> sleepTime;
                inmate.sleep_times.push_back(sleepTime);
            }
            file >> inmate.time_to_fall_asleep;
            inmatesList.push_back(inmate);
        } else if (recordType == "Dorm") {
            Dorm dorm;
            getline(file, dorm.dorm_name);
            file >> dorm.num_channels;
            for (int i = 0; i < dorm.num_channels; ++i) {
                int channel;
                file >> channel;
                dorm.music_channels.push_back(channel);
            }
            for (int i = 0; i < dorm.num_channels; ++i) {
                int music;
                file >> music;
                dorm.music_per_channel.push_back(music);
            }
            dormMap[dorm.dorm_name] = dorm;
        }
    }

    file.close();
}

void displayData(const vector<Inmate>& inmatesList, const unordered_map<string, Dorm>& dormMap) {
    cout << "Inmates:" << endl;
    for (const auto& inmate : inmatesList) {
        cout << "Name: " << inmate.name << endl;
        cout << "Earpod ID: " << inmate.earpod_id << endl;
        cout << "Sleep Times:";
        for (const auto& time : inmate.sleep_times) {
            cout << " " << time;
        }
        cout << endl;
        cout << "Time to Fall Asleep: " << inmate.time_to_fall_asleep << " minutes" << endl;
        cout << endl;
    }

    cout << "Dorms:" << endl;
    for (const auto& dorm : dormMap) {
        cout << "Dorm Name: " << dorm.first << endl;
        cout << "Number of Music Channels: " << dorm.second.num_channels << endl;
        cout << "Music Channels:";
        for (const auto& channel : dorm.second.music_channels) {
            cout << " " << channel;
        }
        cout << endl;
        cout << "Music Per Channel:";
        for (const auto& music : dorm.second.music_per_channel) {
            cout << " " << music;
        }
        cout << endl;
        cout << endl;
=======

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

            i1.daily_sleep.push_back(daily);
        }
        inmatesList.push_back(i1);
    }

    fin.close();
    cout << "Total inmates: " << inmatesList.size() << endl;
}

void assigndorm(vector<Inmate>& inmatesList, vector<Dorm>& dormlist) {
    cout << endl;
    for (int i = 0; i < inmatesList.size(); i = i + 2) {
        if (i + 1 < inmatesList.size()) {
            Dorm d;
            d.dorm_name = "Dorm" + to_string(i / 2 + 1);
            dormlist.push_back(d);
            inmatesList[i].members = 2;
            inmatesList[i + 1].members = 2;
            cout << "Assigned inmates " << inmatesList[i].name << " and " << inmatesList[i + 1].name << " to " << d.dorm_name<<endl;
        } else {
            Dorm d;
            d.dorm_name = "Single dorm " + to_string(i / 2 + 1);
            dormlist.push_back(d);
            inmatesList[i].members = 1;
            cout << "Assigned inmate " << inmatesList[i].name << " to " << d.dorm_name<<endl;
        }
>>>>>>> 1e4ed3848a8483c5b8dde74292211d444b667b6f
    }
}

int main() {
    vector<Inmate> inmatesList;
<<<<<<< HEAD
    unordered_map<string, Dorm> dormMap;

    readData(inmatesList, dormMap);
    displayData(inmatesList, dormMap);
=======
    vector<Dorm> dormlist;

    insertdata(inmatesList);
   

    for (int i = 0; i < inmatesList.size(); ++i) {
        displayInmates(inmatesList[i]);
    }
     assigndorm(inmatesList, dormlist);
>>>>>>> 1e4ed3848a8483c5b8dde74292211d444b667b6f

    return 0;
}
