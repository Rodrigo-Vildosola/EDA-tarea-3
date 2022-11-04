/*
 * treeNode.cpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */

#include "treeNode.hpp"



TreeNode::TreeNode(): parent(nullptr), data(""), children(new TreeList()) {
}

TreeNode::TreeNode(std::string val): parent(nullptr), data(val), children(new TreeList()) {
}

void TreeNode::setParent(TreeNode* node){
	parent = node;
}

void TreeNode::setData(std::string val){
		data = val;
}
void TreeNode::setChildren(TreeList* list){
	children = list;
}
void TreeNode::setIsFolder(int val){
	isFolder = val;
}

TreeNode* TreeNode::getParent(){
	return parent;
}

std::string TreeNode::getData(){
	return data;
}
int TreeNode::getIsFolder(){
	return isFolder;
}

TreeList* TreeNode::getChildren(){
	return children;
}

TreeNode::~TreeNode() {
	//action when a treeNode is deleted
	//delete the descendants only
	if (children != nullptr){
		delete children;
	}
}


