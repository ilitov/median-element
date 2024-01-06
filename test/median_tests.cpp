#include <gtest/gtest.h>

#include "Median.hpp"

#include <cmath>
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>

TEST(MedianTest, CheckCompile) {
	Median m;
}

TEST(MedianTest, Empty) {
	Median med;

	ASSERT_NO_THROW(med.median());
	ASSERT_TRUE(std::isnan(med.median()));
}

TEST(MedianTest, SingleElement) {
	Median med;

	med.add(42);

	ASSERT_EQ(med.median(), 42.f);
}

TEST(MedianTest, TwoElements) {
	Median med;

	med.add(3);
	med.add(7);

	ASSERT_EQ(med.median(), 5.f);
}

TEST(MedianTest, AddInAscendingOrder) {
	Median med;

	for (int i = 1; i <= 1'000'000; ++i) {
		med.add(i);
		const float m = med.median();

		const int mid = i / 2;

		if (i % 2 == 0) {
			const float trueMid = (mid + mid + 1) / 2.f;
			ASSERT_EQ(m, trueMid);
		}
		else {
			const float trueMid = mid + 1.f;
			ASSERT_EQ(m, trueMid);
		}
	}
}

TEST(MedianTest, AddInDescendingOrder) {
	Median med;

	const int MAX_VAL = 1'000'001;

	for (int i = MAX_VAL; i >= 1; --i) {
		med.add(i);
		const float m = med.median();

		const int mid = i + (MAX_VAL - i) / 2;

		if (i % 2 == 0) {
			const float trueMid = (mid + mid + 1) / 2.f;
			ASSERT_EQ(m, trueMid);
		}
		else {
			const float trueMid = mid;
			ASSERT_EQ(m, trueMid);
		}
	}
}

TEST(MedianTest, AddMultipleElementsWithSameMedian) {
	const int MEDIAN = 1'000'000;

	Median med;
	med.add(MEDIAN);

	ASSERT_EQ(med.median(), static_cast<float>(MEDIAN));

	for (int i = 1; i <= MEDIAN; ++i) {
		med.add(MEDIAN - i);
		med.add(MEDIAN + i);

		ASSERT_EQ(med.median(), static_cast<float>(MEDIAN));
	}
}

TEST(MedianTest, AddRandomElements) {
	std::random_device rd;
	std::mt19937 gen{ rd() };
	std::uniform_int_distribution<> distrib{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };

	const std::size_t sizes[] = { 10, 42, 79, 50'000, 256'000, 599'999, 5'000'000 };

	for (auto size : sizes) {
		std::cout << "Find median of " << size << " elements\n";

		Median med;

		std::vector<int> elements;
		elements.resize(size);

		// Generate random values
		std::for_each(elements.begin(), elements.end(), [&gen, &distrib](int &val) { val = distrib(gen); });

		// Add them to the container
		std::for_each(elements.begin(), elements.end(), [&med](int val) { med.add(val); });

		// Sort them and find the true median element
		std::sort(elements.begin(), elements.end());

		const float trueMed = [&elements] {
			const std::size_t size = elements.size();
			const std::size_t midIdx = size / 2;

			if (size % 2 == 0) {
				return elements[midIdx] / 2.f + elements[midIdx - 1] / 2.f;
			}

			return static_cast<float>(elements[midIdx]);
		}();

		EXPECT_EQ(med.median(), trueMed);
	}
}
