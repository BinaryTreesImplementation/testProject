#include <catch.hpp>

#include "splay.h"

TEST_CASE("insert_root", "[root]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(10);
   REQUIRE(testSplayTree.search(10) == 1);
   REQUIRE(testSplayTree.getCount() == 1);
}

/* 
Insert left child

	   10   		7
	   /	  ->  	 \
	  7				  10
*/

TEST_CASE("Inserting left child", "[ilch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(10);
   testSplayTree.insert(7);
   REQUIRE(testSplayTree.search(10) == 1);
   REQUIRE(testSplayTree.search(7) == 1);
   REQUIRE(testSplayTree.getCount() == 2);
   REQUIRE(testSplayTree.getKey(testSplayTree.getRoot()) == 7 );
}

/* 
Insert right child

		10   		  15
	   	  \    ->    / 
	  	   15		10
*/

TEST_CASE("Inserting right child", "[irch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(10);
   testSplayTree.insert(15);
   REQUIRE(testSplayTree.search(10) == 1);
   REQUIRE(testSplayTree.search(15) == 1);
   REQUIRE(testSplayTree.getCount() == 2);
   REQUIRE(testSplayTree.getKey(testSplayTree.getRoot()) == 15 );
}


/* 
Inserting right child with left brother

	10	  	     15   		  15		     20
	  \   ->    /     ->     /  \    ->     /
	   15 	  10		   10    20		   15
	   									  /	
	  		  	 						 10
*/

TEST_CASE("Inserting right child with left brother", "[ilch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(10);
   testSplayTree.insert(15);
   testSplayTree.insert(20);      
   REQUIRE(testSplayTree.search(10) == 1);
   REQUIRE(testSplayTree.search(15) == 1);      
   REQUIRE(testSplayTree.search(20) == 1);
   REQUIRE(testSplayTree.getCount() == 3);
   REQUIRE(testSplayTree.getKey(testSplayTree.getRoot()) == 20 );
}

/* 
Inserting left child with right brother

	15	  	  10   		  	10	              20
	/   ->      \    ->       \       ->     /
  10    	  	 15		       15		    15
	   							 \ 		   /	
	  		  	 				  20	  10
*/


TEST_CASE("Inserting right child with right parent", "[ilch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(15);
   testSplayTree.insert(10);
   testSplayTree.insert(20);      
   REQUIRE(testSplayTree.search(10) == 1);
   REQUIRE(testSplayTree.search(15) == 1);      
   REQUIRE(testSplayTree.search(20) == 1);
   REQUIRE(testSplayTree.getCount() == 3);
   REQUIRE(testSplayTree.getKey(testSplayTree.getRoot()) == 20 );
}






