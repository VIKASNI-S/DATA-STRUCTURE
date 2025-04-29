//Menu driven program to implement Priority Queue ADT using max heap#include <iostream>
#include <iostream>
using namespace std;

#define MAX 100

class PriorityQueue {
private:
    int heap[MAX];
    int size;

    void heapify_up(int index) {
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapify_down(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify_down(largest);
        }
    }

public:
    PriorityQueue() {
        size = 0;
    }
//Function to insert an element into the heap
    void insert(int value) {
        if (size == MAX) {
            cout << "Heap is full!\n";
            return;
        }
        heap[size] = value;
        heapify_up(size);
        size++;
    }
//Function to delete an element from the heap
    void deleteMax() {
        if (size == 0) {
            cout << "Heap is empty!\n";
            return;
        }
        cout << "Deleted max element: " << heap[0] << endl;
        heap[0] = heap[size - 1];
        size--;
        heapify_down(0);
    }
//Function to display the contents of the heap
    void display() {
        if (size == 0) {
            cout << "Heap is empty!\n";
            return;
        }
        cout << "Heap contents: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
//Function to sort(Heap sort)
    void sort() {
        if (size == 0) {
            cout << "Heap is empty!\n";
            return;
        }
        int temp[MAX];
        int tempSize = size;
        for (int i = 0; i < size; i++) temp[i] = heap[i];

        cout << "Heap Sort (descending): ";
        while (size > 0) {
            cout << heap[0] << " ";
            heap[0] = heap[size - 1];
            size--;
            heapify_down(0);
        }
        cout << endl;

        for (int i = 0; i < tempSize; i++) heap[i] = temp[i];
        size = tempSize;
    }
//Function to search for an element
    bool search(int value) {
        for (int i = 0; i < size; i++) {
            if (heap[i] == value)
                return true;
        }
        return false;
    }
};

// --- MAIN FUNCTION ---
int main() {
    PriorityQueue pq;
    int choice, value;

    do {
        cout << "\nMenu Driven Program\n";
        cout << "1) Insert\n2) Delete Max\n3) Display\n4) Search\n5) Sort (Heap Sort)\n6) Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            pq.insert(value);
            break;
        case 2:
            pq.deleteMax();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            if (pq.search(value))
                cout << "Value found.\n";
            else
                cout << "Value not found.\n";
            break;
        case 5:
            pq.sort();
            break;
        case 6:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
