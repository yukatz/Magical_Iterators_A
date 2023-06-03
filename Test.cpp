#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;
// Test case for adding elements to the MagicalContainer
TEST_CASE("Container cinstructor")
{
    CHECK_NOTHROW(MagicalContainer mContainer);
}
TEST_CASE("Add elemnts to container")
{
    MagicalContainer mContainer;
    CHECK_NOTHROW(mContainer.addElement(1));
    mContainer.addElement(1);
    mContainer.addElement(2);
    mContainer.addElement(3);
    CHECK_EQ(mContainer.size(), 3);
}
TEST_CASE("Remove elemnts from the container")
{
    MagicalContainer mContainer;
    mContainer.addElement(1);
    mContainer.addElement(2);
    mContainer.addElement(3);
    CHECK_NOTHROW(mContainer.removeElement(1));
    mContainer.removeElement(1);
    CHECK_EQ(mContainer.size(), 2);
    mContainer.removeElement(2);
    mContainer.removeElement(3);
    CHECK_EQ(mContainer.size(), 0);
    CHECK_THROWS(mContainer.removeElement(2)); // tring to remove not existed element
}
TEST_CASE("Return the size")
{
    MagicalContainer mContainer;
    mContainer.addElement(1);
    mContainer.addElement(2);
    mContainer.addElement(3);
    CHECK_NOTHROW(mContainer.size());
    CHECK_EQ(mContainer.size(), 3);
}
TEST_CASE("AscendingIterator")
{
    MagicalContainer mContainer;
    mContainer.addElement(1);
    mContainer.addElement(2);
    mContainer.addElement(3);
    //CHECK_NOTHROW(MagicalContainer::AscendingIterator ascIter(mContainer));
    MagicalContainer::AscendingIterator ascIter(mContainer);
    CHECK_NOTHROW(ascIter.begin());
    auto it = ascIter.begin();
    CHECK_EQ(*it, 1);
    CHECK_NOTHROW(ascIter.end());
    auto itEnd = ascIter.end();
    CHECK_EQ(*itEnd, 3);
}
TEST_CASE("SideCrossIterator")
{
    MagicalContainer mContainer;
    mContainer.addElement(1);
    mContainer.addElement(2);
    mContainer.addElement(3);
    //CHECK_NOTHROW(MagicalContainer::SideCrossIterator crossIter(mContainer));
    MagicalContainer::AscendingIterator crossIter(mContainer);
    CHECK_NOTHROW(crossIter.begin());
    auto it = crossIter.begin();
    CHECK_EQ(*it, 1);
    CHECK_NOTHROW(crossIter.end());
    auto itEnd = crossIter.end();
    CHECK_EQ(*itEnd, 3);
}
TEST_CASE("PrimeIterator")
{
    MagicalContainer mContainer;
    mContainer.addElement(1);
    mContainer.addElement(2);
    mContainer.addElement(3);
   // CHECK_NOTHROW(MagicalContainer::PrimeIterator(mContainer));
    MagicalContainer::AscendingIterator primeIter(mContainer);
    CHECK_NOTHROW(primeIter.begin());
    auto itBegin = primeIter.begin();
    CHECK_EQ(*itBegin, 1);
    CHECK_NOTHROW(primeIter.end());
    auto itEnd = primeIter.end();
    CHECK_EQ(*itEnd, 3);
}
