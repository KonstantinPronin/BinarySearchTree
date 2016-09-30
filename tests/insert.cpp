
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
