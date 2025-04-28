#include <iostream>
#include <set>
using namespace std;

class SetOperations {
    set<int> A, B;

public:
    void inputSets() {
        int n, x;
        cout << "Enter elements of Set A: ";
        cin >> n;
        while (n--) {
            cin >> x;
            A.insert(x);
        }

        cout << "Enter elements of Set B: ";
        cin >> n;
        while (n--) {
            cin >> x;
            B.insert(x);
        }
    }

    void displaySets() {
        cout << "Set A: ";
        for (int x : A) cout << x << " ";
        cout << "\nSet B: ";
        for (int x : B) cout << x << " ";
        cout << endl;
    }

    void addElement() {
        char ch;
        int x;
        cout << "Add to (A/B)? ";
        cin >> ch;
        cout << "Enter element: ";
        cin >> x;

        if (ch == 'A' || ch == 'a')
            A.insert(x);
        else if (ch == 'B' || ch == 'b')
            B.insert(x);
        else
            cout << "Invalid set!" << endl;
    }

    void deleteElement() {
        int x;
        cout << "Element to delete: ";
        cin >> x;
        A.erase(x);
        B.erase(x);
    }

    void searchElement() {
        int x;
        cout << "Element to search: ";
        cin >> x;
        if (A.count(x)) cout << x << " found in Set A\n";
        if (B.count(x)) cout << x << " found in Set B\n";
        if (!A.count(x) && !B.count(x)) cout << x << " not found\n";
    }

    void findUnion() {
        set<int> result = A;
        result.insert(B.begin(), B.end());
        cout << "Union: ";
        for (int x : result) cout << x << " ";
        cout << endl;
    }

    void findIntersection() {
        cout << "Intersection: ";
        bool found = false;
        for (int x : A)
            if (B.count(x)) {
                cout << x << " ";
                found = true;
            }
        if (!found) cout << "No common elements.";
        cout << endl;
    }

    void findDifference() {
        cout << "Difference (A - B): ";
        bool found = false;
        for (int x : A)
            if (!B.count(x)) {
                cout << x << " ";
                found = true;
            }
        if (!found) cout << "Set A is a subset of Set B.";
        cout << endl;
    }
};

int main() {
    SetOperations s;
    int choice;
    cout << "==== Set Operations ====" << endl;
    s.inputSets();

    do {
        cout << "\nMenu:\n1.Add\n2.Delete\n3.Search\n4.Display\n5.Union\n6.Intersection\n7.Difference\n8.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: s.addElement(); break;
            case 2: s.deleteElement(); break;
            case 3: s.searchElement(); break;
            case 4: s.displaySets(); break;
            case 5: s.findUnion(); break;
            case 6: s.findIntersection(); break;
            case 7: s.findDifference(); break;
            case 8: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    return 0;
}
