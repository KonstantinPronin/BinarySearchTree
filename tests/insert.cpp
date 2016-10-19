
#include "../tests/catch.hpp"
#include "BinarySearchTree.h"

SCENARIO("If inserting element already exist in tree")
{
   GIVEN("Tree with existing element")
   {
      BinarySearchTree<int> tree {8,10,3};
      WHEN("Inserting")
      {
         THEN("Method must throw exception")
         {  
            
            REQUIRE_THROWS_AS (tree.Insert (10), BST_logic_error<int>&);
   
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
            int a = 7;
            REQUIRE(tree.Insert(a) == true);
            REQUIRE(tree.ReturnSize() == 4);
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
            int a = 7;
            tree1.Insert(a);
            REQUIRE(tree1 == tree2);
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
            int a = 9;
            tree1.Insert(a);
            REQUIRE(tree1 == tree2);
         }
      }
   }
}

