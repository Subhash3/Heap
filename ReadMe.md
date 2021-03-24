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
- [ ] Add comparator function to distinguish b/w max and min heaps

##### Feel free to contribute and open any issues.