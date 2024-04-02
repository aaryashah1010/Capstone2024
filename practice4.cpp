#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm> // For std::remove_if
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
    vector<string> sleep_times; // Sleep time for each of 7 days
    int fall_asleep_time; // Time taken by the inmate to fall asleep
    string dorm_name; // Name of the dormitory
    vector<int> music_channels; // Music channels assigned (IDs)
    vector<int> music_per_channel; // Music per channel (IDs)
};

void displayInmates(const Inmate& inmate) {
    cout << endl;
    cout << "Inmate Name: " << inmate.name << endl;
    cout << "Earpod ID: " << inmate.ear_id << endl;
    cout << "Sleep Times (for each of 7 days):" << endl;
    for (int day = 0; day < 7; ++day) {
        cout << "Day " << day + 1 << ": " << inmate.sleep_times[day] << endl;
    }
    cout << "Time taken to fall asleep: " << inmate.fall_asleep_time << " minutes" << endl;
    cout << "Dormitory: " << inmate.dorm_name << endl;
    cout << "Music Channels: ";
    for (const auto& channel : inmate.music_channels) {
        cout << channel << " ";
    }
    cout << endl;
    cout << "Music Per Channel: ";
    for (const auto& music : inmate.music_per_channel) {
        cout << music << " ";
    }
    cout << endl;
}

void inputDataFromFile(vector<Inmate>& inmatesList, const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Unable to open file" << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        Inmate inmate;
        stringstream ss(line);

        getline(ss, inmate.name);
        string ear_id_str;
        getline(ss, ear_id_str);
        ear_id_str.erase(remove_if(ear_id_str.begin(), ear_id_str.end(), ::isspace), ear_id_str.end()); // Remove whitespace
        inmate.ear_id = stoi(ear_id_str);

        for (int day = 0; day < 7; ++day) {
            string sleep_time;
            ss >> sleep_time;
            inmate.sleep_times.push_back(sleep_time);
        }

        string fall_asleep_time_str;
        ss >> fall_asleep_time_str;
        inmate.fall_asleep_time = stoi(fall_asleep_time_str);

        inmatesList.push_back(inmate);
    }

    fin.close();
    cout << "Total inmates: " << inmatesList.size() << endl;
}

int main() {
    vector<Inmate> inmatesList;

    inputDataFromFile(inmatesList, "input.txt");

    for (const auto& inmate : inmatesList) {
        displayInmates(inmate);
    }

    return 0;
}
