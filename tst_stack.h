#ifndef TST_STACK_H
#define TST_STACK_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "stack.h"

using namespace testing;

using TestDataType = std::int32_t;

TEST(Stack, EmtpyConstructed)
{
    std::array<TestDataType, 0> array;
    stack::Stack<TestDataType, array.size()> stack(array);
    EXPECT_EQ(stack.empty(), false);
    EXPECT_EQ(stack.size(), 0);
}

TEST(Stack, PushBack)
{
    std::array<TestDataType, 1> array;
    stack::Stack<TestDataType, array.size()> stack(array);
    EXPECT_EQ(stack.push_back(4), true);
    EXPECT_EQ(stack.size(), 1);
    TestDataType value;
    EXPECT_EQ(stack.back(value), true);
    EXPECT_EQ(value, 4);
}

TEST(Stack, Pop)
{
    std::array<TestDataType, 1> array;
    stack::Stack<TestDataType, array.size()> stack(array);
    EXPECT_EQ(stack.push_back(4), true);
    TestDataType value;
    EXPECT_EQ(stack.back(value), true);
    EXPECT_EQ(value, 4);
    EXPECT_EQ(stack.pop(), true);
    EXPECT_EQ(stack.size(), 0);
}

TEST(Stack, PushBackFull)
{
    std::array<TestDataType, 1> array;
    stack::Stack<TestDataType, array.size()> stack(array);
    EXPECT_EQ(stack.push_back(5), true);
    EXPECT_EQ(stack.push_back(4), false);
}

TEST(Stack, PopEmpty)
{
    std::array<TestDataType, 1> array;
    stack::Stack<TestDataType, array.size()> stack(array);
    EXPECT_EQ(stack.pop(), false);
}

TEST(Stack, EmptyBack)
{
    std::array<TestDataType, 1> array;
    stack::Stack<TestDataType, array.size()> stack(array);
    TestDataType value;
    EXPECT_EQ(stack.back(value), false);
}

TEST(Stack, BasicScenario)
{
    std::array<TestDataType, 4> array;
    stack::Stack<TestDataType, array.size()> stack(array);
    TestDataType value;
    EXPECT_EQ(stack.push_back(1), true);
    EXPECT_EQ(stack.back(value), true);
    EXPECT_EQ(value, 1);

    EXPECT_EQ(stack.push_back(2), true);
    EXPECT_EQ(stack.back(value), true);
    EXPECT_EQ(value, 2);

    EXPECT_EQ(stack.push_back(3), true);
    EXPECT_EQ(stack.back(value), true);
    EXPECT_EQ(value, 3);

    EXPECT_EQ(stack.push_back(4), true);
    EXPECT_EQ(stack.back(value), true);
    EXPECT_EQ(value, 4);

    EXPECT_EQ(stack.pop(), true);
    EXPECT_EQ(stack.back(value), true);
    EXPECT_EQ(value, 3);

    EXPECT_EQ(stack.pop(), true);
    EXPECT_EQ(stack.back(value), true);
    EXPECT_EQ(value, 2);

    EXPECT_EQ(stack.pop(), true);
    EXPECT_EQ(stack.back(value), true);
    EXPECT_EQ(value, 1);
}

#endif // TST_STACK_H
