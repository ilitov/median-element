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

	// We partition and keep the added numbers in two separate halves, each of which is organized as a heap.
	//
	// We also maintain the number of elements in each of the heaps so that:
	// (1) their sizes are always equal
	// OR
	// (2) the lower half has 1 more element than the upper half
	//
	// The median element is always:
	// (1) the top element of the lower half
	// OR
	// (2) the average value of the two top elements if the two heaps have the same size

	Heap_t<int, std::less<int>> m_lowerHalf;	// The half with all elements <= the current median(max heap)
	Heap_t<int, std::greater<int>> m_upperHalf;	// The half with all elements >= the current median(min heap)
};

#endif // !_MEDIAN_H_
