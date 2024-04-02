#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
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
    vector<string> sleep_times; // Sleep times for each of 7 days
    int p_minutes; // Time taken by the inmate to fall asleep
    string dorm_name; // Dormitory assigned to the inmate
};

class Dorm {
public:
    string dorm_name;
    vector<int> channels; // Set of music channels assigned
    vector<int> music_ids; // Set of music per channel IDs
};

void displayInmate(const Inmate& inmate) {
    cout << "Inmate Name: " << inmate.name << endl;
    cout << "Earpod ID: " << inmate.ear_id << endl;
    cout << "Sleep Times:" << endl;
    for (size_t i = 0; i < inmate.sleep_times.size(); ++i) {
        cout << "Day " << i + 1 << ": " << inmate.sleep_times[i] << endl;
    }
    cout << "Time taken to fall asleep: " << inmate.p_minutes << " minutes" << endl;
    cout << "Assigned Dormitory: " << inmate.dorm_name << endl;
    cout << endl;
}

void displayDormitory(const Dorm& dorm) {
    cout << "Dormitory Name: " << dorm.dorm_name << endl;
    cout << "Channels:";
    for (int channel : dorm.channels) {
        cout << " " << channel;
    }
    cout << endl;
    cout << "Music IDs:";
    for (int music_id : dorm.music_ids) {
        cout << " " << music_id;
    }
    cout << endl << endl;
}

void parseInmateRecord(ifstream& fin, vector<Inmate>& inmatesList) {
    string line;
    Inmate inmate;
    while (getline(fin, line)) {
        if (line == "Dorm record") break;
        if (line.empty()) continue;
        if (line == "Inmate record") {
            getline(fin, inmate.name);
            fin >> inmate.ear_id;
            for (int i = 0; i < 7; ++i) {
                string sleep_time;
                fin >> sleep_time;
                inmate.sleep_times.push_back(sleep_time);
            }
            fin >> inmate.p_minutes;
            inmatesList.push_back(inmate);
        }
    }
}

void parseDormRecord(ifstream& fin, unordered_map<string, Dorm>& dormMap) {
    string line;
    Dorm dorm;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        if (line == "Dorm record") {
            getline(fin, dorm.dorm_name);
            int num_channels;
            fin >> num_channels;
            for (int i = 0; i < num_channels; ++i) {
                int channel_id;
                fin >> channel_id;
                dorm.channels.push_back(channel_id);
            }
            int num_music_ids;
            fin >> num_music_ids;
            for (int i = 0; i < num_music_ids; ++i) {
                int music_id;
                fin >> music_id;
                dorm.music_ids.push_back(music_id);
            }
            dormMap[dorm.dorm_name] = dorm;
        }
    }
}

int main() {
    vector<Inmate> inmatesList;
    unordered_map<string, Dorm> dormMap;

    ifstream fin("cap1.txt");
    if (!fin.is_open()) {
        cout << "Unable to open file" << endl;
        return 1;
    }

    while (!fin.eof()) {
        parseInmateRecord(fin, inmatesList);
        parseDormRecord(fin, dormMap);
    }

    fin.close();

    cout << "Inmate Details:" << endl;
    for (const auto& inmate : inmatesList) {
        displayInmate(inmate);
    }

    cout << "Dormitory Details:" << endl;
    for (const auto& entry : dormMap) {
        displayDormitory(entry.second);
    }

    return 0;
}
