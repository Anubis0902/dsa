#include <iostream>
#include <vector>
#include <queue>   // for priority_queue
#include <algorithm> // for min_element
using namespace std;

class students
{
    vector<int> marks;
    priority_queue<int> maxHeap; // By default, this is a Max Heap

public:
    void insert();
    void display();
    void maxMarks();
    void minMarks();
};

void students::insert()
{
    int total;
    cout << "How many students? ";
    cin >> total;

    cout << "Enter marks of " << total << " students:\n";
    for (int i = 0; i < total; i++) {
        int mark;
        cout << "Enter marks of student " << i + 1 << ": ";
        cin >> mark;
        marks.push_back(mark); 
        maxHeap.push(mark); // Push into max heap
    }
}

void students::display()
{
    if (marks.empty()) {
        cout << "No marks entered yet.\n";
        return;
    }

    cout << "Marks of all students:\n";
    for (int mark : marks) {
        cout << mark << " ";
    }
    cout << endl;
}

void students::maxMarks()
{
    if (maxHeap.empty()) {
        cout << "No marks entered yet.\n";
        return;
    }

    cout << "Maximum marks: " << maxHeap.top() << endl;
}

void students::minMarks()
{
    if (marks.empty()) {
        cout << "No marks entered yet.\n";
        return;
    }

    int minMark = *min_element(marks.begin(), marks.end());
    cout << "Minimum marks: " << minMark << endl;
}

int main()
{
    int ch, cont;
    students s;
    do {
        cout << "\n======= MENU =======";
        cout << "\n1. Read marks of the students";
        cout << "\n2. Display all marks";
        cout << "\n3. Find Max Marks";
        cout << "\n4. Find Min Marks";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                s.insert();
                break;
            case 2:
                s.display();
                break;
            case 3:
                s.maxMarks();
                break;
            case 4:
                s.minMarks();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        cout << "\nDo you want to continue? (1 for Yes / 0 for No): ";
        cin >> cont;
    } while (cont == 1);

    return 0;
}
