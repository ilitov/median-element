#ifndef _MEDIAN_H_
#define _MEDIAN_H_

#include <functional>	// less/greater

#include "CustomHeap.hpp"

// Data structure that keeps a set of numbers and returns the median element of that set in constant time
class Median {
public:
	// Add a new element to the structure
	void add(int value);

	// Get the current median element. The returned value is equal to the arithmetic average
	// of the two median elements if there is an even number of elements
	float median() const;

private:
	template <typename T, typename Comp>
	using Heap_t = CustomHeap<T, Comp>;

	// We partition and keep the added numbers in two halves, each of which is organized as a heap.
	// We also maintain the number of elements of each of the heaps so that their sizes are always equal
	// or there is at most 1 element more in the bottom half.
	//
	// The median element is always the top element of the bottom half or the avarage value of the two
	// top elements in the two heaps in case both halves have the same size.

	Heap_t<int, std::less<int>> m_bottomHalf;	// The half with all elements smaller that the current median
	Heap_t<int, std::greater<int>> m_upperHalf;	// The half with all elements greater that the current median
};

#endif // !_MEDIAN_H_
