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
	bool Compare(wisdom& p);
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
	int rate;
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
	int rate;
public:
	// �������������� ��������� ������
	void InData(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	int CountSymbols();
	saying() {} // �������� ��� �������������.
};
class riddle : public wisdom {
	string text; // �����
	string answer; // �����
	int rate;
public:
	// �������������� ��������� ������
	void InData(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	riddle() {} // �������� ��� �������������.
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
	void Sort();
	container(); // ������������� ����������
	~container() { Clear(); } // ���������� ����������
};