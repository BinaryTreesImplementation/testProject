#include <catch.hpp>

#include "splay.h"
#include "treap.h"
/*
    nullptr     ->      10
*/

TEST_CASE("insert_root", "[root]") {
   Treap<int> testTreap;
   testTreap.Insert(10);
   REQUIRE(*testTreap.getKeyRoot() == 10);
   REQUIRE(testTreap.getLeftKey(10) == nullptr);
   REQUIRE(testTreap.getRightKey(10) == nullptr);
   REQUIRE(testTreap.getCount() == 1);
   REQUIRE(testTreap.getRoot() != 0);
}

/*
if "10" priority > "7" priority
    10     ->      10		
                  /  	
                 7
else 
    10     ->       7
    		     \
		      10
*/
TEST_CASE("Inserting left child", "[ilch]") {
   Treap<int> testTreap;
   testTreap.Insert(10);
   testTreap.Insert(7);
   int root = 7;
   if(*testTreap.getPriority(7) < *testTreap.getPriority(10))
       root = 10;
   REQUIRE(*testTreap.getKeyRoot() == root);
   REQUIRE(testTreap.getCount() == 2);
   REQUIRE(testTreap.getRoot() != 0);
   REQUIRE(testTreap.Search(7) != nullptr);
   REQUIRE(testTreap.Search(10) != nullptr);
}

/*
if "10" priority > "75" priority
    10     ->      10		
                     \ 	
                      75
else 
    10     ->       75
    		   /
		  10
*/
TEST_CASE("Inserting right child", "[irch]") {
   Treap<int> testTreap;
   testTreap.Insert(10);
   testTreap.Insert(75);
   REQUIRE(*testTreap.getKeyRoot() == 75);
   REQUIRE(*testTreap.getLeftKey(75) == 10);
   REQUIRE(testTreap.getRightKey(75) == nullptr);
   REQUIRE(testTreap.getCount() == 2);
   REQUIRE(testTreap.getRoot() != 0);
   REQUIRE(*testTreap.getPriority(75) > *testTreap.getPriority(10)); 
   REQUIRE(testTreap.getLeftKey(10) == nullptr);
   REQUIRE(testTreap.getRightKey(10) == nullptr);
}
/*
if "10" priority > "25" priority > "75" priority
    10     ->      10	   ->     10	
                     \ 	            \
                      75             25
                                       \
		                        75  
if "25" priority < "75" priority < "10" priority 
    10     ->      10	   ->     10	
                     \ 	            \
                      75             75
                                    /  
		                   25
if "10" priority < "25" priority < "75" priority
    10     ->      75	   ->     75	
                   /   	          /
                  10             25   
                                /     
		               10     
if "10" priority < "75" priority < "25" priority
    10     ->      75	   ->     25	
                   / 	           \	
                  10                75
                                   /     
		                 10 
if "75" priority < "10" priority < "25" priority
    10     ->      10	   ->     25	
                     \ 	           \	
                      75            75
                                   /     
		                 10 
if "75" priority < "10" priority < "25" priority
    10     ->      10	   ->     25	
                     \ 	          /	
                      75         10
                                  \     
		                   75
if "25" priority < "10" priority < "75" priority
    10     ->      75	   ->      75	
                   / 	          /	
                  10             10
                                  \   
		                   25 
if "10" priority < "25" priority < "75" priority
    10     ->      75	   ->      75	
                   / 	            \	
                  10                 25
                                     /
		                   10
*/
TEST_CASE("Inserting", "[irch]") {
	Treap<int> testTreap;
	testTreap.Insert(10);
	testTreap.Insert(75);
	testTreap.Insert(25);
	int maxPriority = *testTreap.getPriority(75);
	if(maxPriority < *testTreap.getPriority(10))
   		maxPriority = *testTreap.getPriority(10);
	if(maxPriority < *testTreap.getPriority(25))
		maxPriority = *testTreap.getPriority(25);
    if(maxPriority == *testTreap.getPriority(25))
   	{
  		REQUIRE(*testTreap.getKeyRoot() == 25);
   	}
   	if(maxPriority == *testTreap.getPriority(75))
   	{
   		REQUIRE(*testTreap.getKeyRoot() == 75);
   	}
   	if(maxPriority == *testTreap.getPriority(10))
   	{
   		REQUIRE(*testTreap.getKeyRoot() == 10);
   	}
   	REQUIRE(testTreap.getCount() == 3);
   	REQUIRE(testTreap.Search(75) != nullptr);
   	REQUIRE(testTreap.Search(25) != nullptr);
   	REQUIRE(testTreap.Search(10) != nullptr);
   }

