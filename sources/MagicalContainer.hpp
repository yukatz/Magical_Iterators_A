#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <iostream>
#include <vector>
#include <cmath>

namespace ariel
{
    using namespace std;
    // User-defined container classthat can store integers representing mystical elements
    class MagicalContainer
    {

        // Each iterator should support some basic operation.
        class Iterator
        {
        public:
            int *currElement;
            Iterator();                               // Default constructor
            Iterator(const Iterator &other) = delete; // Copy constructor
            virtual ~Iterator() = default;            // Destructor
                                                      // Assignment operator????
            Iterator &operator=(const Iterator &other) = delete;// Equality comparison (operator==)
            // Inequality comparison (operator!=)
            virtual int &operator*() = 0;                   // Dereference operator (operator*)
            virtual Iterator &operator++() = 0;             // Pre-increment operator (operator++)
            virtual std::vector<int>::iterator begin() = 0; // Returns the appropriate iterator pointing to the first element of the container based on the specified type.
            virtual std::vector<int>::iterator end() = 0;   // Returns the appropriate iterator pointing one position past the last element of the container based on the specified type.
            Iterator(Iterator &&other) noexcept = delete;            //???
            Iterator &operator=(Iterator &&other) noexcept = delete; //???
        };

    public:
        // Iterator classes -  scending order.
        class AscendingIterator : public Iterator
        {
        private:
            MagicalContainer *container;
            vector<int> sortedElements;
            int *currElement;
        public:
            AscendingIterator();
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator() override;
            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            int &operator*() override;
            AscendingIterator &operator++() override;
            std::vector<int>::iterator begin() override;
            std::vector<int>::iterator end() override;
            AscendingIterator(AscendingIterator &&other) noexcept;
            AscendingIterator &operator=(AscendingIterator &&other) noexcept;
        };

        // Iterator classes that allows traversal of elements in cross order.
        class SideCrossIterator : public Iterator
        {
        private:
            vector<int> sortedElements;
            MagicalContainer *container;
            int *currElement;

        public:
            SideCrossIterator();
            SideCrossIterator(MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator &other);
            ~SideCrossIterator() override;

            SideCrossIterator &operator=(const SideCrossIterator &other);
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            int &operator*() override;
            SideCrossIterator &operator++() override;

            std::vector<int>::iterator begin() override;
            std::vector<int>::iterator end() override;
            SideCrossIterator(SideCrossIterator &&other) noexcept;
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept;
        };

        // Iterator classes that allows traversal of elements in prime numbers only.
        class PrimeIterator : public Iterator
        {
        private:
            vector<int> primeElements;
            MagicalContainer *container;
            int *currElement;

            static bool isPrime(int num)
            {
                double sqrtNum = sqrt(num);
                for (int i = 2; i <= sqrtNum; i++)
                {
                    if (num % i == 0)
                    {
                        return false;
                    }
                }
                return true;
            }

        public:
            PrimeIterator();
            PrimeIterator(MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator() override;

            PrimeIterator &operator=(const PrimeIterator &other);
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            int &operator*() override;
            PrimeIterator &operator++() override;

            std::vector<int>::iterator begin() override;
            std::vector<int>::iterator end() override;

            PrimeIterator(PrimeIterator &&other) noexcept;
            PrimeIterator &operator=(PrimeIterator &&other) noexcept;
        };

        vector<int> elements;
        AscendingIterator ascendingIterator;
        SideCrossIterator sideCrossIterator;
        PrimeIterator primeIterator;

        MagicalContainer();
        ~MagicalContainer();
        bool addElement(int element);//adding elements
        bool removeElement(int element);// removing elements
        std::vector<int> getElements() const;
        int size() const;//retrieving the size of the container

        AscendingIterator &getAscendingIterator();
        SideCrossIterator &getSideCrossIterator();
        PrimeIterator &getPrimeIterator();

        MagicalContainer(const MagicalContainer &other) = delete;
        MagicalContainer &operator=(const MagicalContainer &other) = delete;
        MagicalContainer(MagicalContainer &&other) noexcept = delete;
        MagicalContainer &operator=(MagicalContainer &&other) noexcept = delete;
    };
}
#endif