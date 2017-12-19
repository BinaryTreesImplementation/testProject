#include <catch.hpp>

#include "splay.h"
#include "treap.h"
#include "RBT.hpp"
#include "AVL-tree.hpp"
#include "AATree.hpp"
#include "BST.hpp"


TEST_CASE("rbt", "[31]") 
{
    Tree<int> tree3;
    for (size_t i = 0; i < 50; ++i)
   {
	   tree3.insert(i);
   }
   
   //REQUIRE(tree.getCounter() == 50);
   for (size_t i = 0; i < 50; ++i)
   {
	   tree3.deleteElement(i);
   }
   REQUIRE(tree3.count() == 0);
}
    /*
TEST_CASE("RBT", "[2]") 
{
   Tree<int> tree1;
   for (size_t i = 0; i < 50; ++i)
   {
	   tree1.insert(i);
   }
   
   //REQUIRE(tree.count() == 50);
   for (size_t i = 0; i < 50; ++i)
   {
	   tree1.deleteElement(i);
   }
   REQUIRE(tree1.count() == 0);
}

TEST_CASE("AVL", "[1]") 
{
   AVL_tree<int> tree2;
   for (size_t i = 0; i < 50; ++i)
   {
	   tree2.insert(i);
   }
   
   //REQUIRE(tree.count() == 50);
   for (size_t i = 0; i < 50; ++i)
   {
	   tree2.deleteElement(i);
   }
   REQUIRE(tree2.count() == 0);
}    */ 
TEST_CASE("Splay", "[3]") 
{
    SplayTree<int> tree3;
    for (size_t i = 0; i < 50; ++i)
   {
	   tree3.insert(i);
   }
   
   //REQUIRE(tree.getCounter() == 50);
   for (size_t i = 0; i < 50; ++i)
   {
	   tree3.remove(i);
   }
   REQUIRE(tree3.getCounter() == 0);
}


TEST_CASE("Treap", "[4]") 
{
   Treap<int> tree4;
   for (size_t i = 0; i < 50; ++i)
   {
	   tree4.Insert(i);
   }
   
 //  R/EQUIRE(tree.getCount() == 50);
   for (size_t i = 0; i < 50; ++i)
   {
	   tree4.Remove(i);
   }
   REQUIRE(tree4.getCount() == 0);
}

                       
TEST_CASE("AATree", "[5]") 
{
   AATree<int> tree5;
   for (size_t i = 0; i < 50; ++i)
   {
	   tree5.insert(i);
   }
   
  // REQUIRE(tree.getcount() == 50);
   for (size_t i = 0; i < 50; ++i)
   {
	   tree5.remove(i);
   }
   REQUIRE(tree5.getcount() == 0);
}


TEST_CASE("BST", "[6]") 
{
   BST<int> tree6;
   for (size_t i = 0; i < 50; ++i)
   {
	   tree6.insert(i);
   }
   
  // REQUIRE(tree.get_count() == 50);
   for (size_t i = 0; i < 50; ++i)
   {
	   tree6.remove(i);
   }
   REQUIRE(tree6.get_count() == 0);
}
