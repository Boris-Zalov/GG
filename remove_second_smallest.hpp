#pragma once

#include <list>
#include "ComparableConcept.hpp"
#include "MyLinkedList.h"

template <Comparable T>
void remove_second_smallest(MyLinkedList<T> &l);

template <Comparable T>
void remove_second_smallest(std::list<T> &l);

#include "remove_second_smallest.cpp"