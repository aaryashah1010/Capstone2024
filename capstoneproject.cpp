#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

class DailySleep {
public:
    int day;
    string sleep_time;
};

class Inmate {
public:
    string name;
    int earpod_id;
    vector<string> sleep_times;
    int time_to_fall_asleep;
};

class Dorm {
public:
    string dorm_name;
    int num_channels;
    vector<int> music_channels;
    vector<int> music_per_channel;
};

void readData(vector<Inmate>& inmatesList, unordered_map<string, Dorm>& dormMap) {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "Unable to open file!" << endl;
        return;
    }

    string line;
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
    }
}

int main() {
    vector<Inmate> inmatesList;
    unordered_map<string, Dorm> dormMap;

    readData(inmatesList, dormMap);
    displayData(inmatesList, dormMap);

    return 0;
}
