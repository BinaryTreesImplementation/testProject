#include <catch.hpp>

#include "splay.h"

TEST_CASE("insert_root", "[root]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(10);
   REQUIRE(testSplayTree.search(10) == 1);
}

/* 
Insert left child

		10   		7
	   /	  ->  	 \
	  7				  10
*/

TEST_CASE("Insert left child", "[ilch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(10);
   testSplayTree.insert(7);
   REQUIRE(testSplayTree.search(10) == 1);
   REQUIRE(testSplayTree.search(7) == 1);
   REQUIRE(testSplayTree.getKey(testSplayTree.getRoot()) == 7 );
}

/* 
Insert right child

		10   		  15
	   	  \    ->    / 
	  	   15		10
*/

TEST_CASE("Insert right child", "[irch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(10);
   testSplayTree.insert(15);
   REQUIRE(testSplayTree.search(10) == 1);
   REQUIRE(testSplayTree.search(15) == 1);
   REQUIRE(testSplayTree.getKey(testSplayTree.getRoot()) == 15 );
}