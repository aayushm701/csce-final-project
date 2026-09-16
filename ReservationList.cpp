#include "ReservationList.h"

ReservationList::Node::Node(const Reservation& reservation, Node* nextNode)
    : value(reservation), next(nextNode) {}

ReservationList::~ReservationList() {
    // Clear the list before the object is destroyed.
    clear();
}

void ReservationList::add(const Reservation& reservation) {
    // New nodes are placed at the beginning for quick insertion.
    head = new Node(reservation, head);
}

bool ReservationList::remove(int id, Reservation& removed) {
    Node* previous = nullptr;
    Node* current = head;
    while (current != nullptr) {
        if (current->value.id == id) {
            removed = current->value;
            // Connect the previous node to the node after the one being removed.
            if (previous == nullptr) head = current->next;
            else previous->next = current->next;
            delete current;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

Reservation* ReservationList::find(int id) {
    // Visit each node until the requested reservation is found.
    for (Node* current = head; current != nullptr; current = current->next) {
        if (current->value.id == id) return &current->value;
    }
    return nullptr;
}

const Reservation* ReservationList::find(int id) const {
    for (const Node* current = head; current != nullptr; current = current->next) {
        if (current->value.id == id) return &current->value;
    }
    return nullptr;
}

std::vector<Reservation> ReservationList::toVector() const {
    std::vector<Reservation> result;
    // A copy is useful when another operation needs normal vector traversal.
    for (const Node* current = head; current != nullptr; current = current->next) {
        result.push_back(current->value);
    }
    return result;
}

int ReservationList::size() const {
    int count = 0;
    for (const Node* current = head; current != nullptr; current = current->next) ++count;
    return count;
}

void ReservationList::clear() {
    // Delete nodes one at a time to avoid losing the next pointer.
    while (head != nullptr) {
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
    }
}