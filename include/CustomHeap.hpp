#ifndef _CUSTOM_HEAP_H_
#define _CUSTOM_HEAP_H_

#include <vector>
#include <algorithm>

template <typename T, typename Comp>
class CustomHeap {
public:
	std::size_t size() const {
		return m_data.size();
	}

	bool empty() const {
		return m_data.empty();
	}

	const T& top() const {
		return m_data.front();
	}

	void push(const T &value) {
		m_data.push_back(value);
		std::push_heap(m_data.begin(), m_data.end(), m_comp);
	}

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
			std::size_t next = lChild;
			std::size_t rChild = lChild + 1;
			
			if (rChild < size && !m_comp(m_data[rChild], m_data[lChild])) {
				next = rChild;
			}

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
