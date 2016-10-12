#include "../tests/catch.hpp"
#include "../include/BinarySearchTree.h"

SCENARIO ("Size must decrease"){
  GIVEN ("Tree and its size"){
    BinarySearchTree<int> tree{11, 12, 15, 9, 10, 14, 17, 13};
    auto size = tree.ReturnSize();
    tree.Remove(13);
    THEN ("Size decrease"){
      REQUIRE(tree.ReturnSize() == size - 1);
    }
  }
}

SCENARIO ("Changing the tree"){
  GIVEN ("Two trees"){
    WHEN ("Remove root"){
      BinarySearchTree<int> tree1{11};
      BinarySearchTree<int> tree2();
      tree1.Remove(11);
      THEN ("Tree must be equal"){
         REQUIRE(tree1 == tree2);
      }
    }
    WHEN ("Root without offsprings"){
      BinarySearchTree<int> tree1{11, 12, 9};
      BinarySearchTree<int> tree2{11, 9};
      tree1.Remove(12);
      THEN ("Tree must be equal"){
         REQUIRE(tree1 == tree2);
      }
     } 
     WHEN ("Root with right offspring"){
      BinarySearchTree<int> tree1{11, 12, 15, 9};
      BinarySearchTree<int> tree2{11, 15, 9};
      tree1.Remove(12);
      THEN ("Tree must be equal"){
         REQUIRE(tree1 == tree2);
      }
     }
     WHEN ("Root with left offspring"){
      BinarySearchTree<int> tree1{11, 12, 15, 9. 10};
      BinarySearchTree<int> tree2{11, 12, 15, 10};
      tree1.Remove(9);
      THEN ("Tree must be equal"){
        REQUIRE(tree1 == tree2);
      }
     }
     WHEN ("Root with both offsprings"){
      BinarySearchTree<int> tree1{11, 12, 15, 9, 10, 14, 17, 13};
      BinarySearchTree<int> tree2{11, 12, 9, 10, 14, 17, 13};
      tree1.Remove(15);
      THEN ("Tree must be equal"){
        REQUIRE(tree1 == tree2);
      }
     }
     WHEN ("There is no such element"){
       BinarySearchTree<int> tree{11, 12, 15, 9, 10, 14, 17, 13};
       THEN ("Return value is false"){
        REQUIRE(tree.Remove(5) == false);
       }
     }
  }
}
