#include <catch.hpp>

#include "splay.h"

TEST_CASE("insert_root", "[root]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(10);
   REQUIRE(*testSplayTree.getKeyRoot() == 10);
   REQUIRE(testSplayTree.getLeftKey(10) == nullptr);
   REQUIRE(testSplayTree.getRightKey(10) == nullptr);
   REQUIRE(testSplayTree.getParentKey(10) == nullptr);
   REQUIRE(testSplayTree.getCount() == 1);
   REQUIRE(testSplayTree.getRoot() != 0);
}

/* 
Insert left child

	   10   	7
	   /	  ->  	 \
	  7		  10
*/

TEST_CASE("Inserting left child", "[ilch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(10);
   testSplayTree.insert(7);
   REQUIRE(*testSplayTree.getKeyRoot() == 7);
   REQUIRE(testSplayTree.getLeftKey(7) == nullptr);
   REQUIRE(*testSplayTree.getRightKey(7) == 10);
   REQUIRE(testSplayTree.getParentKey(7) == nullptr);
   REQUIRE(testSplayTree.getCount() == 2);
   REQUIRE(testSplayTree.getRoot() != 0);
   REQUIRE(testSplayTree.getLeftKey(10) == nullptr);
   REQUIRE(testSplayTree.getRightKey(10) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(10) == 7);
}

/* 
Insert right child

		10   	      15
	   	  \    ->    / 
	  	   15	   10
*/

TEST_CASE("Inserting right child", "[irch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(10);
   testSplayTree.insert(15);
   REQUIRE(*testSplayTree.getKeyRoot() == 15);
   REQUIRE(*testSplayTree.getLeftKey(15) == 10);
   REQUIRE(testSplayTree.getRightKey(15) == nullptr);
   REQUIRE(testSplayTree.getParentKey(15) == nullptr);
   REQUIRE(testSplayTree.getCount() == 2);
   REQUIRE(testSplayTree.getRoot() != 0);
   REQUIRE(testSplayTree.getLeftKey(10) == nullptr);
   REQUIRE(testSplayTree.getRightKey(10) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(10) == 15);
}


/* 
Inserting right child with left brother

	10	     15           15		  20
	  \   ->    /     ->     /  \    ->      /
	   15 	  10	       10    20	       15
	   				      /	
	                                    10
*/

TEST_CASE("Inserting right child with left brother", "[ilch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(10);
   testSplayTree.insert(15);
   testSplayTree.insert(20);      
   REQUIRE(*testSplayTree.getKeyRoot() == 20);
   REQUIRE(*testSplayTree.getLeftKey(20) == 15);
   REQUIRE(testSplayTree.getRightKey(20) == nullptr);
   REQUIRE(testSplayTree.getParentKey(20) == nullptr);
   REQUIRE(testSplayTree.getCount() == 3);
   REQUIRE(testSplayTree.getRoot() != 0);
   REQUIRE(*testSplayTree.getLeftKey(15) == 10);
   REQUIRE(testSplayTree.getRightKey(15) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(15) == 20);
   REQUIRE(testSplayTree.getLeftKey(10) == nullptr);
   REQUIRE(testSplayTree.getRightKey(10) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(10) == 15);
}

/* 
Inserting left child with right brother

	15	   10           10	               20
	/   ->      \    ->       \       ->          /
      10    	    15		  15		    15
	   			    \ 		   /	
	  		  	     20	         10
*/


TEST_CASE("Inserting right child with right parent", "[ilch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(15);
   testSplayTree.insert(10);
   testSplayTree.insert(20);      
   REQUIRE(*testSplayTree.getKeyRoot() == 20);
   REQUIRE(*testSplayTree.getLeftKey(20) == 15);
   REQUIRE(testSplayTree.getRightKey(20) == nullptr);
   REQUIRE(testSplayTree.getParentKey(20) == nullptr);
   REQUIRE(testSplayTree.getCount() == 3);
   REQUIRE(testSplayTree.getRoot() != 0);
   REQUIRE(*testSplayTree.getLeftKey(15) == 10);
   REQUIRE(testSplayTree.getRightKey(15) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(15) == 20);
   REQUIRE(testSplayTree.getLeftKey(10) == nullptr);
   REQUIRE(testSplayTree.getRightKey(10) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(10) == 15);
}

