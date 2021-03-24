#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define MAX_HEAP_TYPE 1
#define MIN_HEAP_TYPE 0
#define LEFT_CHILD 1
#define RIGHT_CHILD -1
#define EQUAL 0

template <typename X>
struct HeapElement
{
    int val;
    X other;
};

template <class T>
class Heap
{
private:
    vector<int> items;

public:
    int type;
    int size;

    Heap(int type = MAX_HEAP_TYPE, vector<HeapElement<T>> arr = {})
    {
        this->type = type;
        this->items = arr;
        this->size = arr.size();

        this->heapify();
    }

public:
    pair<int, int> getChildrenIndices(int parentIndex);
    int getParentIndex(int childIndex);
    void display();
    bool insert(int element);
    void swap(int *a, int *b);
    void heapifyUp(int index);
    bool remove();
    void heapifyDown(int elementIndex);
    int getMaxChildIndex(int parentIndex);
    int peak();
    void heapify();
    bool isEmpty();
    vector<int> heapSort(bool ascending = false);
};

template <class T>
bool Heap<T>::isEmpty()
{
    return this->size <= 0;
}

template <class T>
pair<int, int> Heap<T>::getChildrenIndices(int parentIndex)
{
    int left, right;

    left = 2 * parentIndex + 1;
    right = 2 * parentIndex + 2;

    left = (left >= size) ? -1 : left;
    right = (right >= size) ? -1 : right;

    return {left, right};
}

template <class T>
int Heap<T>::getParentIndex(int childIndex)
{
    return ceil((double)childIndex / (double)2) - 1;
}

template <class T>
int Heap<T>::getMaxChildIndex(int parentIndex)
{
    pair<int, int> children;

    children = this->getChildrenIndices(parentIndex);
    if (children.first == -1 && children.second != -1)
    {
        return children.second;
    }

    if (children.second == -1 && children.first != -1)
    {
        return children.first;
    }

    // Leaf Node
    if (children.second == -1 && children.first == -1)
    {
        return -1;
    }

    return (this->items[children.first] >= this->items[children.second]) ? children.first : children.second;
}

template <class T>
void Heap<T>::display()
{
    int i;
    bool enteredLoop = false;

    printf("[");
    fflush(NULL);
    for (i = 0; i < this->size; i++)
    {
        enteredLoop = true;
        printf("%d  ", this->items[i]);
        fflush(NULL);
    }
    printf(enteredLoop ? "\b\b]\n" : "]\n");

    return;
}

template <class T>
void Heap<T>::heapifyUp(int elementIndex)
{
    int parentIndex, element;

    element = this->items[elementIndex];
    while (true)
    {
        parentIndex = this->getParentIndex(elementIndex);
        // printf("parent: %d, element: %d\n", parentIndex, elementIndex);
        if ((elementIndex <= 0) || (this->items[parentIndex] >= element))
        {
            // printf("Reached root or parent > child\n");
            break;
        }
        this->swap(&this->items[parentIndex], &this->items[elementIndex]);
        elementIndex = parentIndex;
    }

    return;
}

template <class T>
void Heap<T>::heapifyDown(int elementIndex)
{
    int maxChildIndex;

    while (true)
    {
        maxChildIndex = this->getMaxChildIndex(elementIndex);
        if (maxChildIndex == -1)
        {
            break;
        }
        if (this->items[maxChildIndex] <= this->items[elementIndex])
        {
            break;
        }
        swap(&this->items[maxChildIndex], &this->items[elementIndex]);
        elementIndex = maxChildIndex;
    }

    return;
}

template <class T>
void Heap<T>::heapify()
{
    int i, lastInternalNodeIndex;

    lastInternalNodeIndex = ceil((double)this->size / (double)2) - 1;
    // this->display();
    for (i = lastInternalNodeIndex; i >= 0; i--)
    {
        // printf("i: %d, element: %d\n", i, this->items[i]);
        this->heapifyDown(i);
        // this->display();
    }

    return;
}

template <class T>
bool Heap<T>::insert(int element)
{
    int elementIndex;

    this->items.push_back(element);
    this->size += 1;

    elementIndex = this->size - 1;
    this->heapifyUp(elementIndex);

    return true;
}

template <class T>
bool Heap<T>::remove()
{
    if (this->isEmpty())
    {
        return false;
    }
    this->items[0] = this->items[this->size - 1];

    this->heapifyDown(0);
    this->items.pop_back();
    this->size -= 1;

    return true;
}

template <class T>
vector<int> Heap<T>::heapSort(bool ascending)
{
    vector<int> sorted, heapCopy;
    int maxElement, sizeCopy;

    // backup items
    heapCopy = vector<int>(this->items);
    sizeCopy = this->size;

    while (!this->isEmpty())
    {
        maxElement = this->peak();
        if (ascending)
        {
            sorted.insert(sorted.begin(), maxElement);
        }
        else
        {
            sorted.push_back(maxElement);
        }
        this->remove();
    }

    // restore items
    this->items = heapCopy;
    this->size = sizeCopy;

    return sorted;
}

template <class T>
int Heap<T>::peak()
{
    if (this->isEmpty())
    {
        return -1;
    }
    return this->items[0];
}

template <class T>
void Heap<T>::swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    return;
}