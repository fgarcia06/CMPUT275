#include <vector>
#include <algorithm>

// Suppose the key type, K, is comparable with respect to '<'
template <class T, class K>
struct HeapItem {
  T item;
  K key;
};

template <class T, class K>
class BinaryHeap {
public:
  // Constructor is not provided because the only "initialization" required is
  // done by the constructor of the "heap" attribute which is called by default

  // Return the minimum-key item
  HeapItem<T, K> min() const;

  // Insert an item with the given key
  // if the item is already in the heap, 
  // it will still insert a new copy with this key
  void insert(const T& item, const K& key);

  // Pop the minimum-key item from the heap
  void popMin();

  // Return the number of items in the heap
  int size() const;

private:
  // Dynamic array holding heap items
  std::vector< HeapItem<T, K> > heap;

  // Fix the heap ordering property at index i and recurse with its parent
  void fixHeapUp(int i);

  // Fix the heap ordering property at index i and recurse with the child
  // that had a smaller key
  void fixHeapDown(int i);
};

// Assuming min is not called on empty heaps
template <class T, class K>
HeapItem<T, K> BinaryHeap<T, K>::min() const {
  return heap[0];
}

template <class T, class K>
void BinaryHeap<T, K>::insert(const T& item, const K& key) {
  HeapItem<T, K> node = {item, key};

  // Add the new item to the end of the heap
  heap.push_back(node);
  // Fix the heap ordering property now
  // heap.size() - 1 is the index of the last heap item
  fixHeapUp(heap.size() - 1);
}

template <class T, class K>
void BinaryHeap<T, K>::popMin() {
  // Move the last heap item (in the last layer) to the top
  // if the heap size is 1, this will just pop that item
  heap[0] = heap.back();
  heap.pop_back();

  // If there are items left in the heap, fix the heap property
  if (heap.size() > 0) {
    fixHeapDown(0);
  }
}

template <class T, class K>
int BinaryHeap<T, K>::size() const {
  return heap.size();
}

template <class T, class K>
void BinaryHeap<T, K>::fixHeapUp(int i) {
  while (i > 0) {
    int pi = (i-1)>>1; // get the parent index

    // If item i's key is smaller than its parent's key, swap them and go up
    if (heap[i].key < heap[pi].key) {
      std::swap(heap[i], heap[pi]);
      i = pi;
    }
    else {
      // No more fixing needs to be done
      return;
    }
  }
}

template <class T, class K>
void BinaryHeap<T, K>::fixHeapDown(int i) {
  while (true) {
    // Get indices of the two child nodes
    int lchild = (i<<1)+1, rchild = (i<<1)+2;

    // If no children, no problem
    if (lchild >= int(heap.size())) {
      return;
    }

    int min_child;
    // Identify the child with the minimum key, being careful
    // to handle the case where there is no right child
    if (rchild >= int(heap.size()) || heap[lchild].key <= heap[rchild].key) {
      min_child = lchild;
    }
    else {
      min_child = rchild;
    }

    // If the heap ordering property is violated for i, swap that heap item
    // with the heap item held by the minimum-key child and repeat with this child
    if (heap[min_child].key < heap[i].key) {
      std::swap(heap[i], heap[min_child]);
      i = min_child;
    }
    else {
      return;
    }
  }
}
