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
std::ifstream& operator >> (std::ifstream& fin, BinarySearchTree<T>& tree);

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
	size_t Size;
	
public:
	BinarySearchTree() : Root(nullptr), Size(0) {};
	BinarySearchTree(const std::initializer_list<T>& list);
	BinarySearchTree(const BinarySearchTree<T>& tree);
	BinarySearchTree(BinarySearchTree<T>&& tree);
	~BinarySearchTree();
	
	bool Insert(T& val) noexcept;
	const T* Find(const T& val) const noexcept;
	void Direct(std::ostream& out, Node* root) const noexcept;
	void Symmetric(std::ostream& out, Node* root) const noexcept;
	void Copy(Node* ptr) noexcept;
	size_t size() const {return Size;}
	bool Compare(Node* ptr1, Node* ptr2) const noexcept;
	Node* ReturnRoot() const noexcept {return Root;}
	
	BinarySearchTree<T>& operator= (const BinarySearchTree<T>& tree) noexcept;
	BinarySearchTree<T>& operator= (BinarySearchTree<T>&& tree) noexcept;
	bool operator== (const BinarySearchTree<T>& tree) const noexcept;
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const std::initializer_list<T>& list){
	for (auto it : list) {
		Insert(it);
	}
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& tree){
	*this = tree;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& tree):Size(tree.Size), Root(tree.Root){
	tree.Root = nullptr;
}

template <typename T>
bool BinarySearchTree<T>::Insert(T& val) noexcept {
	if (!Size) {
		Root = new Node(val);
		Size++;
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
	Size++;
	return true;
}

template <typename T>
const T* BinarySearchTree<T>::Find(const T& val) const noexcept {
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
void BinarySearchTree<T>::Copy(Node* ptr) noexcept {
	Insert(ptr->value);
	if (ptr->left) Copy(ptr->left);
	if (ptr->right) Copy(ptr->right);
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator= (const BinarySearchTree<T>& tree) noexcept {
	if (this == &tree)
		return *this;
	
	delete Root;
	Size = 0;
	Copy(tree.Root);
	return *this;
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator= (BinarySearchTree<T>&& tree) noexcept {
	if (this == &tree)
		return *this;

	delete Root;
	Size = tree.Size;
	Root = tree.Root;
	tree.Root = nullptr;

	return *this;
}

template <typename T>
bool BinarySearchTree<T>::Compare(Node* ptr1, Node* ptr2) const noexcept {
	if (ptr1 && !ptr2) return false;
	if (!ptr1 && ptr2) return false;
	if (ptr1 && ptr2) {
		if (ptr1->value == ptr2->value) {
			Compare(ptr1->left, ptr2->left);
			Compare(ptr1->right, ptr2->right);
		}
		else return false;
	}
	return true;
}

template <typename T>
bool BinarySearchTree<T>::operator== (const BinarySearchTree<T>& tree) const noexcept {
	if (Size != tree.Size) return false;
	return Compare(Root, tree.Root);
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
		delete Root;
		Root = nullptr;
		Size = 0;
}

template <typename T>
void BinarySearchTree<T>::Direct(std::ostream& out, Node* root) const noexcept{
	if (!root) return;
	
	out << root->value << ' ';
	Direct(out, root->left);
	Direct(out, root->right);
}

template <typename T>
void BinarySearchTree<T>::Symmetric(std::ostream& out, Node* root) const noexcept {
	if (!root) return;

	Symmetric(out, root->left);
	out << root->value << ' ';
	Symmetric(out, root->right);
}

template <typename T>
std::ostream& operator << (std::ostream& out, const BinarySearchTree<T>& tree) {
	tree.Symmetric(out, tree.ReturnRoot());
	return out;
}

template <typename T>
std::ofstream& operator << (std::ofstream& fout, const BinarySearchTree<T>& tree) {
	tree.Direct(fout, tree.ReturnRoot());
	return fout;
}

template <typename T>
std::istream& note(std::istream& in, BinarySearchTree<T>& tree) {
	T value;
	while (in >> value)
		tree.Insert(value);
	return in;
}

template <typename T>
std::istream& operator >> (std::istream& in, BinarySearchTree<T>& tree) {
	note(in, tree);
	return in;
}

template <typename T>
std::ifstream& operator >> (std::ifstream& fin, BinarySearchTree<T>& tree) {
	note(fin, tree);
	return fin;
}
