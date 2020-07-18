#ifndef STACK_H
#define STACK_H

#include <array>
#include <cstddef>

namespace stack
{

template <class T, std::size_t arraySize>
class Stack
{
public:
    Stack() = delete;
    explicit Stack(std::array<T, arraySize>& array) : m_array(array), m_size(0) {}
    ~Stack() = default;
    bool back(T& value) const
    {
        if (m_size)
        {
            value = m_array[m_size - 1];
            return true;
        }
        else
        {
            return false;
        }
    }
    bool push_back(const T& value) noexcept
    {
        if (m_size < arraySize)
        {
            m_array[m_size++] = value;
            return true;
        }
        else
        {
            return false;
        }
    }
    bool push_back(T&& value) noexcept
    {
        return push_back(const_cast<const T&>(value));
    }
    bool pop() noexcept
    {
        if (m_size)
        {
            --m_size;
            return true;
        }
        else
        {
            return false;
        }
    }
    std::size_t size() const
    {
        return m_size;
    }
    bool empty() const
    {
        return m_size;
    }
private:
    std::array<T, arraySize>& m_array;
    std::size_t m_size;
};

}
#endif // STACK_H
