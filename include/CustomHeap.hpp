#ifndef _CUSTOM_HEAP_H_
#define _CUSTOM_HEAP_H_

#include <vector>
#include <algorithm>

// Heap data structure that supports push() and replaceTop(), but does not support pop()
template <typename T, typename Comp>
class CustomHeap {
public:
	std::size_t size() const {
		return m_data.size();
	}

	bool empty() const {
		return m_data.empty();
	}

	// Returns the top element of the heap
	// It is undefined behaviour to call this method if the heap is empty
	const T& top() const {
		return m_data.front();
	}

	// Adds new element to the heap
	void push(const T &value) {
		m_data.push_back(value);
		std::push_heap(m_data.begin(), m_data.end(), m_comp);
	}

	// Replaces the top element of the heap with the provided value and returns the old top element
	// It is undefined behaviour to call this method if the heap is empty
	T replaceTop(const T &value) {
		const T oldTop = m_data.front();
		m_data.front() = value;
		heapifyDown();
		return oldTop;
	}

private:
	void heapifyDown() {
		const std::size_t size = m_data.size();

		std::size_t idx = 0;
		std::size_t lChild = leftChild(idx);

		while (lChild < size) {
			const std::size_t rChild = lChild + 1;
			std::size_t next = lChild;

			// Continue with the right child if it comes before the left child according to the comparator
			if (rChild < size && !m_comp(m_data[rChild], m_data[lChild])) {
				next = rChild;
			}

			// Exit the loop if the selected child comes after the current root according to the comparator
			if (m_comp(m_data[next], m_data[idx])) {
				return;
			}

			std::swap(m_data[idx], m_data[next]);
			idx = next;
			lChild = leftChild(next);
		}
	}

	static std::size_t leftChild(std::size_t idx) {
		return idx * 2 + 1;
	}

private:
	std::vector<T> m_data;
	Comp m_comp;
};

#endif // !_CUSTOM_HEAP_H_
