#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
using namespace std;
template <typename T>
class Queue {
private:
    T* arr;
    size_t capacity;
    int read;
    int write;
    size_t size;

public:
    // Constructor
    Queue(size_t initialCapacity = 10) {
        capacity = initialCapacity;
        arr = new T[capacity];
        read = write = 0;
        size = 0;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Function to enqueue an element
    void enqueue(const T& element) {
        if (isFull()) {
            // Resize the array if full
            resize();
            // return;
        }
        arr[write] = element;
        write = (write + 1) % capacity;
        size++;
    }

    // Function to dequeue an element
    void dequeue() {
        if (isEmpty()) {
            cerr << "Error: Queue is empty. Cannot dequeue.\n";
            return;
        }

        if (read != write) {
            read = (read + 1) % capacity;
            size--;
            // reset read and right
            if (isEmpty()) {
                read = write = 0;
            }
        }
    }

    // Function to get the element at the front of the queue
    T frontElement() const {
        if (isEmpty()) {
            cerr << "Error: Queue is empty. No front element.\n";
            exit(1);
        }
        return arr[read];
    }

    // Function to check if the queue is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Function to check if the queue is full
    bool isFull() const {
        return size == capacity;
    }

    // Function to get the current size of the queue
    size_t getSize() const {
        return size;
    }

    // Function to resize the array
    void resize() {
        size_t new_capacity = max(2*static_cast<int>(size), 2);
        T* brr = new T[new_capacity];
        for (int i=0; i< size; i++)
            brr[i] = arr[(read+i)%capacity];
            delete [] arr;
        arr = brr;
        capacity = new_capacity;
        read = 0; write = size;
    }

};

#endif // QUEUE_H
