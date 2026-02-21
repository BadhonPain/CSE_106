#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <climits>
#include <algorithm>

#define MAX_CAPACITY 1000 // Defines the maximum capacity of the heap

class MinHeap
{
private:
    int heap[MAX_CAPACITY]; // Array to store heap elements
    int size;               // Current number of elements in the heap

    /**
     * Sifts up the node at index i to maintain heap property.
     */
    void siftUp(int i)
    {
        while (i > 0 && heap[i] < heap[(i - 1) / 2])
        {
            std::swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    /**
     * Sifts down the node at index i to maintain heap property.
     */
    void siftDown(int i)
    {
        while (1)
        {
            int leftChildIdx = 2 * i + 1;
            int rightChildIdx = 2 * i + 2;
            int smallest = i;

            if (leftChildIdx < size && heap[leftChildIdx] < heap[i])
                smallest = leftChildIdx;

            if (rightChildIdx < size && heap[rightChildIdx] < heap[smallest])
                smallest = rightChildIdx;

            if (smallest != i)
            {
                std::swap(heap[i], heap[smallest]);
                i = smallest;
            }
            else
                break;
        }
    }

public:
    // Constructor initializes an empty heap
    MinHeap() : size(0) {}

    /**
     * Inserts a new element x into the heap.
     */
    void insert(int x)
    {
        if (size >= MAX_CAPACITY)
        {
            std::cerr << "Heap is Full!" << std::endl;
            return;
        }
        heap[size] = x;
        siftUp(size);
        size++;
    }

    /**
     * Returns the minimum element without removing it.
     */
    int findMin()
    {
        if (isEmpty())
        {
            std::cerr << "Heap is empty! " << std::endl;
            return INT_MIN;
        }
        return heap[0];
    }

    /**
     * Removes and returns the minimum element from the heap.
     */
    int extractMin()
    {
        if (isEmpty())
        {
            std::cerr << "Heap is empty! " << std::endl;
            return INT_MIN;
        }

        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        if (!isEmpty())
            siftDown(0);

        return root;
    }

    /**
     * Returns the number of elements in the heap.
     */
    int getSize()
    {
        return size;
    }

    /**
     * Checks if the heap is empty.
     * Returns true if empty, false otherwise.
     */
    bool isEmpty()
    {
        return size == 0;
    }

    /**
     * Decreases the value of the element at index i to newValue.
     */
    void decreaseKey(int i, int newValue)
    {
        if (i < 0 || i >= size)
        {
            std::cerr << "Index out of bounds !" << std::endl;
            return;
        }

        if (heap[i] < newValue)
        {
            std::cerr << "New value should be less than peek." << std::endl;
            return;
        }

        heap[i] = newValue;
        siftUp(i);
    }

    /**
     * Deletes the element at index i.
     */
    void deleteKey(int i)
    {
        if (i < 0 || i >= size)
        {
            std::cerr << "Index out of bounds !" << std::endl;
            return;
        }

        decreaseKey(i, INT_MIN);
        int removedRoot = extractMin();
    }

    /**
     * Prints the heap's content to the output file.
     * Format: "elem1 elem2 elem3 ..." (space-separated)
     */
    void printHeap(std::ofstream &outfile)
    {
        for (int i = 0; i < size; i++)
        {
            outfile << heap[i] << " ";
        }
        outfile << std::endl;
    }

    /**
     * Checks whether the Min Heap property is preserved.
     * Returns true if valid, false otherwise.
     */
    bool isValidMinHeap()
    {
        if (size <= 1)
            return true;
        int length = size - 1;

        while (length)
        {
            if (heap[length] < heap[(length - 1) / 2])
                return false;
            length--;
        }
        return true;
    }

    /**
     * Builds a heap from an unsorted array using bottom-up heapify.
     */
    void heapify(int arr[], int n)
    {
        if (n > MAX_CAPACITY)
        {
            std::cerr << "Limit exceeds!" << std::endl;
            return;
        }

        size = n;

        for (int i = 0; i < size; i++)
        {
            heap[i] = arr[i];
        }

        for (int i = size / 2 - 1; i >= 0; i--)
        {
            siftDown(i);
        }
    }

    /**
     * Returns all elements in sorted (ascending) order.
     * The original heap should remain UNCHANGED after this operation.
     */
    void heapSort(std::ofstream &outfile)
    {
        int tempHeap[MAX_CAPACITY];
        int tempHeapSize = size;

        for (int i = 0; i < tempHeapSize; i++)
        {
            tempHeap[i] = heap[i];
        }

        while (!isEmpty())
        {
            outfile << extractMin() << " ";
        }
        outfile << std::endl;

        size = tempHeapSize;

        for (int i = 0; i < size; i++)
        {
            heap[i] = tempHeap[i];
        }
    }

    /**
     * Replaces the minimum element with a new value x in a single operation.
     * Returns the old minimum value.
     */
    int replaceMin(int x)
    {
        if (isEmpty())
        {
            std::cerr << "Heap is empty! " << std::endl;
            return INT_MIN;
        }

        int oldMin = heap[0];
        heap[0] = x;
        if (oldMin < x)
            siftDown(0);

        return oldMin;
    }
};

#endif // MINHEAP_H
