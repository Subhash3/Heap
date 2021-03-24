#include "heap.cpp"

void printVector(vector<int> arr);

int main()
{
    int choice, index, parentIndex, num;
    pair<int, int> children;
    vector<int> sorted;
    // Heap<int> *heap = new Heap<int>(-1, {{1, 0}, {2, 1}, {3, 2}, {5, 4}, {6, 5}, {7, 6}, {8, 7}, {9, 8}, {10, 9}});
    Heap<int> *heap = new Heap<int>(-1, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    // Heap<int> *heap = new Heap<int>();
    HeapElement<int> heapElement;

    while (true)
    {
        printf("1. Insert an element.\n");
        printf("2. Display\n");
        printf("3. Delete max/min.\n");
        printf("4. Peak\n");
        printf("5. Heap sort\n");
        printf("6. Exit\n");
        printf("[Heap size: (%d)]> Select one: ", heap->size);
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter an element: ");
            scanf("%d", &num);
            heap->insert(num, 1);
            break;
        case 2:
            heap->display();
            break;
        case 3:
            heap->remove();
            break;
        case 4:
            heapElement = heap->peak();
            printf("Max/min element: %d, data: %d\n", heapElement.val, heapElement.data);
            break;
        case 5:
            sorted = heap->heapSort();
            printVector(sorted);
            sorted = heap->heapSort(true);
            printVector(sorted);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
        printf("\n");
    }
}

void printVector(vector<int> arr)
{
    int i, size;
    bool enteredLoop = false;

    size = arr.size();
    printf("[");
    fflush(NULL);
    for (i = 0; i < size; i++)
    {
        enteredLoop = true;
        printf("%d  ", arr[i]);
        fflush(NULL);
    }
    printf(enteredLoop ? "\b\b]\n" : "]\n");

    return;
}