#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size = 0;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int data)
    {

        size = size + 1;
        int index = size;

        arr[index] = data;

        while (index > 1)
        {

            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);

                index = parent;
            }

            else
                return;
        }
    }

    void deletion()
    {
        // step 1
        if (size == 0)
        {
            cout << " No need to delete the node" << endl;
            return;
        }

        // step 2

        arr[1] = arr[size];
        size--;

        // step 3;

        int i = 1;

        while (i < size)
        {

            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);

                i = leftIndex;
            }

            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }

            else
                return;
        }
    }

    void print()
    {

        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{

    int largest = i;

    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[largest] < arr[left])
    {

        largest = left;
    }

    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {

        swap(arr[largest], arr[i]);

        // recursion call

        heapify(arr, n, largest);
    }
}

int main()
{

    int arr[6] = {-1, 54, 53, 55, 52, 50};

    int n = 5;

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletion();

    h.print();

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Printing the head now " << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // priority_queue<int>pq;
    // pq.push(23);
    // pq.push(34);
    // pq.push(3);

    // cout<<" this si STL " << pq.top()<<endl;
    // pq.pop();

    // cout<<" this si STL " << pq.top()<<endl;
    // cout<<" size "<<pq.size()<<endl;

    // min heap or max heap used through STL
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(23);
    minHeap.push(34);
    minHeap.push(3);
    minHeap.push(54);

    cout << " this si STL " << minHeap.top() << endl;
    minHeap.pop();

    cout << " this si STL " << minHeap.top() << endl;
    cout << " size " << minHeap.size() << endl;
}