#pragma once
#include <string>
#include "list.h"

namespace LeafTest {
	struct Data {
		Data() {
			num = 0;
			str = "";
		}
		Data(int _num, std::string _str) {
			_num = num;
			_str = str;
		}
		int num;
		std::string str;
	};

	struct Tests {
		int TestSize(LeafStruct::CDualLinkedList<Data>& lst) {
			int size = lst.getSize();
			return size;
		}

		void TestClear(LeafStruct::CDualLinkedList<Data>& lst) {
			lst.clear();
		}

		Data TestData(LeafStruct::CDualLinkedList<Data>& lst) {
			LeafStruct::CDualLinkedList<Data>::CIterator it = lst.begin();
			Data data = it.getData();
			return data;
		}
		//pushs
		void TestPushBack(LeafStruct::CDualLinkedList<Data>& lst) {
			Data* data = new Data();
			for (int i = 0; i < 5; i++) {
				data->num = i;
				lst.pushBack(*data);
			}
		}
		void TestPushFront(LeafStruct::CDualLinkedList<Data>& lst) {
			Data* data = new Data();
			for (int i = 0; i < 5; i++) {
				data->num = i;
				lst.pushFront(*data);
			}
		}
		//pops
		Data TestPopFront(LeafStruct::CDualLinkedList<Data>& lst) {
			Data data = lst.popFront();
			return data;
		}
		Data TestPopBack(LeafStruct::CDualLinkedList<Data>& lst) {
			Data data = lst.popBack();
			return data;
		}

		int TestScroll(LeafStruct::CDualLinkedList<Data>& lst) {
			int i = 0;
			for (LeafStruct::CDualLinkedList<Data>::CIterator it = lst.begin(); it.isValid(); ++it) {
				i++;
			}
			return i;
		}

		//erases
		void TestErase(LeafStruct::CDualLinkedList<Data>& lst) {
			LeafStruct::CDualLinkedList<Data>::CIterator it = lst.begin();
			lst.erase(it);
		}
		void TestEraseAndNext(LeafStruct::CDualLinkedList<Data>& lst) {
			LeafStruct::CDualLinkedList<Data>::CIterator it = lst.begin();
			lst.eraseAndNext(it);
		}

	};
}