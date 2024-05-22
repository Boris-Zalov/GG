#include <list>
#include "ComparableConcept.hpp"
#include "MyLinkedList.h"

template <Comparable T>
void remove_second_smallest(MyLinkedList<T> &l)
{
    auto it = l.begin();
    if (it == l.end())
        return;

    auto smallest = it;
    auto second_smallest = it;

    ++it;
    if (it == l.end())
        return;

    for (; it != l.end(); ++it)
    {
        if (*it <= *smallest)
        {
            second_smallest = smallest;
            smallest = it;
        }
        else if (*it <= *second_smallest)
            second_smallest = it;
    }

    try
    {
        l.erase(second_smallest);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

template <Comparable T>
void remove_second_smallest(std::list<T> &l)
{
    auto it = l.begin();
    if (it == l.end())
        return;

    auto smallest = it;
    auto second_smallest = it;

    ++it;
    if (it == l.end())
        return;

    for (; it != l.end(); ++it)
    {
        if (*it <= *smallest)
        {
            second_smallest = smallest;
            smallest = it;
        }
        else if (*it <= *second_smallest)
            second_smallest = it;
    }

    l.erase(second_smallest);
};