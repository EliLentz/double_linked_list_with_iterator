// testing_list_r.cpp : Этот файл содержит функцию "main"
#include <iostream>
#include "test.h"

#include "list.h"

using namespace std;

void Test(LeafStruct::CDualLinkedList<LeafTest::Data> lst) {
	LeafTest::Tests tst;
	LeafTest::Data data;

	int size;

	tst.TestPushBack(lst);
	tst.TestPushFront(lst);

	size = tst.TestSize(lst);
	cout << size << endl;

	for (int i = 0; i < 5; i++)
	{
		data = tst.TestPopBack(lst);
	}

	size = tst.TestSize(lst);
	cout << size << endl;

	tst.TestPushFront(lst);
	tst.TestPushBack(lst);

	for (int i = 0; i < 10; i++)
	{
		data = tst.TestPopFront(lst);
	}

	size = tst.TestSize(lst);
	cout << size << endl;

	tst.TestClear(lst);

	size = tst.TestSize(lst);
	cout << size << endl << endl;

	tst.TestPushBack(lst);
	int i = tst.TestScroll(lst);
	cout << i << endl;

	tst.TestErase(lst);
	i = tst.TestSize(lst);
	cout << i << endl;

	tst.TestEraseAndNext(lst);
	i = tst.TestScroll(lst);
	cout << i << endl << endl;

	data = tst.TestData(lst);
	cout << data.num << "	" << data.str << endl << endl;
}

int main()
{
	LeafStruct::CDualLinkedList<LeafTest::Data> list1;
	LeafStruct::CDualLinkedList<LeafTest::Data> list2;

	Test(list1);
	Test(list2);

	return 0;
}