/* 
Inserting left child with left brother

	10	      15             15	         5
	  \    ->    /     ->       /     ->      \
           15	   10		  10		   10
	   			 / 		    \
	  		  	5	             15
*/


TEST_CASE("Inserting left child with left parent", "[ilch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(10);
   testSplayTree.insert(15);
   testSplayTree.insert(5);      
   REQUIRE(*testSplayTree.getKeyRoot() == 5);
   REQUIRE(testSplayTree.getLeftKey(5) == nullptr);
   REQUIRE(*testSplayTree.getRightKey(5) == 10);
   REQUIRE(testSplayTree.getParentKey(5) == nullptr);
   REQUIRE(testSplayTree.getCount() == 3);
   REQUIRE(testSplayTree.getRoot() != 0);
   REQUIRE(testSplayTree.getLeftKey(15) == nullptr);
   REQUIRE(testSplayTree.getRightKey(15) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(15) == 10);
   REQUIRE(testSplayTree.getLeftKey(10) == nullptr);
   REQUIRE(*testSplayTree.getRightKey(10) == 15);
   REQUIRE(*testSplayTree.getParentKey(10) == 5);
}

TEST_CASE("Inserting left child with left parent2", "[ilch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(15);
   testSplayTree.insert(5);
   testSplayTree.insert(10);      
   REQUIRE(*testSplayTree.getKeyRoot() == 10);
   REQUIRE(*testSplayTree.getLeftKey(10) == 5);
   REQUIRE(*testSplayTree.getRightKey(10) == 15);
   REQUIRE(testSplayTree.getParentKey(10) == nullptr);
   REQUIRE(testSplayTree.getCount() == 3);
   REQUIRE(testSplayTree.getRoot() != 0);
   REQUIRE(testSplayTree.getLeftKey(15) == nullptr);
   REQUIRE(testSplayTree.getRightKey(15) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(15) == 10);
   REQUIRE(testSplayTree.getLeftKey(5) == nullptr);
   REQUIRE(testSplayTree.getRightKey(5) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(5) == 10);
}



TEST_CASE("remove root", "[rr]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(15);
   testSplayTree.remove(15);      
   REQUIRE(testSplayTree.getCount() == 0);
   REQUIRE(testSplayTree.getRoot() == nullptr);
}


TEST_CASE("remove right child", "[rrch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(15);
   testSplayTree.insert(10);
   testSplayTree.remove(15);      
   REQUIRE(testSplayTree.getCount() == 1);
   REQUIRE(*testSplayTree.getKeyRoot() == 10);
   REQUIRE(testSplayTree.getLeftKey(10) == nullptr);
   REQUIRE(testSplayTree.getRightKey(10) == nullptr);
   REQUIRE(testSplayTree.getParentKey(10) == nullptr);
}


TEST_CASE("remove left child", "[rlch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(10);
   testSplayTree.insert(15);
   testSplayTree.remove(10);      
   REQUIRE(testSplayTree.getCount() == 1);
   REQUIRE(*testSplayTree.getKeyRoot() == 15);
   REQUIRE(testSplayTree.getLeftKey(15) == nullptr);
   REQUIRE(testSplayTree.getRightKey(15) == nullptr);
   REQUIRE(testSplayTree.getParentKey(15) == nullptr);
}


TEST_CASE("remove left child with left child", "[rllch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(15);
   testSplayTree.insert(10);
   testSplayTree.insert(12);
   testSplayTree.insert(14);
   testSplayTree.remove(12);      
   REQUIRE(testSplayTree.getCount() == 3);
   REQUIRE(*testSplayTree.getKeyRoot() == 10);
   REQUIRE(testSplayTree.getLeftKey(10) == nullptr);
   REQUIRE(*testSplayTree.getRightKey(10) == 14);
   REQUIRE(testSplayTree.getParentKey(10) == nullptr);
   REQUIRE(testSplayTree.getLeftKey(14) == nullptr);
   REQUIRE(*testSplayTree.getRightKey(14) == 15);
   REQUIRE(*testSplayTree.getParentKey(14) == 10);
   REQUIRE(testSplayTree.getLeftKey(15) == nullptr);
   REQUIRE(testSplayTree.getRightKey(15) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(15) == 14);
}


