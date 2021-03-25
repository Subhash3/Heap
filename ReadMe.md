## Heap implementation in cpp

### API
```c++
    // Types
    #define MAX_HEAP_TYPE 1
    #define MIN_HEAP_TYPE -1

    // Heap Element    
    template <typename X>
    struct HeapElement
    {
        double val;
        X data;
    };
    /*
        val  =>  the prioritized element. Sorting takes place based on val.
        data =>  optional data that user wants to store at the same place as val.
    */


    /************ Constructors *************/
    Heap(int type = MAX_HEAP_TYPE, vector<HeapElement<T>> arr = {});
    /*
        Default heapType is max-heap, use type = MIN_HEAP_TYPE for min-heap.
        If arr is passed, then heap will be built based on the values of arr.
    */

    // Indices will be used as data if double array is passed
    Heap(int type = MAX_HEAP_TYPE, vector<double> arr = {})


    /*********** Methods *************/
    // Converts an array into heap
    void heapify();

    // Prints the heap, (Only val not data)
    void display();

    // Inserts a new element to the heap along with data
    bool insert(double element, T data);

    // Overloaded method of the above method. If no data is passed, its index will be used a data
    bool insert(double element);

    // Removes the top/prioritized element of the heap
    bool remove();

    // Returns the top/prioritized element of the heap. This doesn't affect the heap.
    HeapElement<T> peak();

    // Returns true if the heap is empty and false otherwise.
    bool isEmpty();

    // Returns the sorted arr of the heapElements.val. This doesn't affect the heap.
    vector<double> heapSort(bool reverse = false);

    // Utility functions.
    void heapifyUp(int index);
    void heapifyDown(int elementIndex);

```

#### To Do:
- [x] Max Heap
- [x] Add template instead of just integer.
- [x] Add comparator function to distinguish b/w max and min heaps.
- [x] Male val as double instead of int.
- [ ] In display method, accept a printerFunction to print the HeapElement<T>.
- [ ] Make val to accept int, float and double.

##### Feel free to contribute and open any issues.