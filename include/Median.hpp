#ifndef _MEDIAN_H_
#define _MEDIAN_H_

#include <queue>		// priority_queue
#include <functional>	// less/greater

#include "CustomHeap.hpp"

class Median {
public:
	void add(int value);
	float median() const;

private:
	template <typename T, typename Comp>
	using Heap_t = CustomHeap<T, Comp>;
	//using Heap_t = std::priority_queue<T, std::vector<T>, Comp>;

	// We keep two halves, each of which is organized as a heap and maintain
	// their sizes equal or with a maximum difference of 1(size of bottom half is always >= upper half).
	//
	// The median element is always the top element of the bottom half or the avarage value of the two
	// top elements in case both halves have the same size.

	Heap_t<int, std::less<int>> m_bottomHalf;	// The half with all elements smaller that the current median
	Heap_t<int, std::greater<int>> m_upperHalf;	// The half with all elements greater that the current median
};

#endif // !_MEDIAN_H_