/*
      nullptr  ->    10    ->    nullptr
*/

  TEST_CASE("remove root", "[irch]") {
	Treap<int> testTreap;
	testTreap.Insert(10);
	testTreap.Remove(10);
	REQUIRE(testTreap.getKeyRoot() == nullptr);
	REQUIRE(testTreap.getRoot() == nullptr);
	REQUIRE(testTreap.getCount() == 0);
}
/*
if "10" priority > "11" priority
    10     ->      10	   ->   10	
                     \ 	
                      11
else 
    10     ->       11     ->    11
    		   /
		  10
*/
  TEST_CASE("remove list", "[irch]") {
	Treap<int> testTreap;
	testTreap.Insert(10);
	testTreap.Insert(11);
	
	int removing = 10;
	int root = 11;
	if(*testTreap.getPriority(10) > *testTreap.getPriority(11))
	{
		removing = 11;
		root = 10;
	}
	testTreap.Remove(removing);
	REQUIRE(*testTreap.getKeyRoot() == root);
	REQUIRE(testTreap.getRightKey(root) == nullptr);
	REQUIRE(testTreap.getLeftKey(root) == nullptr);
	REQUIRE(testTreap.getRoot() != nullptr);
	REQUIRE(testTreap.getCount() == 1);
}

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

	10	    15            15		   20
	  \   ->    /     ->     /  \    ->        /
	   15 	   10	       10    20	         15
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

	15	  10             10	               20
	/   ->      \      ->      \       ->         /
      10    	     15		    15		     15
	   			      \             /	
	  		  	       20	   10
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

	10	       15             15	       5
	  \    ->     /     ->       /       ->         \
	   15	    10		   10		         10
	   		          / 		           \
	  		         5	                    15
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

/*
	5				 10
	 \		->		/  \	
	  10		               5   15
*/

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

/*

	15 -> nullptr

*/

TEST_CASE("remove root", "[rr]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(15);
   testSplayTree.remove(15);      
   REQUIRE(testSplayTree.getCount() == 0);
   REQUIRE(testSplayTree.getRoot() == nullptr);
}

/*
	10				
	  \ 	->    10  
	   15
*/

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


/*
	 15			
	/	->	15
      10
*/

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
/*
	    14			10
	   /  \			  \	
	  12   15	-> 	   14	
	 /	   		     \
	10 			      15
*/

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

/*
	    13		       	    13
   	   /  \			   /  \
	 12    16	->	 12    20
 		 \
		  20
*/

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
/*
	    17		       	    12
   	   /  \			      \
	 13    20	  ->	       17
 	/  \	 		      /  \
      12    16	                    16    20
*/
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
/*
	    13		       	    20
   	   /  \			   /  \
	 11    20	->	 13    21
 		 \              /
		  22           11
                 /
	        21
*/
TEST_CASE("remove right child with left child", "[rrrch]") {
   SplayTree<int> testSplayTree;
   testSplayTree.insert(20);
   testSplayTree.insert(21);
   testSplayTree.insert(22);
   testSplayTree.insert(11);
   testSplayTree.insert(13);
   testSplayTree.remove(22);     
   REQUIRE(testSplayTree.getCount() == 4);
   REQUIRE(*testSplayTree.getKeyRoot() == 20);
   REQUIRE(*testSplayTree.getLeftKey(20) == 13);
   REQUIRE(*testSplayTree.getRightKey(20) == 21);
   REQUIRE(testSplayTree.getParentKey(20) == nullptr);
   REQUIRE(*testSplayTree.getLeftKey(13) == 11);
   REQUIRE(testSplayTree.getRightKey(13) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(13) == 20);
   REQUIRE(testSplayTree.getLeftKey(11) == nullptr);
   REQUIRE(testSplayTree.getRightKey(11) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(11) == 13);
   REQUIRE(testSplayTree.getLeftKey(21) == nullptr);
   REQUIRE(testSplayTree.getRightKey(21) == nullptr);
   REQUIRE(*testSplayTree.getParentKey(21) == 20);
}
/*
	16		     20
       /  \       ->         /
     14    20              16
                           /
		         14
*/

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
