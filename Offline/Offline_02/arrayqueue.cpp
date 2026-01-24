#include "queue.h"
#include <iostream>
using namespace std;
// Constructor implementation
ArrayQueue::ArrayQueue(int initial_capacity)
{
    // TODO: Initialize data members (data, capacity, front_idx, rear_idx)
    // TODO: Allocate memory for the array with the specified initial capacity
    data = new int[initial_capacity];
    capacity = initial_capacity;
    front_idx = -1;
    rear_idx = -1;
}

// Destructor implementation
ArrayQueue::~ArrayQueue()
{
    // TODO: Free the dynamically allocated memory for the array
    delete[] data;
    capacity = 0;
    front_idx = -1;
    rear_idx = -1;
}

// Enqueue implementation (add an item to the rear of the queue)
void ArrayQueue::enqueue(int item)
{
    // TODO: Check if the array is full
    // TODO: If full, resize the array to double its current capacity
    // TODO: Add the new element to the rear of the queue
    int length = size();

    if (length == capacity)
        resize(capacity * 2);

    if (empty())
    {
        front_idx++;
        rear_idx++;
    }
    else
        rear_idx = (rear_idx + 1) % capacity;

    data[rear_idx] = item;
}

// Dequeue implementation (remove an item from the front of the queue)
int ArrayQueue::dequeue()
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Decrement current_size and return the element at the front of the queue
    // TODO: Update front index
    // TODO: If the array is less than 25% full, resize it to half its current capacity (but not less than 2)
    // TODO: Return the dequeued element
    if (empty())
    {
        cout << "Queue is empty !" << endl;
        return -1;
    }

    int val = data[front_idx];

    if (size() == 1)
        front_idx = rear_idx = -1;
    else
        front_idx = (front_idx + 1) % capacity;

    int length = size();
    if (length > 0 && length <= capacity / 4 && capacity > 2)
        resize(capacity / 2);

    return val;
}

// Clear implementation
void ArrayQueue::clear()
{
    // TODO: Reset the queue to be empty (reset capacity, front_idx, rear_idx, data)
    delete[] data;
    capacity = 2;
    front_idx = -1;
    rear_idx = -1;
    data = new int[capacity];
}

// Size implementation
int ArrayQueue::size() const
{
    // TODO: Return the number of elements currently in the queue
    if (front_idx == -1 || rear_idx == -1)
        return 0;
    return ((rear_idx - front_idx + capacity) % capacity + 1);
}

// Front implementation
int ArrayQueue::front() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the element at the front of the queue without removing it
    if (!size())
    {
        cout << "Queue is empty !" << endl;
        return -1;
    }
    return data[front_idx];
}

// Back implementation (get the element at the back of the queue)
int ArrayQueue::back() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the element at the back of the queue without removing it
    if (!size())
    {
        cout << "Queue is empty !" << endl;
        return -1;
    }
    return data[rear_idx];
}

// Empty implementation
bool ArrayQueue::empty() const
{
    // TODO: Return whether the queue is empty (current_size == 0)
    return size() == 0;
}

// Print implementation
string ArrayQueue::toString() const
{
    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
    string str = "<";
    int length = size();
    for (int i = 0; i < length; i++)
    {
        str += to_string(data[(front_idx + i) % capacity]);

        if (i != length - 1)
            str += ",";
    }
    str += "|";
    return str;
}

// Resize implementation
void ArrayQueue::resize(int new_capacity)
{
    // TODO: Create a new array with the new capacity
    // TODO: Copy elements from the old array to the new array
    // TODO: Delete the old array
    // TODO: Update the data pointer and capacity
    // TODO: Update front and rear indices
    int *new_array = new int[new_capacity];

    int length = size();
    for (int i = 0; i < length; i++)
    {
        new_array[i] = data[(front_idx + i) % capacity];
    }

    delete[] data;
    data = new_array;
    capacity = new_capacity;

    if (empty())
    {
        front_idx = -1;
        rear_idx = -1;
        return;
    }

    front_idx = 0;
    rear_idx = length - 1;
}

int ArrayQueue::getCapacity() const
{
    // TODO: Return the current capacity of the queue
    return capacity;
}

/* 
Compiling Commands: g++ -std=c++11 arrayqueue_tester.cpp arrayqueue.cpp -o main
 ./main 1000
*/