/*
 * childrenList.hpp
 *
 *  Created on: Aug 31, 2022
 *      Author: jsaavedr
 */

#ifndef CHILDRENLIST_HPP_
#define CHILDRENLIST_HPP_

#include "treeListNode.hpp"
#include <string>



class TreeNode;
class TreeListNode;
class TreeList {
private:
	TreeListNode* head;
public:
	TreeList();
	TreeListNode* getHead();
	void insertFirst(TreeNode* treeNode, TreeNode* parent, int _isFolder);
	void removeFirst();
	void remove(std::string val);
	void removeAll();
	bool isEmpty();
	TreeNode* find(std::string val);
	void print();
	virtual ~TreeList();
};



#endif /* CHILDRENLIST_HPP_ */
