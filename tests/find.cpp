#include "../tests/catch.hpp"
#include "../include/BinarySearchTree.h"


SCENARIO("Find existing element"){
    GIVEN("Tree with element"){
        BinarySearchTree<int> tree{11, 14, 16, 18};
        WHEN("Element exist"){
            THEN("Find it") {
              REQUIRES (tree.find (11) != 0)
            }
        }

    }
}

SCENARIO("Find not existing element"){
    GIVEN("Tree without element"){
        BinarySearchTree<int> tree{11, 14, 16, 18};
        WHEN("Element doesnt exist"){
            THEN("Wont find it") {
              REQUIRES (tree.find (10) == nullptr)
            }
        }

    }
}

SCENARIO("Find existing element"){
    GIVEN("Tree with element"){
        const BinarySearchTree<int> tree{11, 14, 16, 18};
        WHEN("Element exist"){
            THEN("Find it") {
              REQUIRES (tree.find (11) != 0)
            }
        }

    }
}

SCENARIO("Find not existing element"){
    GIVEN("Tree without element"){
        const BinarySearchTree<int> tree{11, 14, 16, 18};
        WHEN("Element doesnt exist"){
            THEN("Wont find it") {
              REQUIRES (tree.find (10) == nullptr)
            }
        }

    }
}
