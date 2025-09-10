#include <iostream>
using namespace std;

main int


//insertUser
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


//findUser
User* findUser(User* head, const string& username) {
    while (head) {
        if (head->username == username) return head;
        head = head->next;
    }
    return nullptr;
}


//authenticate
bool authenticate(User* head, const string& username, const string& password) {
    User* user = findUser(head, username);
    return user && user->password == password;
}

//removeFront
bool removeFront(User*& head) {
    if (!head) return false;
    User* temp = head;
    head = head->next;
    delete temp;
    return true;
}

/removeusername
bool removeByUsername(User*& head, const string& username) {
    if (!head) return false;

    if (head->username == username) {
        return removeFront(head);
    }

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

//clearList
void clearList(User*& head) {
    while (head) {
        removeFront(head);
    }
}


//size
size_t size(User* head) {
    size_t count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}


//printUsers
void printUsers(User* head) {
    while (head) {
        cout << head->username << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

