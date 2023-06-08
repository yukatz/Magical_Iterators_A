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

TEST_CASE("PrimeIterator")
{
    MagicalContainer mContainer;
    mContainer.addElement(1);
    mContainer.addElement(2);
    mContainer.addElement(3);
    MagicalContainer::PrimeIterator primeitr1(mContainer);
    CHECK_NOTHROW(primeitr1.begin());
    auto it = primeitr1.begin();
    CHECK_EQ(*it, 1);
    CHECK_NOTHROW(primeitr1.end());
    auto itEnd = primeitr1.end();
    CHECK_EQ(*itEnd, 3);
    MagicalContainer::PrimeIterator primeitr2(mContainer);
    MagicalContainer mContainer1;
    mContainer1.addElement(4);
    mContainer1.addElement(5);
    mContainer1.addElement(8);
    MagicalContainer::PrimeIterator primeitr3(mContainer1);

    SUBCASE("Prime Assignment operator")
    {
    }
    SUBCASE("Prime Equality comparison (operator==)")
    {
        CHECK_NOTHROW(primeitr1.operator==(primeitr2));
        CHECK(primeitr1 == primeitr2);    // Self compare
        CHECK(!(primeitr1 == primeitr3)); // Differet containers
    }
    SUBCASE("Prime Inequality comparison (operator!=)")
    {
        CHECK_NOTHROW(primeitr1.operator!=(primeitr2));
        CHECK(!(primeitr1 != primeitr2)); // Self compare
        CHECK((primeitr1 != primeitr3));  // Differet containers
    }
    SUBCASE("Prime GT operator")
    {

        CHECK_NOTHROW(primeitr1.operator<(primeitr2));
        CHECK(!(primeitr1 < primeitr2)); // Self compare
        CHECK((primeitr1 < primeitr2));  // Differet containers
    }
    SUBCASE("Prime LT operator")
    {
        CHECK_NOTHROW(primeitr1.operator>(primeitr2));
        CHECK(!(primeitr1 > primeitr2)); // Self compare
        CHECK(!(primeitr1 > primeitr2)); // Differet containers
    }
    SUBCASE("Prime Dereference operator (operator*)")
    {
    }
    SUBCASE("Prime Pre-increment operator (operator++)")
    {
        CHECK_NOTHROW(++primeitr1);
        ++primeitr1;
        CHECK(*primeitr1 == 1);
        ++primeitr1;
        CHECK(*primeitr1 == 2);
        ++primeitr1;
        CHECK(*primeitr1 == 3);
        ++primeitr1;
        ++primeitr1;
        CHECK_THROWS_AS(*primeitr1, runtime_error); // after the end
    }
    SUBCASE("Prime Begin")
    {
        CHECK_NOTHROW((primeitr1.begin()));
        CHECK_EQ(*primeitr1.begin(), 1);
    }
    SUBCASE("Prime End")
    {
        CHECK_NOTHROW((primeitr1.end()));
        CHECK_EQ(*primeitr1.end(), 3);
   }
}

