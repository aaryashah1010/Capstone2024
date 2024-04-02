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
    int members; // Indicates whether it's a single or double occupancy
    string dorm_name; // Name of the dormitory
    vector<int> music_channels; // Music channels assigned (numbers)
    vector<string> music_per_channel; // Music per channel (string)
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
        string token;

        // Read comma-separated values from the line
        getline(ss, inmate.name, ',');
        getline(ss, token, ',');
        inmate.ear_id = stoi(token);// stoi is used to convert string into number
        
        for (int day = 1; day <= 7; ++day) {
            DailySleep daily;
            getline(ss, daily.sleep_time, ',');
            daily.day = day;
            inmate.daily_sleep.push_back(daily);
        }

        getline(ss, token, ',');
        inmate.minutes = stoi(token);

        getline(ss, inmate.dorm_name, ',');

        // Read music channels and music per channel
        while (getline(ss, token, ',')) {
            int channel = stoi(token);
            inmate.music_channels.push_back(channel);

            getline(ss, token, ',');
            inmate.music_per_channel.push_back(token);
        }

        inmatesList.push_back(inmate);
    }

    fin.close();
    cout << "Total inmates: " << inmatesList.size() << endl;
}

void assignDorm(vector<Inmate>& inmatesList) {
    // Group inmates by dormitory
    vector<vector<Inmate>> dormitories;

    for (const auto& inmate : inmatesList) {
        bool found = false;
        for (auto& dorm : dormitories) {
            if (dorm[0].dorm_name == inmate.dorm_name) {
                dorm.push_back(inmate);
                found = true;
                break;
            }
        }
        if (!found) {
            dormitories.push_back({inmate});
        }
    }

    // Display dormitory assignments
    for (const auto& dorm : dormitories) {
        cout << "Dormitory: " << dorm[0].dorm_name << endl;
        for (const auto& inmate : dorm) {
            cout << "Assigned inmate " << inmate.name << endl;
        }
        cout << endl;
    }
}
void pminutes(vector<Inmate>inmateList,vector<vector<Inmate>> dormitories)
{
        int i=0;
       
          for(const auto&dorm:dormitories)
          { 
            for(int i=1;i<dorm.size();i++)
            {
                 int ans=dorm[0].minutes;
                if(dorm[0].minutes > dorm[i].minutes)
                {
                    ans=dorm[i].minutes;
                }
            } 
          }
}

int main() {
    vector<Inmate> inmatesList;

    inputDataFromFile(inmatesList, "cap3.txt");

    for (const auto& inmate : inmatesList) {
        displayInmates(inmate);
    }

    assignDorm(inmatesList);

    return 0;
}
