#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
<<<<<<< HEAD
#include <unordered_map>
=======
>>>>>>> 1e4ed3848a8483c5b8dde74292211d444b667b6f
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
    vector<DailySleep> daily_sleep; // Vector to hold daily sleep time
    int members;
};

class Dorm {
public:
    string dorm_name;
    int channels_id;
<<<<<<< HEAD
    string music_id;
    vector<int> channels; // Vector to hold channel IDs
=======
    string music_id;    
>>>>>>> 1e4ed3848a8483c5b8dde74292211d444b667b6f
};

void displayInmates(const Inmate& inmate) {
    cout << endl;
    cout << "Name: " << inmate.name << endl;
    cout << "Ear ID: " << inmate.ear_id << endl;
    cout << "Minutes: " << inmate.minutes << endl;
    cout << "Daily Sleep Time:" << endl;
<<<<<<< HEAD
    for (const auto& daily : inmate.daily_sleep) {
        cout << "Day " << daily.day << ": " << daily.sleep_time << endl;
=======
    for (const auto& day : inmate.daily_sleep) {
        cout << "Day " << day.day << ": " << day.sleep_time << endl;
>>>>>>> 1e4ed3848a8483c5b8dde74292211d444b667b6f
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
<<<<<<< HEAD
        if (line.empty()) continue;
=======
        if (line.empty()) continue; // Skip empty lines
>>>>>>> 1e4ed3848a8483c5b8dde74292211d444b667b6f
        Inmate i1;
        stringstream ss(line);

        ss >> i1.name >> i1.ear_id >> i1.minutes;

        int day = 1;
<<<<<<< HEAD
        while (!ss.eof()) {
            DailySleep daily;
            daily.day = day++;

            string sleepTime;
            ss >> sleepTime;
            daily.sleep_time = sleepTime;
=======
        while (ss >> line) {
            DailySleep daily;
            daily.day = day++;

            daily.sleep_time = line;
>>>>>>> 1e4ed3848a8483c5b8dde74292211d444b667b6f

            i1.daily_sleep.push_back(daily);
        }
        inmatesList.push_back(i1);
    }

    fin.close();
    cout << "Total inmates: " << inmatesList.size() << endl;
}

<<<<<<< HEAD
void assigndorm(vector<Inmate>& inmatesList, unordered_map<string, Dorm>& dormMap) {
    cout << endl;
    int musicID = 1;
    int channelID = 1;

    for (int i = 0; i < inmatesList.size(); i += 2) {
        if (i + 1 < inmatesList.size()) {
            Dorm d;
            d.dorm_name = "Dorm" + to_string((i / 2)  + 1);
            d.music_id = "MUSIC" + to_string(musicID);
            
            // Assign channels
            d.channels.push_back(channelID++);
            d.channels.push_back(channelID++);

            // Repeat channels after every 5 dorms
            if ((i / 2 + 1) % 5 == 0) {
                channelID = 1; // Reset channel ID
            }

            musicID++;
            dormMap[d.dorm_name] = d;
            inmatesList[i].members = 2;
            inmatesList[i + 1].members = 2;
            cout << "Assigned inmates " << inmatesList[i].name << " and " << inmatesList[i + 1].name << " to " << d.dorm_name << " having music system " << d.music_id << " with channels " << d.channels[0] << " and " << d.channels[1] << endl;
        } else {
            Dorm d;
            d.dorm_name = "Single dorm " + to_string((i / 2) + 1);
            d.music_id = "MUSIC" + to_string(musicID);
            
            // Assign channels for single dorms
            d.channels.push_back(channelID++);
            d.channels.push_back(channelID++);

            // Repeat channels after every 5 dorms
            if ((i / 2 + 1) % 5 == 0) {
                channelID = 1; // Reset channel ID
            }

            musicID++;
            dormMap[d.dorm_name] = d;
            inmatesList[i].members = 1;
            cout << "Assigned inmate " << inmatesList[i].name << " to " << d.dorm_name << " having music system " << d.music_id << " with channels " << d.channels[0] << " and " << d.channels[1] << endl;
        }
    }
}

void sleeping(vector<Inmate>& inmatesList, unordered_map<string, Dorm>& dormMap) {
    for (const auto& dorm : dormMap) {
        cout << "For " << dorm.first << ", Music System ID: " << dorm.second.music_id << ", Channels:";
        for (const auto& channel : dorm.second.channels) {
            cout << " " << channel;
        }
        cout << endl;
    }
}

int main() {
    vector<Inmate> inmatesList;
    unordered_map<string, Dorm> dormMap;
=======
int main() {
    vector<Inmate> inmatesList;
    vector<Dorm> dormlist;
>>>>>>> 1e4ed3848a8483c5b8dde74292211d444b667b6f

    insertdata(inmatesList);

    for (int i = 0; i < inmatesList.size(); ++i) {
        displayInmates(inmatesList[i]);
    }

<<<<<<< HEAD
    assigndorm(inmatesList, dormMap);

    //sleeping(inmatesList, dormMap);

=======
>>>>>>> 1e4ed3848a8483c5b8dde74292211d444b667b6f
    return 0;
}
