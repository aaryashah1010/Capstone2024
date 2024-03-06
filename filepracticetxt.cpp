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
};

class dorm {
public:
    string dorm_name;
    int channels_id;
    int music_id;
};

void displayInmates(const inmates& inmate) {
    cout << "Name: " << inmate.name << endl;
    cout << "Ear ID: " << inmate.ear_id << endl;
    cout << "Minutes: " << inmate.minutes << endl;
    cout << "Sleep Time: ";
    for(int i = 0; i < inmate.sleep_time.size(); i++) {
        cout << inmate.sleep_time[i] << " ";
    }
    cout << endl;
}

void insertdata(inmates &i1) {
    ifstream fin("cap.txt");
    if (!fin.is_open()) {
        cerr << "Unable to open file" << endl;
        return;
    }

    string line;
    int i = 0; // Initialize i to count the number of inmates

    while (getline(fin, line)) {
        stringstream ss(line);
        ss >> i1.name >> i1.ear_id >> i1.minutes;
        i1.sleep_time.clear(); // Clear sleep_time vector
        int sleep_hour;
        while (ss >> sleep_hour) {
            i1.sleep_time.push_back(sleep_hour);
        }
        i++; // Increment i for each inmate read
    }

    fin.close();
    cout << "Total inmates: " << i << endl;
}

int main() {
    inmates i1;
    insertdata(i1);
    displayInmates(i1); // Display the data read into i1
    return 0;
}
