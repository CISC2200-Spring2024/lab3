#ifndef __ALIST_H__
#define __ALIST_H__

#define RFACTOR 2 // use factor 2

namespace ds {

template <typename ItemType>
class TestDriver; // for autograding only; please ignore

/** Array-based list. */
template <typename ItemType> class AList {
  friend class TestDriver<ItemType>; // for autograding only; please ignore

private:
  /** The underlying array. */
  ItemType *items;

  /** Stores the current size of the list. */
  int count;

  /** Max number of items allowed. */
  int maxCnt;

  /** Resize the underlying array to the target capacity. */
  void resize(int capacity) {
    maxCnt = capacity;
    ItemType *a = new ItemType[maxCnt];
    for (int i = 0; i < count; i++) {
      a[i] = items[i];
    }
    delete[] items;
    items = a;
  }

public:
  /**
   * Construct a new AList object.
   *
   * @param initSize initial size of the underlying array; default 100
   */
  explicit AList(int initSize = 100) {
    count = 0;
    maxCnt = initSize;
    items = new ItemType[maxCnt];
  }

  /** Destroy the AList object. */
  ~AList() { delete[] items; }

  /** Return the number of elements in list. */
  int size() const { return count; }

  /** Return the i-th item in list .*/
  ItemType &get(int i) const { return items[i]; }

  /** Append `x` to the end of list. */
  void addLast(ItemType x) {
    if (count == maxCnt) {
      resize(count * RFACTOR);
    }
    items[count] = x;
    count += 1;
  }

  /** Return the last item in list. */
  ItemType &getLast() const { return items[count - 1]; }

  /** Delete and return the last item. */
  ItemType removeLast() {
    ItemType returnItem = getLast();
    count -= 1;
    return returnItem;
  }

  AList(const AList<ItemType> &other);
  void addFirst(ItemType x);
  ItemType &getFirst() const;
  ItemType removeFirst();

  AList<ItemType> &operator=(const AList<ItemType> &rhs);  
}; 
/** Copy constructor. */
template <typename ItemType>
AList<ItemType>::AList(const AList<ItemType> &other) {
  // TODO: create a list that is identical to `other`
}

/** Insert x at the front of list. */
template <typename ItemType> void AList<ItemType>::addFirst(ItemType x) {
  // TODO:
}

/** Return the first element in list. */
template <typename ItemType> ItemType &AList<ItemType>::getFirst() const {
  // TODO:
}

/**
 * Remove and return the first element in list.
 * For example, list [1,2,3] becomes [2,3] and 1 is returned.
 *
 * @return ItemType the first item in the original list before removing
 */
template <typename ItemType> ItemType AList<ItemType>::removeFirst() {
  // TODO:
}

/**
 * Assign one Alist (rhs) to current Alist
 @return the current Alist
*/
template <typename ItemType>
AList<ItemType> &operator=(const AList<ItemType> &rhs)
{
   //TODO by you 
}
} // namespace ds

#endif // __ALIST_H__
