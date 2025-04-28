
#include <iostream>
#include <string>
using namespace std;

class DictionaryNode {
private:
    string word;        
    string meaning;     
    DictionaryNode *left;   
    DictionaryNode *right;  

public:
    // Constructor
    DictionaryNode(string word = "", string meaning = "") {
        this->word = word;
        this->meaning = meaning;
        left = NULL;
        right = NULL;
    }

    
    friend class Dictionary;
};

class Dictionary {
private:
    DictionaryNode *root;  
    int maxComparisons;    

    // Helper function to create a new node
    DictionaryNode* createNode(string word, string meaning) {
        DictionaryNode *newNode = new DictionaryNode(word, meaning);
        return newNode;
    }

    // Helper function for inorder traversal (ascending order)
    void inorderTraversal(DictionaryNode *node) {
        if (node == NULL) {
            return;
        }
        inorderTraversal(node->left);
        cout << node->word << " : " << node->meaning << endl;
        inorderTraversal(node->right);
    }

    // Helper function for reverse inorder traversal (descending order)
    void reverseInorderTraversal(DictionaryNode *node) {
        if (node == NULL) {
            return;
        }
        reverseInorderTraversal(node->right);
        cout << node->word << " : " << node->meaning << endl;
        reverseInorderTraversal(node->left);
    }

    // Helper function to find minimum value node
    DictionaryNode* findMinNode(DictionaryNode *node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

public:
    // Constructor
    Dictionary() {
        root = NULL;
        maxComparisons = 0;
    }

    // Function to add a new word to the dictionary
    void addWord() {
        string word, meaning;
        
        cout << "Enter the word: ";
        cin >> word;
        cout << "Enter the meaning: ";
        cin.ignore();  // Clear input buffer
        getline(cin, meaning);

        DictionaryNode *newNode = createNode(word, meaning);

        if (root == NULL) {
            root = newNode;
            cout << "Word added successfully!" << endl;
            return;
        }

        DictionaryNode *current = root;
        DictionaryNode *parent = NULL;

        // Find the appropriate position for the new node
        while (current != NULL) {
            parent = current;
            if (word < current->word) {
                current = current->left;
            }
            else if (word > current->word) {
                current = current->right;
            }
            else {
                cout << "Word already exists in the dictionary!" << endl;
                return;
            }
        }

        // Insert the new node
        if (word < parent->word) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }

        cout << "Word added successfully!" << endl;
    }

    // Function to search for a word
    void searchWord() {
        if (root == NULL) {
            cout << "Dictionary is empty!" << endl;
            return;
        }

        string word;
        cout << "Enter the word to search: ";
        cin >> word;

        DictionaryNode *current = root;
        int comparisons = 0;

        while (current != NULL) {
            comparisons++;
            if (word == current->word) {
                cout << "Word found!" << endl;
                cout << current->word << " : " << current->meaning << endl;
                cout << "Number of comparisons: " << comparisons << endl;
                if (comparisons > maxComparisons) {
                    maxComparisons = comparisons;
                }
                return;
            }
            else if (word < current->word) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        cout << "Word not found in the dictionary!" << endl;
        cout << "Number of comparisons: " << comparisons << endl;
    }

    // Function to update the meaning of a word
    void updateWord() {
        if (root == NULL) {
            cout << "Dictionary is empty!" << endl;
            return;
        }

        string word, newMeaning;
        cout << "Enter the word to update: ";
        cin >> word;

        DictionaryNode *current = root;
        while (current != NULL) {
            if (word == current->word) {
                cout << "Current meaning: " << current->meaning << endl;
                cout << "Enter new meaning: ";
                cin.ignore();
                getline(cin, newMeaning);
                current->meaning = newMeaning;
                cout << "Meaning updated successfully!" << endl;
                return;
            }
            else if (word < current->word) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        cout << "Word not found in the dictionary!" << endl;
    }

    // Function to delete a word
    void deleteWord() {
        if (root == NULL) {
            cout << "Dictionary is empty!" << endl;
            return;
        }

        string word;
        cout << "Enter the word to delete: ";
        cin >> word;

        DictionaryNode *current = root;
        DictionaryNode *parent = NULL;

        // Find the node to delete
        while (current != NULL && current->word != word) {
            parent = current;
            if (word < current->word) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        if (current == NULL) {
            cout << "Word not found in the dictionary!" << endl;
            return;
        }

        // Case 1: Node has no children
        if (current->left == NULL && current->right == NULL) {
            if (current == root) {
                root = NULL;
            }
            else if (parent->left == current) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
            delete current;
        }
        // Case 2: Node has one child
        else if (current->left == NULL || current->right == NULL) {
            DictionaryNode *child = (current->left != NULL) ? current->left : current->right;
            if (current == root) {
                root = child;
            }
            else if (parent->left == current) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
            delete current;
        }
        // Case 3: Node has two children
        else {
            // Find the inorder successor (smallest in the right subtree)
            DictionaryNode *successor = current->right;
            DictionaryNode *successorParent = current;

            while (successor->left != NULL) {
                successorParent = successor;
                successor = successor->left;
            }

            // Store successor's data
            string tempWord = successor->word;
            string tempMeaning = successor->meaning;

            // Delete the successor (which has at most one right child)
            if (successorParent->left == successor) {
                successorParent->left = successor->right;
            }
            else {
                successorParent->right = successor->right;
            }

            // Replace current node's data with successor's data
            current->word = tempWord;
            current->meaning = tempMeaning;

            delete successor;
        }

        cout << "Word deleted successfully!" << endl;
    }

    // Function to display words in ascending order
    void displayAscending() {
        if (root == NULL) {
            cout << "Dictionary is empty!" << endl;
            return;
        }
        cout << "\nDictionary (Ascending Order):" << endl;
        cout << "------------------------" << endl;
        inorderTraversal(root);
    }

    // Function to display words in descending order
    void displayDescending() {
        if (root == NULL) {
            cout << "Dictionary is empty!" << endl;
            return;
        }
        cout << "\nDictionary (Descending Order):" << endl;
        cout << "------------------------" << endl;
        reverseInorderTraversal(root);
    }

    // Function to display maximum comparisons
    void displayMaxComparisons() {
        cout << "Maximum comparisons required: " << maxComparisons << endl;
    }
};

int main() {
    Dictionary dict;
    int choice;

    cout << "========== DICTIONARY USING BINARY SEARCH TREE ==========" << endl;
    cout << "This program implements a dictionary using binary search tree" << endl;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add a new word" << endl;
        cout << "2. Search for a word" << endl;
        cout << "3. Update a word's meaning" << endl;
        cout << "4. Delete a word" << endl;
        cout << "5. Display words in ascending order" << endl;
        cout << "6. Display words in descending order" << endl;
        cout << "7. Display maximum comparisons" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                dict.addWord();
                break;
            case 2:
                dict.searchWord();
                break;
            case 3:
                dict.updateWord();
                break;
            case 4:
                dict.deleteWord();
                break;
            case 5:
                dict.displayAscending();
                break;
            case 6:
                dict.displayDescending();
                break;
            case 7:
                dict.displayMaxComparisons();
                break;
            case 8:
                cout << "Thank you for using the dictionary!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}

