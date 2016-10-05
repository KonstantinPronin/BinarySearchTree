

#include "../tests/catch.hpp"
#include "../include/BinarySearchTree.h"

SCENARIO ("Size of empty tree") {
    GIVEN("Given empty tree") {
        BinarySearchTree<int> tree;

       WHEN ("Decide size") {
            THEN ("Size must be empty") {
                REQUIRE(tree.size() == 0);
            }
        }
    }
}

SCENARIO("Size of tree with some itemps"){
    GIVEN("Given not empty tree") {
        BinarySearchTree<int> tree{11, 14, 16, 18};

        WHEN ("Decide size") {
            THEN ("Size mustn`t be empty") {
                REQUIRE(tree.size() != 0);
            }
        }
    }

}

SCENARIO("Size of empty const tree"){
    GIVEN("Given const empty tree") {
        const BinarySearchTree<int> tree;

        WHEN ("Decide size") {
            THEN ("Size must be empty") {
                REQUIRE(tree.size() == 0);
            }
        }
    }

}

SCENARIO("Size of not empty const tree"){
    GIVEN("Given const not empty tree") {
        const BinarySearchTree<int> tree{11, 14, 10};

        WHEN ("Decide size") {
            THEN ("Size mustn`t be empty") {
                REQUIRE(tree.size() != 0);
            }
        }
    }

}
