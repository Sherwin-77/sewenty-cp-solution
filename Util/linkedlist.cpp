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

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next, *prev;

    Node(T _data) : data(_data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class LinkedList {
   private:
    Node<T> *head, *tail;

   public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    Node<T> *getHead() {
        return head;
    }

    Node<T> *getTail() {
        return tail;
    }

    Node<T> *insertAfterNode(Node<T> *node, Node<T> *newNode) {
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

    Node<T> *insertAtHead(Node<T> *newNode) {
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

    Node<T> *insertAtTail(Node<T> *newNode) {
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
        Node<T> *temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            temp = temp->next;
        }
        cout << '\n';
    }

    void clear() {
        Node<T> *temp = head;
        while (temp != nullptr) {
            Node<T> *next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
        tail = nullptr;
    }

    Node<T> *deleteNode(Node<T> *node) {
        if (node == nullptr) {
            return nullptr;
        }
        Node<T> *prevNode = node->prev;
        if (node == head && node == tail) {
            head = nullptr;
            tail = nullptr;
        } else if (node == head) {
            Node<T> *temp = head->next;
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

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    // Create a linked list
    LinkedList<int> list;

    // Insert elements into the list
    list.insertAtHead(new Node<int>(1));
    list.insertAtTail(new Node<int>(2));
    list.insertAtTail(new Node<int>(3));

    // Print the list
    list.printList();

    // Delete an element from the list
    list.deleteNode(list.getHead());
    list.printList();

    // Insert after
    Node<int> *nodeToInsertAfter = list.getHead();
    list.insertAfterNode(nodeToInsertAfter, new Node<int>(4));
    list.printList();
}
