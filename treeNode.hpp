/*
 * treeNode.hpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */

#ifndef TREENODE_HPP_
#define TREENODE_HPP_

#include "treeList.hpp"
#include <string>



class TreeList;
class TreeNode {
private:
	TreeNode* parent;
	std::string data; //data can be of any type
	int isFolder;
	TreeList* children;
	
public:
	TreeNode();
	TreeNode(std::string val);

	void setParent(TreeNode* node);
	void setData(std::string val);
	void setChildren(TreeList* list);
	void setIsFolder(int val);


	TreeNode* getParent();
	std::string getData();
	int getIsFolder();
	TreeList* getChildren();
	virtual ~TreeNode();
};



#endif /* TREENODE_HPP_ */
