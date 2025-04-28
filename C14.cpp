#include <iostream>
#include <vector>
#include <string>
using namespace std;

class FlightGraph {
    vector<string> cities;
    vector<vector<int>> distance;

public:
    void addFlight(string from, string to, int dist) {
        int fromIndex = findCity(from);
        int toIndex = findCity(to);

        distance[fromIndex][toIndex] = dist;
        distance[toIndex][fromIndex] = dist;
    }

    void display() {
        cout << "\nFlight Distance Matrix:\n\n\t";
        for (string city : cities)
            cout << city << "\t";
        cout << endl;

        for (int i = 0; i < cities.size(); i++) {
            cout << cities[i] << "\t";
            for (int j = 0; j < cities.size(); j++) {
                cout << distance[i][j] << "\t";
            }
            cout << endl;
        }
    }

private:
    int findCity(string name) {
        for (int i = 0; i < cities.size(); i++) {
            if (cities[i] == name)
                return i;
        }
        cities.push_back(name);
        for (auto& row : distance)
            row.push_back(0);
        distance.push_back(vector<int>(cities.size(), 0));
        return cities.size() - 1;
    }
};

int main() {
    FlightGraph g;
    int n;
    cout << "How many flights you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string from, to;
        int dist;
        cout << "\nEnter source city: ";
        cin >> from;
        cout << "Enter destination city: ";
        cin >> to;
        cout << "Enter distance (in km): ";
        cin >> dist;

        g.addFlight(from, to, dist);
    }

    g.display();

    return 0;
}