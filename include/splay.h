#pragma once
#include <iostream>
#include <functional>
template <typename T>
class SplayTree
{
private:
	struct Node
	{
		Node *left;
		Node *right;
		Node *parent;
		T key;
		Node(const T& value = T()) : left(nullptr), right(nullptr), parent(nullptr), key(value) {}
	} *root;
	std::size_t count;

	void _transplant(Node *localParent, Node *localChild)
	{
		if (localParent == root)
			root = localChild;
		else if (localParent == localParent->parent->left)
			localParent->parent->left = localChild;
		else if (localParent == localParent->parent->right)
			localParent->parent->right = localChild;

		if (localChild != nullptr)
			localChild->parent = localParent->parent;
	}

	void _leftRotate(Node *localRoot)
	{
		Node *_right = localRoot->right;

		localRoot->right = _right->left;
		if (_right->left != nullptr)
			_right->left->parent = localRoot;
		_transplant(localRoot, _right);
		_right->left = localRoot;
		_right->left->parent = _right;
	}

	void _rightRotate(Node *localRoot)
	{
		Node *_left = localRoot->left;

		localRoot->left = _left->right;
		if (_left->right != nullptr)
			_left->right->parent = localRoot;
		_transplant(localRoot, _left);
		_left->right = localRoot;
			
	
		//std::cout << *getKeyRoot() << "\n";
		localRoot->parent = _left;
	}

	Node *_search(const T& value)
	{
		Node *searchedElement = root;
		while (searchedElement != nullptr)
		{
			if (searchedElement->key < value)
				searchedElement = searchedElement->right;
			else if (value < searchedElement->key)
				searchedElement = searchedElement->left;
			else if (searchedElement->key == value)
			{
				return searchedElement;
			}
		}
		return nullptr;
	}

	void _splay(Node *pivot)
	{
		while (pivot != root)
		{      
			if (pivot->parent == root)
			{

				if (pivot == pivot->parent->left)
					_rightRotate(pivot->parent);
				else if (pivot == pivot->parent->right)

					_leftRotate(pivot->parent);
			}
			else
			{
				// Zig-Zig step.
				if (pivot == pivot->parent->left && pivot->parent == pivot->parent->parent->left)
				{

					_rightRotate(pivot->parent->parent);
					_rightRotate(pivot->parent);

				}
				else if (pivot == pivot->parent->right && pivot->parent == pivot->parent->parent->right)
				{
					_leftRotate(pivot->parent->parent);
					_leftRotate(pivot->parent);
				}
				// Zig-Zag step.
				else if (pivot == pivot->parent->right && pivot->parent == pivot->parent->parent->left)
				{
					_leftRotate(pivot->parent);
					_rightRotate(pivot->parent);
				}
				else if (pivot == pivot->parent->left && pivot->parent == pivot->parent->parent->right)
				{
					_rightRotate(pivot->parent);
					_leftRotate(pivot->parent);
				}
			}
		}
	}



public:
	SplayTree() : root(nullptr), count(0) {	 };
	~SplayTree()
	{
		delete root;
	}
	void display(const Node* temp, unsigned int level)const
	{
		if (temp)
		{
			display(temp->left, level + 1);
			for (int i = 0; i < level; i++)
				std::cout << "__";
			std::cout << temp->key << "\n";
			display(temp->right, level + 1);
		}
	}



	void insert(const T& value)
	{
		Node *preInsertPlace = nullptr;
		Node *insertPlace = root;

		while (insertPlace != nullptr)
		{
			preInsertPlace = insertPlace;

			if (insertPlace->key < value)
				insertPlace = insertPlace->right;
			else if (value < insertPlace->key) {
				insertPlace = insertPlace->left;
			}
		}

		Node *insertElement = new Node(value);
		insertElement->parent = preInsertPlace;
		

		if (preInsertPlace == nullptr)
			root = insertElement;
		else if (preInsertPlace->key < insertElement->key)
			preInsertPlace->right = insertElement;
		else if (insertElement->key < preInsertPlace->key)
			preInsertPlace->left = insertElement;
		++count;
		_splay(insertElement);
	}


	void remove(const T& value)
	{
		Node *removeElement = search(value);
		
		if (removeElement != nullptr && count > 0)
		{
			if (removeElement->left == nullptr)
			{
				_transplant(removeElement, removeElement->right);
			}
			else if (removeElement->right == nullptr)
			{
				_transplant(removeElement, removeElement->left);
			}
			else
			{
				Node *newLocalRoot = removeElement->left;
				while (newLocalRoot->right != nullptr)
				{
					newLocalRoot = newLocalRoot->right;
				}
				if (newLocalRoot->parent != removeElement)
				{
					_transplant(newLocalRoot, newLocalRoot->right);
					newLocalRoot->right = removeElement->right;
					newLocalRoot->right->parent = newLocalRoot;
				}
				_transplant(removeElement, newLocalRoot);
				newLocalRoot->right = removeElement->right;
				newLocalRoot->right->parent = newLocalRoot;
				_splay(newLocalRoot);
			}
			delete[] removeElement;
			--count;
		}
	}


	Node* search(T const& value)
	{
		Node* searchedNode = _search(value);
		if(searchedNode)
			_splay(searchedNode);
		return searchedNode;
	}

	Node *getRoot()const
	{
		return root;
	}

	T* getKey(const T& value)
	{
		Node *node = _search(value);
		if (node != nullptr)
			return new T(node->key);
		else
			return nullptr;
	}


	std::size_t getCount()
	{
		return count;
	}

	T* getRightKey(const T& key)
	{
		Node *node = _search(key);
		if (node != nullptr && node->right != nullptr)
			return new T(node->right->key);
		else
			return nullptr;
	}

	T* getKeyRoot()
	{
		if (root)
			return new T(root->key);
		else
			return nullptr;
	}
	T* getLeftKey(const T& key)
	{
		Node *node = _search(key);
		if (node != nullptr && node->left != nullptr)
			return new T(node->left->key);
		else
			return nullptr;
	}


	T* getParentKey(const T& key)
	{
		Node *node = _search(key);
		if (node != nullptr && node->parent != nullptr)
			return new T(node->parent->key);
		else
			return nullptr;
	}
};


