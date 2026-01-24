#include "queue.h"
#include <iostream>
#include <string.h>
using namespace std;

// Constructor implementation
ListQueue::ListQueue()
{
    front_node = rear_node = NULL;
    current_size = 0;
}

// Destructor implementation
ListQueue::~ListQueue()
{
    // TODO: Deallocate all nodes in the linked list
    // TODO: Consider using the clear() method
    clear();
}

// Enqueue implementation (add an item at the rear of the queue)
void ListQueue::enqueue(int item)
{
    // TODO: Create a new node with the given item
    // TODO: Link the new node to the rear
    // TODO: Update the rear_node
    // TODO: Increment the current size
    Node *newNode = new Node(item);
    if (empty())
    {
        front_node = rear_node = newNode;
        current_size++;
        return;
    }

    rear_node->next = newNode;
    rear_node = newNode;
    current_size++;
}

// Dequeue implementation (remove an item from the front of the queue)
int ListQueue::dequeue()
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Store the data from the front node
    // TODO: Update the front pointer to the next node
    // TODO: Update the rear pointer if the queue becomes empty
    // TODO: Delete the old front node
    // TODO: Decrement current_size
    // TODO: Return the stored data
    if (empty())
    {
        cout << "Queue is empty !" << endl;
        return -1;
    }

    Node *temp = front_node;
    front_node = front_node->next;
    if (front_node == NULL)
        rear_node = NULL;
    int val = temp->data;
    delete temp;
    current_size--;
    return val;
}

// Clear implementation (delete all elements)
void ListQueue::clear()
{
    // TODO: Traverse the linked list and delete each node
    // TODO: Reset front and rear pointer
    // TODO: Reset current_size to 0
    if (empty())
        return;
    while (!empty())
    {
        dequeue();
    }
}

// Size implementation (return the current number of elements)
int ListQueue::size() const
{
    // TODO: Return the current size (current_size)
    return current_size;
}

// Front implementation (get the element at the front of the queue)
int ListQueue::front() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the data from the front node without removing it
    if (empty())
    {
        cout << "Queue is empty !" << endl;
        return -1;
    }
    return front_node->data;
}

// Back implementation (get the element at the back of the queue)
int ListQueue::back() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the data from the back node without removing it
    if (empty())
    {
        cout << "Queue is empty !" << endl;
        return -1;
    }
    return rear_node->data;
}

// Empty implementation (check if the queue is empty)
bool ListQueue::empty() const
{
    // TODO: Return whether front is nullptr
    return front_node == NULL;
}

// Print implementation (print elements from front to rear)
string ListQueue::toString() const
{
    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
    // TODO: Traverse the linked list from front
    string str = "<";
    Node *temp = front_node;
    while (temp != NULL)
    {
        str += to_string(temp->data);
        temp = temp->next;
        if (temp != NULL)
            str += ",";
    }
    str += "|";
    return str;
}

/* 
Compiling Commands: g++ -std=c++11 listqueue_tester.cpp listqueue.cpp -o main
 ./main 1000
*/
