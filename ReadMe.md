## Heap implementation in cpp

### API
```c++
    template <typename X>
    struct HeapElement
    {
        int val;
        X data;
    };
    /*
        val is the prioritized element. Sorting takes place based on val.
        data is optional data that users want to store.
    */

    Heap(int type = -1, vector<HeapElement<T>> arr = {});
    /*
        Default heapType is max-heap, use type = -1 for min-heap.
        If arr is passed, then heap will be built based on the values of arr.
    */


    // Indices will be used as data if integer array is passed
    Heap(int type = MAX_HEAP_TYPE, vector<int> arr = {});

    // Methods
    pair<int, int> getChildrenIndices(int parentIndex);
    int getParentIndex(int childIndex);
    void display();
    bool insert(int element, T data);
    void swap(HeapElement<T> *a, HeapElement<T> *b);
    void heapifyUp(int index);
    bool remove();
    void heapifyDown(int elementIndex);
    int getPrioritizedChildIndex(int parentIndex);
    HeapElement<T> peak();
    void heapify();
    bool isEmpty();
    vector<int> heapSort(bool ascending = false);
```

#### To Do:
- [x] Max Heap
- [x] Add template instead of just integer.
- [x] Add comparator function to distinguish b/w max and min heaps.
- [x] Male val as double instead of int.
- [ ] Make val to accept int, float and double.

##### Feel free to contribute and open any issues.