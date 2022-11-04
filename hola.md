Tree tree;
	tree.setRoot(new TreeNode("/"));

	tree.insert("child1", "/", 1);
	tree.insert("child2", "/", 1);
	tree.insert("grandchild1", "child2", 1);
	tree.insert("grandchild2", "child2", 0);
    tree.insert("grand", "grandchild2", 0);
	tree.insert("grandchild3", "child2", 1);
	tree.insert("grandchild4", "child1", 1);

	tree.traverse();
    cout << tree.path("grandchild4") << endl;
