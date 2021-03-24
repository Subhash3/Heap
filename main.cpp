#include "heap.cpp"

void printVector(vector<int> arr);

int main()
{
    int choice, index, parentIndex, num;
    pair<int, int> children;
    vector<int> sorted;
    Heap *heap = new Heap(1, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    // Heap *heap = new Heap();

    while (true)
    {
        printf("1. Get children of.\n");
        printf("2. Get Parent of.\n");
        printf("3. Insert an element.\n");
        printf("4. Display\n");
        printf("5. Delete max/min.\n");
        printf("6. Peak\n");
        printf("7. Heap sort\n");
        printf("8. Exit\n");
        printf("[Heap size: (%d)]> Select one: ", heap->size);
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter parent index: ");
            scanf("%d", &index);
            children = heap->getChildrenIndices(index);
            printf("leftIndex: %d, right index: %d\n", children.first, children.second);
            break;
        case 2:
            printf("Enter child index: ");
            scanf("%d", &index);
            parentIndex = heap->getParentIndex(index);
            printf("parentIndex: %d\n", parentIndex);
            break;
        case 3:
            printf("Enter an element: ");
            scanf("%d", &num);
            heap->insert(num);
            break;
        case 4:
            heap->display();
            break;
        case 5:
            heap->remove();
            break;
        case 6:
            num = heap->peak();
            printf("Max/min element: %d\n", num);
            break;
        case 7:
            sorted = heap->heapSort();
            printVector(sorted);
            sorted = heap->heapSort(true);
            printVector(sorted);
            break;
        case 8:
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