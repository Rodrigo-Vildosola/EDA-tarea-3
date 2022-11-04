CC = g++
Flags = -std=c++11
Target = treeSO

OBJS = main.o treeNode.o treeList.o treeListNode.o tree.o	


$(Target): $(OBJS)
	$(CC) $(Flags) $^ -o $@

%.o: %.cpp tree.hpp treeList.hpp treeListNode.hpp treeNode.hpp
	$(CC) $(Flags) -c $< -o $@


run: $(Target)
	./$(Target) 


clean:
	rm $(Target) $(OBJS) 
