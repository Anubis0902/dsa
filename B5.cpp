#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string name;
    vector<Node*> children;
};

Node* createNode(const string& name) {
    Node* newNode = new Node{name};
    return newNode;
}

void insertChildren(Node* parent, int level) {
    int n;
    string label;
    if (level == 0) label = "chapters";
    else if (level == 1) label = "sections in chapter '" + parent->name + "'";
    else if (level == 2) label = "subsections in section '" + parent->name + "'";
    else return;

    cout << "Enter number of " << label << ": ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string childName;
        cout << "Enter name: ";
        getline(cin, childName);
        Node* child = createNode(childName);
        parent->children.push_back(child);

        insertChildren(child, level + 1);
    }
}

void displayTree(Node* root, int depth = 0) {
    if (!root) return;
    for (int i = 0; i < depth; i++) cout << "  ";
    cout << root->name << endl;
    for (Node* child : root->children) {
        displayTree(child, depth + 1);
    }
}

int main() {
    Node* book = createNode("Book");
    insertChildren(book, 0);

    cout << "\nBook Structure:\n";
    displayTree(book);

    return 0;
}
