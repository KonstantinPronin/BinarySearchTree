#include <iostream>
#include <fstream>

template <typename T>
class BinarySearchTree;

template <typename T>
std::ofstream& operator << (std::ofstream& fout, const BinarySearchTree<T>& tree);

template <typename T>
std::ostream& operator << (std::ostream& out, const BinarySearchTree<T>& tree);

template <typename T>
std::istream& operator >> (std::istream& in, BinarySearchTree<T>& tree);

template <typename T>
class BinarySearchTree {
	class Node {
	public:
		T value;
		Node* left;
		Node* right;
		Node(T val):value(val), left(nullptr), right(nullptr) {}
		~Node() {
				delete right;
				delete left;
				right = nullptr;
				left = nullptr;
		}
	}; 

	Node* Root;
	size_t size;
	
public:
	BinarySearchTree() : Root(nullptr), size(0) {};
	BinarySearchTree(BinarySearchTree<T>&& tree);
	BinarySearchTree(const std::initializer_list<T>& list);
	bool add(T& val) noexcept;
	const T* get(const T& val) const noexcept;
	void Traverse(std::ostream& out, Node* root) const noexcept;
	Node* ReturnRoot() const noexcept {return Root;}
	BinarySearchTree<T>& operator= (BinarySearchTree<T>&& tree);
	~BinarySearchTree();
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const std::initializer_list<T>& list):size(0), Root(nullptr){
	for (auto it : list) {
		add(it);
	}
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& tree):size(tree.size), Root(tree.Root){
	tree.Root = nullptr;
}

template <typename T>
bool BinarySearchTree<T>::add(T& val) noexcept {
	if (!size) {
		Root = new Node(val);
		size++;
		return true;
	}
	Node* CurPtr = Root;
	Node* PrevPtr = Root;
	while (CurPtr)
	{
		PrevPtr = CurPtr;
		if (CurPtr->value > val)
			CurPtr = CurPtr->left;
		else if (CurPtr->value < val)
			CurPtr = CurPtr->right;
		else if (CurPtr->value == val)
			return false;
	}
	if (PrevPtr->value > val)
		PrevPtr->left = new Node(val);
	else 
		PrevPtr->right = new Node(val);
	size++;
	return true;
}

template <typename T>
const T* BinarySearchTree<T>::get(const T& val) const noexcept {
	const Node* tmp = Root;
	while (tmp) {
		if (tmp->value > val) 
			tmp = tmp->left;
		else if (tmp->value < val) 
			tmp = tmp->right;
		else return &tmp->value;
	}
	return nullptr;
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator= (BinarySearchTree<T>&& tree) {
	if (this == &tree)
		return *this;

	delete Root;
	size = tree.size;
	Root = tree.Root;
	tree.Root = nullptr;

	return *this;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
		delete Root;
		Root = nullptr;
		size = 0;
}

template <typename T>
void BinarySearchTree<T>::Traverse(std::ostream& out, Node* root) const noexcept{
	if (!root) return;
	
	out << root->value << ' ';
	Traverse(out, root->left);
	Traverse(out, root->right);
}

template <typename T>
std::ostream& operator << (std::ostream& out, const BinarySearchTree<T>& tree) {
	tree.Traverse(out, tree.ReturnRoot());
	return out;
}

template <typename T>
std::ofstream& operator << (std::ofstream& fout, const BinarySearchTree<T>& tree) {
	tree.Traverse(fout, tree.ReturnRoot());
	return fout;
}

template <typename T>
std::istream& operator >> (std::istream& in, BinarySearchTree<T>& tree) {
	size_t size = 0;
	std::cout << "Enter size: ";
	std::cin >> size;
	std::cout << '\n';
	for (size_t i = 0; i < size; i++) {
		T value;
		in >> value;
		tree.add(value);
		std::cout << ' ';
	}
	return in;
}
