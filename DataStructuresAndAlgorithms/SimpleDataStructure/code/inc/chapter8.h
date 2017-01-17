#ifndef __SIMPLEDATASTRUCTURES_CHAPTER_8__
#define __SIMPLEDATASTRUCTURES_CHAPTER_8__


namespace SimpleDataStructures
{
/* 顺序查找 a为数组 n为数组的元素个数 key为要超找的值*/
int Sequential_Search(int* a, int n, int key);

/* 折半查找(二分查找) a为有序数组 n为数组的元素个数 key为要超找的值 */
int Binary_Search(int* a, int n, int key);

/* 插值查找 a为有序数组 n为数组的元素个数 key为要超找的值 */
int Interpolation_Search(int* a, int n, int key);

/* 二叉排序树 */
struct BinaryNode
{
	int value;
	BinaryNode* left;
	BinaryNode* right;

	BinaryNode(int _val) : value(_val), left(NULL), right(NULL) {}
};

class BinarySortTree
{
public:
	BinarySortTree() : root (NULL) {}
	~BinarySortTree();

	bool add(int _val);
	bool del(int _val);
	bool search(int _val);
	bool clear();

	// _val 值 _objParentNode 双亲节点 _objNode 目标节点
	// 查找值为 _val 的目标节点以及双亲节点
	bool find(int _val, BinaryNode** _objParentNode, BinaryNode** _objNode);

	// 插入新的节点 若已存在值为_val的节点 插入失败
	bool insert(int _val);

private:
	
	bool _search(BinaryNode* node, int _val);
	BinaryNode* _searchParentNode(BinaryNode* parentNode, int _val);
	bool _clear(BinaryNode* node);

	bool _find(BinaryNode* _node, int _val, BinaryNode** _objParentNode, BinaryNode** _objNode);

private:
	BinaryNode* root;
};

}

#endif