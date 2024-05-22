#include "../remove_second_smallest.hpp"
#include "../MyLinkedList.h"
#include <gtest/gtest.h>

// g++ tests/test_remove_second_smallest.cpp -lgtest -lgtest_main -pthread -o bin/test

TEST(RemoveSecondSmallestTest, CorrectLengthAfterRemove)
{
    MyLinkedList<int> l = {1, 3, 1, 2};
    remove_second_smallest(l);
    EXPECT_EQ(l.size(), 3);
    remove_second_smallest(l);
    EXPECT_EQ(l.size(), 2);
    remove_second_smallest(l);
    EXPECT_EQ(l.size(), 1);
    remove_second_smallest(l);
    EXPECT_EQ(l.size(), 1);
}

TEST(RemoveSecondSmallestTest, CorrectElementsAfterRemove)
{
    MyLinkedList<int> l = {1, 3, 1, 2};
    remove_second_smallest(l);
    auto it = l.begin();
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(it, l.end());

    remove_second_smallest(l);
    it = l.begin();
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(it, l.end());

    remove_second_smallest(l);
    it = l.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(it, l.end());

    remove_second_smallest(l);
    it = l.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(it, l.end());
}

TEST(RemoveSecondSmallestTest, EmptyList)
{
    MyLinkedList<int> l;
    remove_second_smallest(l);
    EXPECT_EQ(l.size(), 0);
    auto it = l.begin();
    EXPECT_EQ(it, l.end());
}

TEST(RemoveSecondSmallestTest, OneElement)
{
    MyLinkedList<int> l = {1};
    remove_second_smallest(l);
    EXPECT_EQ(l.size(), 1);
    auto it = l.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(it, l.end());
}

TEST(RemoveSecondSmallestTest, CreatesCorrectRangeOfNumbers)
{
    int n{15}, min{1}, max{10};
    MyLinkedList<int> l;
    l.fill_random_numbers(n, min, max);
    EXPECT_EQ(l.size(), n);
    for (auto elem : l)
    {
        EXPECT_GE(elem, min);
        EXPECT_LE(elem, max);
    }
}

TEST(RemoveSecondSmallestTest, ThrowsAtIncorrectRange)
{
    MyLinkedList<int> l;
    EXPECT_THROW(l.fill_random_numbers(10, 10, 1), std::invalid_argument);
}

TEST(RemoveSecondSmallestTest, DoesNotGenerateElementsIfNIsZero)
{
    MyLinkedList<int> l;
    l.fill_random_numbers(0, 1, 10);
    EXPECT_EQ(l.size(), 0);
}
