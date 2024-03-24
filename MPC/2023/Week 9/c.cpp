#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// #define int long long

void fileIO(string fileName, string inExt = ".in", string outExt = ".out") {
    string fIn = fileName + inExt;
    string fOut = fileName + outExt;
    freopen(fIn.c_str(), "r", stdin);
    freopen(fOut.c_str(), "w", stdout);
}

template <typename T>
void debug(T const &value, std::string valueName) {
    cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}
template <typename T>
void debug(T const &value, std::string valueName, int index) {
    cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}

template <typename T>
void print(T const &value, bool newLine = true) {
    cout << value;
    if (newLine) cout << '\n';
}

// Alternative
typedef long long ll;

class Node {
   public:
    char data;
    Node *next, *prev;

    Node(char _data) {
        data = _data;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList {
   private:
    Node *head, *tail;

   public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    Node *getHead() {
        return head;
    }

    Node *getTail() {
        return tail;
    }

    Node *insertAtHead(Node *newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        newNode->prev = nullptr;
        return newNode;
    }

    Node *insertAfterNode(Node *node, Node *newNode) {
        if (node == nullptr) {
            return nullptr;
        }
        newNode->next = node->next;
        if (node->next != nullptr) {
            node->next->prev = newNode;
        }
        node->next = newNode;
        newNode->prev = node;
        if (node == tail) {
            tail = newNode;
        }
        return newNode;
    }

    Node *insertAtEnd(Node *newNode) {
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        return newNode;
    }

    void printList() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            temp = temp->next;
        }
        cout << '\n';
    }

    bool isHead(Node *node) {
        return (node == head);
    }

    void clear() {
        Node *temp = head;
        while (temp != nullptr) {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
        tail = nullptr;
    }

    Node *deleteNode(Node *node) {
        if (node == nullptr) {
            return nullptr;
        }
        Node *prevNode = node->prev;
        if (node == head && node == tail) {
            head = nullptr;
            tail = nullptr;
        } else if (node == head) {
            Node *temp = head->next;
            head = temp;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            if (node == tail) {
                tail = nullptr;
            }
        } else if (node == tail) {
            tail->prev->next = nullptr;
            tail = tail->prev;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        delete node;
        return prevNode;
    }

    ~LinkedList() {
        clear();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    string s;
    getline(cin, s);
    while (t--) {
        getline(cin, s);
        bool isHead = false;
        LinkedList list;
        Node *currentPosition = list.getHead();
        for (char c : s) {
            /**
             * [ - means go to head - 1 (if we insert here, we insert before head. Delete will do nothing)
             * ] - means go to tail (if we insert here, we insert after tail. Delete will delete tail)
             * < - means delete current position (backspace behaviour)
             */
            if (c == '[') {
                isHead = true;
                currentPosition = list.getHead();
            } else if (c == ']') {
                isHead = false;
                currentPosition = list.getTail();
            } else if (c == '<') {
                if (!isHead) {
                    if (currentPosition != nullptr) {
                        currentPosition = list.deleteNode(currentPosition);
                    }
                }
            } else {
                Node *newNode = new Node(c);
                if (isHead) {
                    currentPosition = list.insertAtHead(newNode);
                    isHead = false;
                } else {
                    if (currentPosition != nullptr) {
                        currentPosition = list.insertAfterNode(currentPosition, newNode);
                    } else {
                        currentPosition = list.insertAtHead(newNode);
                    }
                }
            }
        }
        list.printList();
    }
}
