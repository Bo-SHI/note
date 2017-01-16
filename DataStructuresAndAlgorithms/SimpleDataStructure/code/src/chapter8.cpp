#include <iostream>
#include <chapter8.h>

namespace SimpleDataStructures
{
	
int Sequential_Search(int* a, int n, int key)
{
	if(NULL == a) {
		return 0;
	}
	
	for(int i = 0; i < n; ++i) {
		if(*(a+i) == key) {
			return i + 1;
		}
	}
	
	return 0;
}

int Binary_Search( int* a, int n, int key )
{
	if(NULL == a) {
		return 0;
	}

	int low = 1;
	int high = n;

	while(low <= high) {
		int mid = (high + low) / 2;

		if(key < *(a+mid - 1)) {
			high = mid - 1;
		} else if(key > *(a+mid - 1)) {
			low = mid + 1;
		} else {
			return mid;
		}
	}

	return 0;
}

int Interpolation_Search( int* a, int n, int key )
{
	if(NULL == a) {
		return 0;
	}

	int low = 1;
	int high = n;

	while(low <= high) {
		int mid = low + (key - *(a + low - 1)) / (*(a + high - 1) - *(a + low - 1)) * (high - low);

		if(key < *(a + mid - 1)) {
			high = mid - 1;
		} else if(key > *(a + mid - 1)) {
			low = mid + 1;
		} else {
			return mid;
		}
	}

	return 0;
}

/* Binary Sort Tree*/

bool BinarySortTree::add( int _val )
{
	BinaryNode* node = new BinaryNode(_val);
	if(node == NULL) {
		return false;
	}

	if(NULL == root) {
		root = node;
		return true;
	}

	BinaryNode* parentNode = _searchParentNode(root, _val);
	if(NULL == parentNode) {
		return false;
	}
	
	if(parentNode->value < _val) {
		parentNode->right = node;
		return true;
	}

	if(parentNode->value > _val) {
		parentNode->left = node;
		return true;
	}

	return false;
}

bool BinarySortTree::del( int _val )
{
	return false;
}

bool BinarySortTree::search( int _val )
{
	return _search(root, _val);
}

bool BinarySortTree::_search( BinaryNode* node, int _val )
{
	if(node == NULL) {
		return false;
	}

	if(node->value == _val) {
		return true;
	}

	if(node->value > _val) {
		return _search(node->left, _val);
	}

	if(node->value < _val) {
		return _search(node->right, _val);
	}

	return false;
}

BinaryNode* BinarySortTree::_searchParentNode( BinaryNode* parentNode, int _val )
{
	if(NULL == parentNode) {
		return NULL;
	}

	if(parentNode->value == _val) {
		return NULL;
	}

	if(parentNode->value > _val) {
		if(parentNode->left == NULL) {
			return parentNode;
		} else {
			return _searchParentNode(parentNode->left, _val);
		}
	}

	if(parentNode->value < _val) {
		if(parentNode->right == NULL) {
			return parentNode;
		} else {
			return _searchParentNode(parentNode->right, _val);
		}
	}

	return NULL;
}

}