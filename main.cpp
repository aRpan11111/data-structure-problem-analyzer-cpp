#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <chrono>

using namespace std;
using namespace chrono;

/* ---------------- SEARCHING ---------------- */
int linearSearch(vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == key) return i;
    return -1;
}

int binarySearchAlgo(vector<int>& arr, int key) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == key) return m;
        if (arr[m] < key) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

/* ---------------- SORTING ---------------- */
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

/* ---------------- LINKED LIST ---------------- */
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtEnd(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
}

/* ---------------- STACK ---------------- */
void stackOperations() {
    stack<int> st;
    for (int i = 0; i < 1000; i++)
        st.push(i);
    while (!st.empty())
        st.pop();
}

/* ---------------- QUEUE ---------------- */
void queueOperations() {
    queue<int> q;
    for (int i = 0; i < 1000; i++)
        q.push(i);
    while (!q.empty())
        q.pop();
}

/* ---------------- MAIN ---------------- */
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    // Linear Search
    auto start = high_resolution_clock::now();
    linearSearch(arr, key);
    auto end = high_resolution_clock::now();
    cout << "\nLinear Search Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds";

    // Binary Search
    sort(arr.begin(), arr.end());
    start = high_resolution_clock::now();
    binarySearchAlgo(arr, key);
    end = high_resolution_clock::now();
    cout << "\nBinary Search Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds";

    // Bubble Sort
    vector<int> arrCopy = arr;
    start = high_resolution_clock::now();
    bubbleSort(arrCopy);
    end = high_resolution_clock::now();
    cout << "\nBubble Sort Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds";

    // STL Sort
    start = high_resolution_clock::now();
    sort(arr.begin(), arr.end());
    end = high_resolution_clock::now();
    cout << "\nSTL Sort Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds";

    // Linked List
    Node* head = NULL;
    start = high_resolution_clock::now();
    for (int i = 0; i < 1000; i++)
        insertAtEnd(head, i);
    end = high_resolution_clock::now();
    cout << "\nLinked List Insertion Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds";

    // Stack
    start = high_resolution_clock::now();
    stackOperations();
    end = high_resolution_clock::now();
    cout << "\nStack Operations Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds";

    // Queue
    start = high_resolution_clock::now();
    queueOperations();
    end = high_resolution_clock::now();
    cout << "\nQueue Operations Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    cout << "\nAnalysis Complete.\n";
    return 0;
}
