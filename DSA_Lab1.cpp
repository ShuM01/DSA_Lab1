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

    removeByUsername(head, "Samuel");
    printUsers(head); // Jonathan -> Maylin -> Adam -> Alex -> NULL

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

User* findUser(User* head, const string& username) {
    while (head) {
        if (head->username == username) return head;
        head = head->next