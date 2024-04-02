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
    vector<DailySleep> daily_sleep; // Vector to hold daily sleep time
    int members;
};

class Dorm {
public:
    string dorm_name;
    int channels_id;
    string music_id;
    vector<int> channels; // Vector to hold channel IDs
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
        return;
    }

    string line;

    while (getline(fin, line)) {
        if (line.empty()) continue;
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
    int musicID = 1;
    int channelID = 1;

    for (int i = 0; i < inmatesList.size(); i += 2) {
        if (i + 1 < inmatesList.size()) {
            Dorm d;
            d.dorm_name = "Dorm" + to_string((i / 2)  + 1);
            dormlist.push_back(d);
            inmatesList[i].members = 2;
            inmatesList[i + 1].members = 2;
            dormlist.back().music_id = "MUSIC" + to_string(musicID); // Assign unique music IDs back()
            
            // Assign channels
            dormlist.back().channels.push_back(channelID++);
            dormlist.back().channels.push_back(channelID++);

            // Repeat channels after every 5 dorms
            if ((i / 2 + 1) % 5 == 0) {
                channelID = 1; // Reset channel ID
            }

            musicID++;
            cout << "Assigned inmates " << inmatesList[i].name << " and " << inmatesList[i + 1].name << " to " << d.dorm_name << " having music system " << dormlist.back().music_id << " with channels " << dormlist.back().channels[0] << " and " << dormlist.back().channels[1] << endl;
        } else {
            Dorm d;
            d.dorm_name = "Single dorm " + to_string((i / 2) + 1);
            dormlist.push_back(d);
            inmatesList[i].members = 1;
            dormlist.back().music_id = "MUSIC" + to_string(musicID); // Assign unique music IDs
            
            // Assign channels for single dorms
            dormlist.back().channels.push_back(channelID++);
            dormlist.back().channels.push_back(channelID++);

            // Repeat channels after every 5 dorms
            if ((i / 2 + 1) % 5 == 0) {
                channelID = 1; // Reset channel ID
            }

            musicID++;
            cout << "Assigned inmate " << inmatesList[i].name << " to " << d.dorm_name << " having music system " << dormlist.back().music_id << " with channels " << dormlist.back().channels[0] << " and " << dormlist.back().channels[1] << endl;
        }
    }
}

void sleeping(vector<Inmate>& inmatesList, vector<Dorm>& dormlist) {
    for (int i = 0; i < dormlist.size(); i++) {
        cout << "For " << dormlist[i].dorm_name << ", Music System ID: " << dormlist[i].music_id << ", Channels:";
        for (int j = 0; j < dormlist[i].channels.size(); ++j) {
            cout << " " << dormlist[i].channels[j];
        }
        cout << endl;
    }
}

int main() {
    vector<Inmate> inmatesList;
    vector<Dorm> dormlist;

    insertdata(inmatesList);

    for (int i = 0; i < inmatesList.size(); ++i) {
        displayInmates(inmatesList[i]);
    }

    assigndorm(inmatesList, dormlist);

    //sleeping(inmatesList, dormlist);

    return 0;
}
