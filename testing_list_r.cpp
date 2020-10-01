// testing_list_r.cpp
#include <iostream>
#include "test.h"

#include "list.h"

using namespace std;

void Test(LeafStruct::CDualLinkedList<LeafTest::Data> lst) {
	LeafTest::Tests tst;
	LeafTest::Data data;

	int size;
	
	//fill in the leaf 10 elements. 5 elements at the end and 5 at the beginning(10)
	tst.TestPushBack(lst);
	tst.TestPushFront(lst);
	
	//display quanity of elements (10)
	size = tst.TestSize(lst);
	cout << size << endl;
	
	//get out 5 elements from end(5)
	for (int i = 0; i < 5; i++)
	{
		data = tst.TestPopBack(lst);
	}
	
	//display quanity of elements(5)
	size = tst.TestSize(lst);
	cout << size << endl;

	//fill in the leaf 10 elements. 5 elements at the end and 5 at the beginning (15)
	tst.TestPushFront(lst);
	tst.TestPushBack(lst);
	
	//get out 5 elements from beginnig(10)
	for (int i = 0; i < 10; i++)
	{
		data = tst.TestPopFront(lst);
	}
	
	//display this elements (10)
	size = tst.TestSize(lst);
	cout << size << endl;
	
	//clear all this leaf
	tst.TestClear(lst);
	
	//display quanity of elements (0)
	size = tst.TestSize(lst);
	cout << size << endl << endl;
	
	//fill in the leaf 5 lements at the end and display quanity of elements with iterator(5)
	tst.TestPushBack(lst);
	int i = tst.TestScroll(lst);
	cout << i << endl;
	
	//delete from begin and display quanity of elements(4)
	tst.TestErase(lst);
	i = tst.TestSize(lst);
	cout << i << endl;
	
	//delete from and display quanity of elements(3)
	tst.TestEraseAndNext(lst);
	i = tst.TestScroll(lst);
	cout << i << endl << endl;
	
	//display current element
	data = tst.TestData(lst);
	cout << data.num << "	" << data.str << endl << endl;
}

int main()
{
	//create 2 leafs
	LeafStruct::CDualLinkedList<LeafTest::Data> list1;
	LeafStruct::CDualLinkedList<LeafTest::Data> list2;

	Test(list1);
	Test(list2);

	return 0;
}
