/*
 * tree.hpp
 *
 *  Created on: Aug 31, 2022
 *      Author: jsaavedr
 */

#ifndef TREE_HPP_
#define TREE_HPP_

#include "treeNode.hpp"




class Tree {
private:
	TreeNode* root;
public:
	Tree();
	TreeNode* setRoot(TreeNode* node);
	void insert(TreeNode* node, TreeNode* parent, int _isFolder);
	void insert(std::string child, std::string parent, int _isFolder);

	TreeNode* find_rec(std::string val, TreeNode* node);
	TreeNode* find(std::string val);
	TreeNode* find_curr(std::string val, TreeNode* node);
	TreeNode* find_child(std::string val, TreeNode* node);

	std::string path_rec(TreeNode* node, std::string path);
	std::string path(std::string val);

	void remove(TreeNode* node);

	void print(TreeNode* node);

	void traverse_rec(TreeNode* node, int level);
	void traverse();
	virtual ~Tree();
};



#endif /* TREE_HPP_ */
