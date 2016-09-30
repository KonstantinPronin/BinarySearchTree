
#include "../tests/catch.h"
#include "..include/BinarySearchTree.h"

SCENARIO("If inserting element already exist in tree")
{
   GIVEN("Tree with existing element")
   {
      BinarySearchTree<int> tree {8,10,3};
      WHEN("Inserting")
      {
         THEN("Method must return false and doent change size")
         {
            REQUIRE(tree.insert(10) == false);
            REQUIRE(tree.size() == 3)
         }
      }
   }
}

SCENARIO("If inserting element does not exist in tree")
{
   GIVEN("Tree with non-existing element")
   {
      BinarySearchTree<int> tree { 8,10,3};
      WHEN("Inserting")
      {
         THEN("Method must return true and change size")
         {
            REQUIRE(tree.insert(7) == true);
            REQUIRE(tree.size() == 4)
         }
      }
   }
}

SCENARIO("If inserting element < rott")
{
   GIVEN("Tree with non-existing element")
   {
      BinarySearchTree<int> tree1 { 8,10,3};
      BinarySearchTree<int> tree2 { 8, 10, 3, 7};
      WHEN("Inserting")
      {
         THEN("Inserted left from root")
         {
            REQUIRE(tree1 == tree2)
         }
      }
   }
}

SCENARIO("If inserting element > root")
{
   GIVEN("Tree with non-existing element")
   {
      BinarySearchTree<int> tree1 {8,10,3};
      BinarySearchTree<int> tree2 { 8, 10, 3, 9};
      WHEN("Inserting")
      {
         THEN("Inserted right from root")
         {
            REQUIRE(tree1 == tree2)
         }
      }
   }
}