TEST_CASE("remove right child with right child", "[rrrch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(20);
   testSplayTree.insert(12);
   testSplayTree.insert(16);
   testSplayTree.insert(13);
   testSplayTree.remove(16);     
   REQUIRE(testSplayTree.getCount() == 3);
   REQUIRE(*testSplayTree.getKeyRoot() == 13);
   REQUIRE(*testSplayTree.getLeftKey(13) == 12);
   REQUIRE(*testSplayTree.getRightKey(13) == 20);
   REQUIRE(testSplayTree.getParentKey(13) == nullptr);
   REQUIRE(testSplayTree.getLeftKey(12) == nullptr);
   REQUIRE(testSplayTree.getRightKey(12) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(12) == 13);
   REQUIRE(testSplayTree.getLeftKey(20) == nullptr);
   REQUIRE(testSplayTree.getRightKey(20) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(20) == 13);
}

TEST_CASE("remove right child with right and left child", "[rrrch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(20);
   testSplayTree.insert(12);
   testSplayTree.insert(16);
   testSplayTree.insert(13);
   testSplayTree.insert(17);
   testSplayTree.remove(13);     
   REQUIRE(testSplayTree.getCount() == 4);
   REQUIRE(*testSplayTree.getKeyRoot() == 12);
   REQUIRE(testSplayTree.getLeftKey(12) == nullptr);
   REQUIRE(*testSplayTree.getRightKey(12) == 17);
   REQUIRE(testSplayTree.getParentKey(12) == nullptr);
   REQUIRE(*testSplayTree.getLeftKey(17) == 16);
   REQUIRE(*testSplayTree.getRightKey(17) == 20);
   REQUIRE(*testSplayTree.getParentKey(17) == 12);
   REQUIRE(testSplayTree.getLeftKey(20) == nullptr);
   REQUIRE(testSplayTree.getRightKey(20) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(20) == 17);
   REQUIRE(testSplayTree.getLeftKey(16) == nullptr);
   REQUIRE(testSplayTree.getRightKey(16) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(16) == 17);
}


TEST_CASE("remove left child with right and left child", "[rrrch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(20);
   testSplayTree.insert(12);
   testSplayTree.insert(16);
   testSplayTree.insert(13);
   testSplayTree.insert(17);
   testSplayTree.remove(13);     
   REQUIRE(testSplayTree.getCount() == 4);
   REQUIRE(*testSplayTree.getKeyRoot() == 12);
   REQUIRE(testSplayTree.getLeftKey(12) == nullptr);
   REQUIRE(*testSplayTree.getRightKey(12) == 17);
   REQUIRE(testSplayTree.getParentKey(12) == nullptr);
   REQUIRE(*testSplayTree.getLeftKey(17) == 16);
   REQUIRE(*testSplayTree.getRightKey(17) == 20);
   REQUIRE(*testSplayTree.getParentKey(17) == 12);
   REQUIRE(testSplayTree.getLeftKey(20) == nullptr);
   REQUIRE(testSplayTree.getRightKey(20) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(20) == 17);
   REQUIRE(testSplayTree.getLeftKey(16) == nullptr);
   REQUIRE(testSplayTree.getRightKey(16) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(16) == 17);
}


TEST_CASE("search", "[s]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(20);
   testSplayTree.insert(14);
   testSplayTree.insert(16);
   testSplayTree.search(20);
   REQUIRE(testSplayTree.getCount() == 3);
   REQUIRE(*testSplayTree.getKeyRoot() == 20);
   REQUIRE(*testSplayTree.getLeftKey(20) == 16);
   REQUIRE(testSplayTree.getRightKey(20) == nullptr);
   REQUIRE(testSplayTree.getParentKey(20) == nullptr);
   REQUIRE(*testSplayTree.getLeftKey(16) == 14);
   REQUIRE(testSplayTree.getRightKey(16) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(16) == 20);
   REQUIRE(testSplayTree.getLeftKey(14) == nullptr);
   REQUIRE(testSplayTree.getRightKey(14) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(14) == 16);
}
