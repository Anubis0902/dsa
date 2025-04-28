#include<iostream>
using namespace std;

#define MAX 20

class MST {
private:
    int offices;
    int cost[MAX][MAX];

public:
    void input() {
        cout << "Enter number of offices (max 20): ";
        cin >> offices;

        // Initialize all costs to 0
        for(int i = 0; i < offices; i++) {
            for(int j = 0; j < offices; j++) {
                cost[i][j] = 0;
            }
        }

        int connections;
        cout << "Enter number of possible connections: ";
        cin >> connections;

        cout << "Enter connection details (office1 office2 cost):\n";
        for(int i = 0; i < connections; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            cost[u-1][v-1] = w;
            cost[v-1][u-1] = w;
        }
    }

    void prims() {
        bool selected[MAX] = {false};
        int totalCost = 0;

        selected[0] = true;

        cout << "\nConnections in MST:\n";

        for(int edges = 0; edges < offices - 1; edges++) {
            int minCost = -1;
            int a = -1, b = -1;

            for(int i = 0; i < offices; i++) {
                if(selected[i]) {
                    for(int j = 0; j < offices; j++) {
                        if(!selected[j] && cost[i][j] != 0) {
                            if(minCost == -1 || cost[i][j] < minCost) {
                                minCost = cost[i][j];
                                a = i;
                                b = j;
                            }
                        }
                    }
                }
            }

            if(a != -1 && b != -1) {
                cout << "Office " << a+1 << " - Office " << b+1 << " : Cost = " << minCost << endl;
                totalCost += minCost;
                selected[b] = true;
            }
        }

        cout << "\nTotal minimum cost: " << totalCost << endl;
    }
};

int main() {
    MST obj;
    obj.input();
    obj.prims();
    return 0;
}
