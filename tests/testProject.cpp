#include <catch.hpp>

#include "splay.h"
#include "treap.h"
#include "RBT.hpp"
#include "AVL-tree.hpp"
#include "AATree.hpp"
#include "BST.hpp"

TEST_CASE("AVL", "[1]") 
{
   AVL_tree<int> tree;
   for (size_t i = 0; i < 50; ++i)
   {
	   tree.insert(i);
   }
   
   REQUIRE(tree.count() == 50);
   for (size_t i = 0; i < 50; ++i)
   {
	   tree.deleteElement(i);
   }
   REQUIRE(tree.count() == 0);
}

    
TEST_CASE("RBT", "[2]") 
{
   Tree<int> tree;
   for (size_t i = 0; i < 50; ++i)
   {
	   tree.insert(i);
   }
   
   REQUIRE(tree.count() == 50);
   for (size_t i = 0; i < 50; ++i)
   {
	   tree.deleteElement(i);
   }
   REQUIRE(tree.count() == 0);
}

     
TEST_CASE("Splay", "[3]") 
{
    SplayTree<int> tree;
    for (size_t i = 0; i < 50; ++i)
   {
	   tree.insert(i);
   }
   
   REQUIRE(tree.getCounter() == 50);
   for (size_t i = 0; i < 50; ++i)
   {
	   tree.remove(i);
   }
   REQUIRE(tree.getCounter() == 0);
}


TEST_CASE("Treap", "[4]") 
{
   Treap<int> tree;
   for (size_t i = 0; i < 50; ++i)
   {
	   tree.Insert(i);
   }
   
   REQUIRE(tree.getCount() == 50);
   for (size_t i = 0; i < 50; ++i)
   {
	   tree.Remove(i);
   }
   REQUIRE(tree.getCount() == 0);
}

                       
TEST_CASE("AATree", "[5]") 
{
   AATree<int> tree;
   for (size_t i = 0; i < 50; ++i)
   {
	   tree.insert(i);
   }
   
   REQUIRE(tree.getcount() == 50);
   for (size_t i = 0; i < 50; ++i)
   {
	   tree.remove(i);
   }
   REQUIRE(tree.getcount() == 0);
}


TEST_CASE("BST", "[6]") 
{
   BST<int> tree;
   for (size_t i = 0; i < 50; ++i)
   {
	   tree.insert(i);
   }
   
   REQUIRE(tree.get_count() == 50);
   for (size_t i = 0; i < 50; ++i)
   {
	   tree.remove(i);
   }
   REQUIRE(tree.get_count() == 0);
}
