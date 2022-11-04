/*
 * tree.cpp
 *
 *  Created on: Aug 31, 2022
 *      Author: jsaavedr
 */

#include "tree.hpp"
#include <iostream>



Tree::Tree(): root(nullptr) {

}

TreeNode* Tree::setRoot(TreeNode* node){
	if (root == nullptr){
		root = node;
		root->setIsFolder(1);
	}
	return root;
}

void Tree::insert(TreeNode* child, TreeNode* parent, int _isFolder){
	if (parent != nullptr){
		(parent->getChildren())->insertFirst(child, parent, _isFolder);
	}
}

void Tree::insert(std::string val, std::string val_parent, int _isFolder){
	TreeNode* parent = find(val_parent);
	if (parent != nullptr && parent->getIsFolder() == 1){
		TreeNode* child = new TreeNode(val);
		insert(child, parent, _isFolder);
		std::cout << "insertado " << val << " in " << val_parent << " at " << parent << std::endl;
	}
	else {
		std::cout << "Cannot insert " << val << " in " << val_parent << std::endl;
	}
}

//baja a los hijos, una y otra vez, la hizo el profe
TreeNode* Tree::find_rec(std::string val, TreeNode* node){
	TreeNode* ans = nullptr;
	if (node != nullptr){
		if (node->getData() == val){
			ans = node;
		}
		else{ // search in children
			TreeList* childrenList = node->getChildren();
			TreeListNode* ptr = childrenList->getHead();
			while (ptr!=nullptr && ans == nullptr){
				ans = find_rec(val, ptr->getData());
				ptr = ptr->getNext();
			}
		}
	}
	return ans;
}

TreeNode* Tree::find(std::string val){
	TreeNode* ans = find_rec(val, root);
	return ans;
}

// Encontrar un nodo entre los desendientes a partir de un nodo, find
TreeNode* Tree::find_curr(std::string val, TreeNode* node){
	TreeNode* ans = find_rec(val, node);
	return ans;
}

// Encontrar un nodo entre los hijos de un padre
TreeNode* Tree::find_child(std::string val, TreeNode* node){
	TreeNode* ans = nullptr;
	if (node != nullptr){
		TreeList* childrenList = node->getChildren();
		TreeListNode* ptr = childrenList->getHead();
		while (ptr!=nullptr && ans == nullptr){
			ans = find_curr(val, ptr->getData());
			ptr = ptr->getNext();
		}
	}
	return ans;
}

// Funcion para encontrar el camino desde la raiz de un nodo
std::string Tree::path_rec(TreeNode* node, std::string path){
	if (node != nullptr){
		if (node->getParent() != nullptr){
			path = path_rec(node->getParent(), path);
			path += "/"; 
		}
		path += node->getData();
	}
	return path;
}

// Funcion para encontrar el camino desde la raiz de un nodo
std::string Tree::path(std::string val){
	std::string path = "";
	TreeNode* node = find(val);
    path = path_rec(node, path);
	return path;
}


// Funcion que elimina un nodo y todos sus descendientes
void Tree::remove(TreeNode* node) {
	if (node != nullptr) {
		TreeList* children = node->getChildren();
		while (children->getHead() != nullptr){
			children->removeFirst();
		}
		TreeNode* parent = node->getParent();
		if (parent != nullptr){
			(parent->getChildren())->remove(node->getData());
		}
		else {
			root = nullptr;
		}
	}
}


// Funcion para imprimir los hijos de un nodo
void Tree::print(TreeNode* node){
	if (node != nullptr){
		TreeList* childrenList = node->getChildren();
		TreeListNode* ptr = childrenList->getHead();
		int i = 0;
		while (ptr!=nullptr){
			if (ptr->getData()->getIsFolder() == 1){
				std::cout << i << ". Folder " << (ptr->getData())->getData() << std::endl;
			}
			else{
				std::cout << i << ". File " << (ptr->getData())->getData() << std::endl;
			}
			i++;
			ptr = ptr->getNext();
		}
	}
}

// imprimen el arbol, la creo el profe, funcion tree
void Tree::traverse_rec(TreeNode* node, int level){
	if (node != nullptr){
		std::cout << std::string(level * 3, '-');
		if (node->getIsFolder() == true){
			std::cout<< node->getData() << " [ Folder at level " << level << " ]" <<std::endl;
		}
		else {
			std::cout<< node->getData() << " [ File at level " << level << " ]" <<std::endl;
		}
		TreeList* childrenList = node->getChildren();
		TreeListNode* ptr = childrenList->getHead();
		while (ptr!=nullptr){
			traverse_rec(ptr->getData(), level + 1);
			ptr = ptr->getNext();
		}
	}
}

void Tree::traverse(){
	std::cout << std::endl;
	traverse_rec(root, 1);
	std::cout << std::endl;
}


Tree::~Tree() {
	delete root;
}


