#include "Median.hpp"

#include <limits>

void Median::add(int value) {
	if (m_lowerHalf.empty()) {
		m_lowerHalf.push(value);
		return;
	}

	if (m_lowerHalf.size() == m_upperHalf.size()) {
		// Replace the smallest/top element in the upper half with the current value
		// and then push the previous top of the upper half into the lower half
		if (value > m_upperHalf.top()) {
			value = m_upperHalf.replaceTop(value);
		}

		// Push into the lower half so that its new size is equal to: 1 + size(upper half)
		m_lowerHalf.push(value);
	}
	// At this point we have: size(lower half) == 1 + size(upper half)
	else {
		// Replace the biggest/top element in the lower half with the current value
		// and then push the previous top of the lower half into the upper half
		if (value < m_lowerHalf.top()) {
			value = m_lowerHalf.replaceTop(value);
		}

		// Push into the upper half so that its new size is equal to: size(lower half)
		m_upperHalf.push(value);
	}
}

float Median::median() const {
	// Both halves are empty -> there is no median element
	if (m_lowerHalf.empty()) {
		return std::numeric_limits<float>::quiet_NaN();
	}

	// Odd number of elements
	if (m_lowerHalf.size() > m_upperHalf.size()) {
		return static_cast<float>(m_lowerHalf.top());
	}

	// Even number of elements
	return m_lowerHalf.top() / 2.f + m_upperHalf.top() / 2.f;
}
