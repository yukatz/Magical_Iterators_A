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
    // CHECK_NOTHROW(MagicalContainer::AscendingIterator ascIter(mContainer));
    MagicalContainer::AscendingIterator ascIter1(mContainer);
    CHECK_NOTHROW(ascIter1.begin());
    auto it = ascIter1.begin();
    CHECK_EQ(*it, 1);
    CHECK_NOTHROW(ascIter1.end());
    auto itEnd = ascIter1.end();
    CHECK_EQ(*itEnd, 3);
    MagicalContainer::AscendingIterator ascIter2(mContainer);

    MagicalContainer mContainer1;
    mContainer1.addElement(4);
    mContainer1.addElement(5);
    mContainer1.addElement(8);
    MagicalContainer::AscendingIterator ascIter3(mContainer1);

    SUBCASE("Assignment operator")
    {
    }
    SUBCASE("Equality comparison (operator==)")
    {
        CHECK_NOTHROW(ascIter1.operator==(ascIter2));
        CHECK(ascIter1 == ascIter2);    // Self compare
        CHECK(!(ascIter1 == ascIter3)); // Differet containers
    }
    SUBCASE("Inequality comparison (operator!=)")
    {
        CHECK_NOTHROW(ascIter1.operator!=(ascIter2));
        CHECK(!(ascIter1 != ascIter2)); // Self compare
        CHECK((ascIter1 != ascIter3));  // Differet containers
    }
    SUBCASE("GT operator")
    {

        CHECK_NOTHROW(ascIter1.operator<(ascIter2));
        CHECK(!(ascIter1 < ascIter2)); // Self compare
        CHECK((ascIter1 < ascIter2));  // Differet containers
    }
    SUBCASE("LT operator")
    {
        CHECK_NOTHROW(ascIter1.operator>(ascIter2));
        CHECK(!(ascIter1 > ascIter2)); // Self compare
        CHECK(!(ascIter1 > ascIter2)); // Differet containers
    }
    SUBCASE("Dereference operator (operator*)")
    {
    }
    SUBCASE("Pre-increment operator (operator++)")
    {
        CHECK_NOTHROW(++ascIter1);
        ++ascIter1;
        CHECK(*ascIter1 == 1);
        ++ascIter1;
        CHECK(*ascIter1 == 2);
        ++ascIter1;
        CHECK(*ascIter1 == 3);
        ++ascIter1;
        ++ascIter1;
        CHECK_THROWS_AS(*ascIter1, runtime_error); // after the end
    }
    SUBCASE("Begin")
    {
        CHECK_NOTHROW((ascIter1.begin()));
        CHECK_EQ(*ascIter1.begin(), 1);
    }
    SUBCASE("End")
    {
        CHECK_NOTHROW((ascIter1.end()));
        CHECK_EQ(*ascIter1.end(), 3);
    }
}
// TEST_CASE("SideCrossIterator")
// {
//     MagicalContainer mContainer;
//     mContainer.addElement(1);
//     mContainer.addElement(2);
//     mContainer.addElement(3);
//     MagicalContainer::SideCrossIterator crossIter1(mContainer);
//     CHECK_NOTHROW((crossIter1.begin()));
//     auto it = crossIter1.begin();
//     CHECK_EQ(*it, 1);
//     CHECK_NOTHROW((crossIter1.end()));
//     auto itEnd = crossIter1.end();
//     CHECK_EQ(*itEnd, 3);
//     MagicalContainer::SideCrossIterator crossIter2(mContainer);
//     MagicalContainer mContainer1;
//     mContainer1.addElement(4);
//     mContainer1.addElement(5);
//     mContainer1.addElement(8);
//     MagicalContainer::SideCrossIterator crossIter3(mContainer1);

