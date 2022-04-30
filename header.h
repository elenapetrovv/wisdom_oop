#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class wisdom {
public:
	// �������������, ���������� � ���� ������ �� ������
	static wisdom* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0; // ����
	virtual void Out(ofstream& ofst) = 0; // �����
	virtual int CountSymbols() = 0;
};
class Node {
public:
	wisdom* thought;
	Node* next;
	Node* prev;
	Node(wisdom* newfigure);
	//~Node() {}
};
// �������
class aphorism : public wisdom {
	string text; // �����
	string author; // �����
public:
	// �������������� ��������� ������
	void InData(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	int CountSymbols();
	aphorism() {} // �������� ��� �������������.
};
// ���������
class saying : public wisdom {
	string text; // �����
	string country; // ������
public:
	// �������������� ��������� ������
	void InData(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	int CountSymbols();
	saying() {} // �������� ��� �������������.
};
class container {
public:
	Node* current;
	int size;
	Node* head;

	void In(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	void OutCountOfSymbols(ofstream& ofst);
	void Clear(); // ������� ���������� �� �����
	container(); // ������������� ����������
	~container() { Clear(); } // ���������� ����������
};