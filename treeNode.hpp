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
	std::string data; //cambio de int a string para el ejercicio
	int isFolder; // lo agregamos para indicar si es carpeta o no
	TreeList* children;
	
public:
	TreeNode();
	TreeNode(std::string val);

	void setParent(TreeNode* node);
	void setData(std::string val);
	void setChildren(TreeList* list);
	void setIsFolder(int val); // poner si es o no carpeta


	TreeNode* getParent();
	std::string getData();
	int getIsFolder(); //ver si es carpeta
	TreeList* getChildren();
	virtual ~TreeNode();
};



#endif /* TREENODE_HPP_ */
