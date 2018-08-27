#include <iostream>
using namespace std;

class Node {
public:
    Node* next = nullptr;
    int value = 0;
    Node(int v) {
        value = v;        
    }
};

class List {
public:
    Node* first = nullptr;
    void add(Node* n) {
        if (first == nullptr) {
            first = n;
        } else {
            auto* it = first;
            while (it->next != nullptr) {
                it = it->next;
            }
            it->next = n;
        }
    };
    void removeFirst() {
        if (first != nullptr) {
            auto next = first->next;
            delete first;
            first = next;
        }
    };
    void remove(Node* prev) {
        auto target = prev->next;
        if (target != nullptr) {
            prev->next = target->next;
            delete target;
        }
    };
    void insertFirst(Node* newNode) {
        auto np = first;
        first = newNode;
        first->next = np;
    }
    void insert(Node* prev, Node* newNode) {
        auto currentNext = prev->next;
        prev->next = newNode;
        prev->next->next = currentNext;
    }
    Node* getLast() {
        auto n = first;
        if (n == nullptr) {
            return n;
        }
        while (n->next != nullptr) {
            n = n->next;
        }
        return n;
    }
};

void outputList(List* l) {
    auto* it = l->first;
    while (it != nullptr) {
        cout << it->value;
        it = it->next;
        if (it != nullptr) {
            cout << "->";
        }
    }
    cout << endl;
}
int main() {
    List list;
    for (int i = 0; i < 10; i++) {
        list.add(new Node(i));
    }

    outputList(&list);
    list.removeFirst();
    outputList(&list);
    auto n = list.first->next->next->next->next;
    cout << n->value << endl;
    list.remove(n);
    outputList(&list);
    list.insertFirst(new Node(99));
    outputList(&list);
    n = list.first->next->next->next->next->next->next;
    cout << n->value << endl;
    list.insert(n, new Node(77));
    outputList(&list);
    list.remove(list.first);
    outputList(&list);
    n = list.getLast();
    list.remove(n);
    outputList(&list);
    list.insert(n, new Node(123));
    outputList(&list);
    list.remove(n);
    outputList(&list);
    
    return 0;
}