#include <gtest/gtest.h>
#include "SortingAlgorithm.hpp"
#include "test_sorting_algorithm.hpp"

TEST(SortingTest, BubbleSortCorrectness) {
    std::vector<int> arr = {5, 3, 8, 4, 2};
    bubbleSort(arr);
    EXPECT_TRUE(isSorted(arr));
}

TEST(SortingTest, HeapSortCorrectness) {
    std::vector<int> arr = {10, 1, 7, 3, 2};
    heapSort(arr);
    EXPECT_TRUE(isSorted(arr));
}

TEST(SortingTest, EmptyArray) {
    std::vector<int> arr;
    bubbleSort(arr);
    EXPECT_TRUE(isSorted(arr));
    heapSort(arr);
    EXPECT_TRUE(isSorted(arr));
}

TEST(SortingTest, AlreadySorted) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    bubbleSort(arr);
    EXPECT_TRUE(isSorted(arr));
    heapSort(arr);
    EXPECT_TRUE(isSorted(arr));
}
TEST(SortingTest, ReverseSorted) {
    std::vector<int> arr = {9, 7, 5, 3, 1};
    bubbleSort(arr);
    EXPECT_TRUE(isSorted(arr));
    heapSort(arr);
    EXPECT_TRUE(isSorted(arr));
}
TEST(SortingTest, WithDuplicates) {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    bubbleSort(arr);
    EXPECT_TRUE(isSorted(arr));
    heapSort(arr);
    EXPECT_TRUE(isSorted(arr));
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
