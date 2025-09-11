#include <iostream>
#include <string>
using namespace std;

// -----------------------------
// Data Model
// -----------------------------
struct User {
    string username;
    string password;
    User* next;

    User(string u, string p) {
        username = u;
        password = p;
        next = nullptr;
    }
};

// -----------------------------
// Core API
// -----------------------------
bool insertUser(User*& head, const string& username, const string& password);
User* findUser(User* head, const string& username);
bool authenticate(User* head, const string& username, const string& password);
bool removeFront(User*& head);
bool removeByUsername(User*& head, const string& username);
void clearList(User*& head);
size_t size(User* head);
void printUsers(User* head);

// -----------------------------
// Main Function
// -----------------------------
int main() {
    User* head = nullptr;

    insertUser(head, "Jonathan", "pass123");
    insertUser(head, "Samuel", "qwerty");
    insertUser(head, "Maylin", "letmein");
    insertUser(head, "Adam", "secure456");
    insertUser(head, "Alex", "Liang");
   

    printUsers(head); // Jonathan -> Samuel -> Maylin -> Adam -> Alex -> NULL

    cout << "Size: " << size(head) << endl;

    cout << "Authenticate Samuel: " << (authenticate(head, "Samuel", "qwerty") ? "Success" : "Fail") << endl;

    removeByUsername(head, "Jonathan");
    printUsers(head); // Samuel -> Maylin -> Adam -> Alex -> NULL

    clearList(head);
    printUsers(head); // NULL

    return 0;
}

// -----------------------------
// Function Definitions
// -----------------------------
bool insertUser(User*& head, const string& username, const string& password) {
    if (findUser(head, username)) return false;
    User* newUser = new User(username, password);
    if (!head) {
        head = newUser;
        return true;
    }
    User* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newUser;
    return true;
}

//search of Jonathan
User* findUser(User* head, const string& username) {
    while (head) {
        if (head->username == username) return head;
        head = head->next;
    }
    return nullptr;
}

bool authenticate(User* head, const string& username, const string& password) {
    User* user = findUser(head, username);
    return user && user->password == password;
}

bool removeFront(User*& head) {
    if (!head) return false;
    User* temp = head;
    head = head->next;
    delete temp;
    return true;
}

bool removeByUsername(User*& head, const string& username) {
    if (!head) return false;
    if (head->username == username) return removeFront(head);
    User* prev = head;
    User* curr = head->next;
    while (curr) {
        if (curr->username == username) {
            prev->next = curr->next;
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

void clearList(User*& head) {
    while (head) removeFront(head);
    head = nullptr; // Ensure head is reset
}

size_t size(User* head) {
    size_t count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

void printUsers(User* head) {
    while (head) {
        cout << "[" << head->username << ":" << head->password << "] -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