//     SUBCASE("Assignment operator")
//     {
//     }
//     SUBCASE("Equality comparison (operator==)")
//     {
//         CHECK_NOTHROW(crossIter1.operator==(crossIter2));
//         CHECK(crossIter1 == crossIter2);    // Self compare
//         CHECK(!(crossIter1 == crossIter3)); // Differet containers
//     }
//     SUBCASE("Inequality comparison (operator!=)")
//     {
//         CHECK_NOTHROW(crossIter1.operator!=(crossIter2));
//         CHECK(!(crossIter1 != crossIter2)); // Self compare
//         CHECK(crossIter1 != crossIter3);    // Differet containers
//     }
//     SUBCASE("GT operator")
//     {
//         CHECK_NOTHROW(crossIter1.operator>(crossIter2));
//         CHECK(!(crossIter1 > crossIter2)); // Self compare
//         CHECK(crossIter1 > crossIter3);    // Differet containers
//     }
//     SUBCASE("LT operator")
//     {
//         CHECK_NOTHROW(crossIter1.operator<(crossIter2));
//         CHECK(!(crossIter1 < crossIter2)); // Self compare
//         CHECK(!(crossIter1 < crossIter3)); // Differet containers
//     }
//     SUBCASE("Dereference operator (operator*)")
//     {
//     }
//     SUBCASE("Pre-increment operator (operator++)")
//     {
//         CHECK_NOTHROW((++crossIter1));
//         ++crossIter1;
//         CHECK(*crossIter1 == 1);
//         ++crossIter1;
//         CHECK(*crossIter1 == 3);
//         ++crossIter1;
//         CHECK(*crossIter1 == 2);
//         ++crossIter1;
//         ++crossIter1;
//         CHECK_THROWS_AS(*crossIter1, runtime_error); // after the end
//     }
//     SUBCASE("Begin")
//     {
//         CHECK_NOTHROW((crossIter1.begin()));
//         CHECK_EQ(*crossIter1.begin(), 1);
//     }
//     SUBCASE("End")
//     {
//         CHECK_NOTHROW((crossIter1.end()));
//         CHECK_EQ(*crossIter1.end(), 2);
//     }
// }
TEST_CASE("PrimeIterator")
{
    MagicalContainer mContainer;
    mContainer.addElement(1);
    mContainer.addElement(2);
    mContainer.addElement(3);
    MagicalContainer::PrimeIterator primeIter1(mContainer);
    CHECK_NOTHROW(primeIter1.begin());
    auto itBegin = primeIter1.begin();
    CHECK_EQ(*itBegin, 1);
    CHECK_NOTHROW(primeIter1.end());
    auto itEnd = primeIter1.end();
    CHECK_EQ(*itEnd, 3);
    MagicalContainer::PrimeIterator primeIter2(mContainer);

    MagicalContainer mContainer1;
    mContainer1.addElement(4);
    mContainer1.addElement(5);
    mContainer1.addElement(8);
    MagicalContainer::PrimeIterator primeIter3(mContainer1);

    SUBCASE("Assignment operator")
    {
    }
    SUBCASE("Equality comparison (operator==)")
    {
        CHECK_NOTHROW(primeIter1.operator==(primeIter2));
        CHECK(primeIter1 == primeIter2);    // Self compare
        CHECK(!(primeIter1 == primeIter3)); // Differet containers
    }
    SUBCASE("Inequality comparison (operator!=)")
    {
        CHECK_NOTHROW(primeIter1.operator!=(primeIter2));
        CHECK(!(primeIter1 != primeIter2)); // Self compare
        CHECK(primeIter1 != primeIter3);    // Differet containers
    }
    SUBCASE("GT operator")
    {
        CHECK_NOTHROW(primeIter1.operator<(primeIter2));
        CHECK(!(primeIter1 < primeIter2)); // Self compare
        CHECK(primeIter1 < primeIter3);    // Differet containers
    }
    SUBCASE("LT operator")
    {
        CHECK_NOTHROW(primeIter1.operator>(primeIter2));
        CHECK(!(primeIter1 > primeIter2)); // Self compare
        CHECK(!(primeIter1 > primeIter3)); // Differet containers
    }
    SUBCASE("Dereference operator (operator*)")
    {
    }
    SUBCASE("Pre-increment operator (operator++)")
    {
        CHECK_NOTHROW((++primeIter1));
        ++primeIter1;
        CHECK(*primeIter1 == 1);
        ++primeIter1;
        CHECK(*primeIter1 == 3);
        ++primeIter1;
        CHECK(*primeIter1 == 2);
        ++primeIter1;
        ++primeIter1;
        CHECK_THROWS_AS(*primeIter1, runtime_error); // after the end
    }
    SUBCASE("Begin")
    {
        CHECK_NOTHROW((primeIter1.begin()));
        CHECK_EQ(*primeIter1.begin(), 1);
    }
    SUBCASE("End")
    {
        CHECK_NOTHROW((primeIter1.end()));
        CHECK_EQ(*primeIter1.end(), 3);
    }
}
