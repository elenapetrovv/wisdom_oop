#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class wisdom {
public:
	string text; // �����
	int rate;
	// �������������, ���������� � ���� ������ �� ������
	static wisdom* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0; // ����
	virtual void Out(ofstream& ofst) = 0; // �����
	int CountSymbols();
	bool Compare(wisdom& p);
	virtual void OutAphorisms(ofstream& ofst) = 0;
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
	string author; // �����
public:
	// �������������� ��������� ������
	void InData(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	void OutAphorisms(ofstream& ofst);
	aphorism() {} // �������� ��� �������������.
};
// ���������
class saying : public wisdom {
	string country; // ������
public:
	// �������������� ��������� ������
	void InData(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	void OutAphorisms(ofstream& ofst);
	saying() {} // �������� ��� �������������.
};
class riddle : public wisdom {
	string answer; // �����
public:
	// �������������� ��������� ������
	void InData(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	void OutAphorisms(ofstream& ofst);
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
	void OutAphorisms(ofstream& ofst);
	void Clear(); // ������� ���������� �� �����
	void Sort();
	container(); // ������������� ����������
	~container() { Clear(); } // ���������� ����������
};