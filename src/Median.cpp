#include "Median.hpp"

#include <limits>

void Median::add(int value) {
	if (m_bottomHalf.empty()) {
		m_bottomHalf.push(value);
		return;
	}

	if (m_bottomHalf.size() == m_upperHalf.size()) {
		// Replace the smallest element in the upper half with the current value and then push the previous top
		// of the upper half into the bottom half
		if (value > m_upperHalf.top()) {
			value = m_upperHalf.replaceTop(value);
		}

		// Bottom half now has 1 element more than the upper half
		m_bottomHalf.push(value);
	}
	// At this point we have: size(bottom half) == size(upper half) + 1
	else {
		// Replace the biggest element in the bottom half with the current value and then push the previous top
		// of the bottom half into the upper half
		if (value < m_bottomHalf.top()) {
			value = m_bottomHalf.replaceTop(value);
		}

		// The number of elements in the two halves is now equal
		m_upperHalf.push(value);
	}
}

float Median::median() const {
	// Both halves are empty -> there is no median element
	if (m_bottomHalf.empty()) {
		return std::numeric_limits<float>::quiet_NaN();
	}

	if (m_bottomHalf.size() > m_upperHalf.size()) {
		return static_cast<float>(m_bottomHalf.top());
	}

	return m_bottomHalf.top() / 2.f + m_upperHalf.top() / 2.f;
}
