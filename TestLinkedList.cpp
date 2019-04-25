/**
 *  @file TestLinkedList.cpp
 *  @author
 *  @date
 *  @brief Tests for LinkedListOfInts
 */

#include <iostream>
#include <vector>

class TestLinkedList
{
  public:

    /** 
     * Test isEmpty()
     */
    void testIsEmpty()
    {
      
      LinkedListOfInts test;
      bool empty = test.isEmpty();
      std::cout << "\t isEmpty should be true: ";
      if (empty) 
      {
        std::cout << "Passed\n";
      } else {
        std::cout << "Failed\n";
      }
      test.addFront(5);
      bool full = test.isEmpty();
      std::cout << "\t isEmpty should be false: ";
      if (full) 
      {
        std::cout << "Failed\n";
      } else {
        std::cout << "Passed\n";
      }
      printVector(test.toVector());
    }

    /**
     * Test size()
     */
    void testSize()
    {
      LinkedListOfInts test;
      int testSize;
      for (int i = 0; i < 10; i++)
      {
        std::cout << "\t Size should be "<< i << ": ";
        testSize = test.size();
        if (testSize == i) 
        {
          std::cout << "Passed\n";
        } else {
          std::cout << "Failed\n";
        }
        test.addFront(i);
      }
      printVector(test.toVector());
    }

    /**
     * Test search()
     */
    void testSearch()
    {
      LinkedListOfInts test;
      for (int i = 0; i < 10; i++)
      {
        test.addFront(i);
      }
      bool found;
      for (int i = 0; i < 10; i++)
      {
        found = test.search(i);
        std::cout << "\t Searching for "<< i << ": ";
        if (found) 
        {
          std::cout << "Passed\n";
        } else {
          std::cout << "Failed\n";
        }
      }
      //search for neg number
      found = test.search(-1);
      std::cout << "\t Searching for -1: ";
      if (found) 
      {
        std::cout << "Failed\n";
      } else {
        std::cout << "Passed\n";
      }
      //search for num not in vector
      found = test.search(15);
      std::cout << "\t Searching for 15: ";
      if (found) 
      {
        std::cout << "Failed\n";
      } else {
        std::cout << "Passed\n";
      }
      printVector(test.toVector());
    }

    /**
     * Test addBack()
     */
    void testAddBack()
    {
      LinkedListOfInts test;
      std::vector<int> compare;
      for (int i = 0; i < 10; i++)
      {
        test.addBack(i);
        compare.push_back(i);
      }
      std::cout << "   Should be: ";
      printVector(compare);
      std::cout << "Actual value: ";
      printVector(test.toVector());
      std::cout << "\t Comparing values: ";
      if (test.toVector() == compare) 
      {
        std::cout << "Passed\n";
      } else {
        std::cout << "Failed\n";
      }
    }

    /**
     * Test addFront()
     */
    void testAddFront()
    {
      LinkedListOfInts test;
      std::vector<int> compare;
      for (int i = 0; i < 10; i++)
      {
        test.addFront(i);
        compare.emplace(compare.begin(), i);
      }
      std::cout << "   Should be: ";
      printVector(compare);
      std::cout << "Actual value: ";
      printVector(test.toVector());
      std::cout << "\t Comparing values: ";
      if (test.toVector() == compare) 
      {
        std::cout << "Passed\n";
      } else {
        std::cout << "Failed\n";
      }
    }

    /**
     * Test removeBack()
     */
    void testRemoveBack()
    {
      LinkedListOfInts test;
      std::vector<int> compare;
      for (int i = 0; i < 10; i++)
      {
        test.addFront(i);
        compare.emplace(compare.begin(), i);
      }
      for (int i = 0; i < 10; i++)
      {
        test.removeBack();
        compare.pop_back();
        std::cout << "   Should be: ";
        printVector(compare);
        std::cout << "Actual value: ";
        printVector(test.toVector());
        std::cout << "\t Comparing values: ";
        if (test.toVector() == compare) 
        {
          std::cout << "Passed\n";
        } else {
          std::cout << "Failed\n";
        }
      }
    }

    /**
     * Test removeFront()
     */
    void testRemoveFront()
    {
      LinkedListOfInts test;
      std::vector<int> compare;
      for (int i = 0; i < 10; i++)
      {
        test.addFront(i);
        compare.emplace(compare.begin(), i);
      }
      for (int i = 0; i < 10; i++)
      {
        test.removeFront();
        compare.erase(compare.begin());
        std::cout << "   Should be: ";
        printVector(compare);
        std::cout << "Actual value: ";
        printVector(test.toVector());
        std::cout << "\t Comparing values: ";
        if (test.toVector() == compare) 
        {
          std::cout << "Passed\n";
        } else {
          std::cout << "Failed\n";
        }
      }
    }

    /**
     * Print a vector.
     */
    void printVector(std::vector<int> const &v)
    {
      std::cout << "Vector: ";
      for (unsigned int i = 0; i < v.size(); i++)
      {
        std::cout << v.at(i) << " ";
      }
      std::cout << std::endl;
    }

    /**
     * Run all tests
     */
    void runTests()
    {
      std::cout << "Running isEmpty() test: \n";
      this->testIsEmpty(); 
      std::cout << "\nRunning size() test: \n";
      this->testSize();
      std::cout << "\nRunning search() test: \n";
      this->testSearch();
      std::cout << "\nRunning addBack() test: \n";
      this->testAddBack();
      std::cout << "\nRunning addFront() test: \n";
      this->testAddFront();
      std::cout << "\nRunning removeBack() test: \n";
      this->testRemoveBack();
      std::cout << "\nRunning removeFront() test: \n";
      this->testRemoveFront();
    }

  private:
    int numTests = 0;
};
