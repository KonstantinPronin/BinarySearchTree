#include "../tests/catch.hpp"
#include "../include/BinarySearchTree.h"


SCENARIO("Find existing element"){
    GIVEN("Tree with element"){
        BinarySearchTree<int> tree{11, 14, 16, 18};
        WHEN("Element exist"){
            THEN("Find it") {
              REQUIRE (*(tree.Find(11)) == 11);
            }
        }

    }
}

SCENARIO("Find not existing element"){
    GIVEN("Tree without element"){
        BinarySearchTree<int> tree{11, 14, 16, 18};
        WHEN("Element doesnt exist"){
            THEN("Wont find it") {
              REQUIRE_THROWS_AS (tree.Find (10), BST_logic_error<int>&);
            }
        }

    }
}

SCENARIO("Find const existing element"){
    GIVEN("Tree with element"){
        const BinarySearchTree<int> tree{11, 14, 16, 18};
        WHEN("Element exist"){
            THEN("Find it") {
              REQUIRE (*(tree.Find (11)) == 11);
            }
        }

    }
}

SCENARIO("Find const not existing element"){
    GIVEN("Tree without element"){
        const BinarySearchTree<int> tree{11, 14, 16, 18};
        WHEN("Element doesnt exist"){
            THEN("Wont find it") {
              REQUIRE_THROWS_AS (tree.Find (10), BST_logic_error<int>&);
            }
        }

    }
}
