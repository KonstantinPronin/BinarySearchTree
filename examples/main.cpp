#include "BinarySearchTree.h"

int main() {
	BinarySearchTree<int> Tree({ 11, 12, 15, 9 });
	auto a = 8;
	Tree.add(a);

	std::ofstream file("C:/Users/sayfer/Desktop/BinarySearchTree.txt");
	file << Tree;
	file.close();
	
	std::cout << Tree;
	std::cout << std::endl;
	
	BinarySearchTree<int> Tree2(std::move(Tree));
	std::cout << Tree2;
	std::cout << std::endl;

	Tree = std::move(Tree2);
	std::cout << Tree;
	
	system("pause");
	return 0;
}
