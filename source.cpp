#include "Header.h"
#include <string>
void saying::InData(ifstream& ifst) {
	ifst >> country;
}
void saying::Out(ofstream& ofst) {
	ofst << "It is a saying. Country: " << country << endl;
}
int wisdom::CountSymbols() {
	string symbols = ".,!?;";
	int cnt = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (symbols.find(text[i]) < symbols.length())cnt++;
	}
	return cnt;
}
void saying::OutAphorisms(ofstream& ofst)
{
	ofst << endl;
}

void aphorism::InData(ifstream& ifst) {
	ifst >> author;
}
void aphorism::Out(ofstream& ofst) {
	ofst << "It is an aphorism. Author: " << author << endl;
}

void riddle::InData(ifstream& ifst) {
	ifst >> answer;
}
void riddle::Out(ofstream& ofst) {
	ofst << "It is a riddle. Answer: " << answer << endl;
}

void riddle::OutAphorisms(ofstream& ofst)
{
	ofst << endl;
}
void aphorism::OutAphorisms(ofstream& ofst)
{
	ofst << "Text: " << text << endl;
	Out(ofst);
	ofst << "Subjective assessment of the riddle on a ten-point scale: " << rate << "/10 " << endl;
	ofst << "count of punctuation marks: " << CountSymbols() << endl;
}

wisdom* wisdom::In(ifstream& ifst) {
	wisdom* sh;
	int k;
	ifst >> k;
	switch (k) {
	case 1:
		sh = new aphorism;
		break;
	case 2:
		sh = new saying;
		break;
	case 3:
		sh = new riddle;
		break;
	default:
		return 0;
	}
	ifst >> sh->text;
	sh->InData(ifst);
	ifst >> sh->rate;
	return sh;
}

Node::Node(wisdom* newthought)
{
	thought = newthought;
	next = NULL;
	prev = NULL;
}
container::container()
{
	current = NULL;
	head = NULL;
	size = 0;
}
void container::Clear() {
	current = NULL;
	head = NULL;
	size = 0;
}

void container::In(ifstream& ifst) {
	while (!ifst.eof())
	{
		Node* newNode;
		newNode = new Node((wisdom::In(ifst)));
		if (head == NULL)
		{
			head = newNode;
			head->next = newNode;
			head->prev = newNode;
			size = 1;
		}
		else
		{
			current = head;

			while (current->next != head)
			{
				current = current->next;
			}
			current->next = newNode;
			current->next->prev = current;
			current = current->next;
			current->next = head;
			head->prev = current;

			size++;
		}
	}
}
void container::Out(ofstream& ofst) {
	ofst << "Container contents " << size
		<< " elements." << endl;
	int i = 1;
	if (head == NULL)
	{
		return;
	}
	//Sort();
	current = head;
	do
	{
		ofst << i << ": ";
		ofst << "Text: " << current->thought->text << endl;
		current->thought->Out(ofst);
		ofst << "Subjective assessment of the riddle on a ten-point scale: " << current->thought->rate << "/10 " << endl;
		OutCountOfSymbols(ofst);
		current = current->next;
		i++;
	} while (current != head);
	ofst << endl << "Sorted container" << endl;
	Sort();
	current = head;
	do
	{
		ofst << i << ": ";
		ofst << "Text: " << current->thought->text << endl;
		current->thought->Out(ofst);
		ofst << "Subjective assessment of the riddle on a ten-point scale: " << current->thought->rate << "/10 " << endl;
		OutCountOfSymbols(ofst);
		current = current->next;
		i++;
	} while (current != head);
}

bool wisdom::Compare(wisdom& w)
{
	return CountSymbols() < w.CountSymbols();
}

void container::OutCountOfSymbols(ofstream& ofst)
{
	ofst << "count of punctuation marks: " << current->thought->CountSymbols() << endl;
}

void container::Sort()
{
	Node* curr1 = head;
	Node* curr2 = head;
	do {
		curr2 = curr1->next;
		while (curr2 != head) {
			if (curr1->thought->Compare(*curr2->thought))
			{
				swap(curr1->thought, curr2->thought);
			}
			curr2 = curr2->next;
		}
		curr1 = curr1->next;
	} while (curr1 != head);
}

void container::OutAphorisms(ofstream& ofst) {
	int i = 1;
	if (head == NULL)
	{
		return;
	}
	current = head;
	do
	{
		ofst << i << ": ";
		if (current->thought)current->thought->OutAphorisms(ofst);
		current = current->next;
		i++;
	} while (current != head);
}
bool fileCheck(ifstream& ifst, ofstream& ofst)
{
	bool result = true;
	string digits = "0123456789";
	char tmp[100];
	string tmps;

	if (!ifst.is_open())
	{
		cout << "Input file was not found.";
		exit(1);
	}
	if (!ofst.is_open())
	{
		cout << "Output file was not found.";
		exit(1);
	}
	int cnt = 1;
	//type check
	while (!ifst.eof())
	{
		ifst.getline(tmp, 100, '\n');
		tmps = (tmp);
		if (tmps == "")
		{
			cout << cnt << " Error: Type is a blank string.\n";
			result = false;
			exit(1);
		}
		for (int i = 0; i < tmps.length(); i++)
		{
			if (!(digits.find(tmps[i]) < digits.length()))
			{
				cout << cnt << " Error: Type definition contains incorrect characters.\n";
				result = false;
				exit(1);
			}
		}
		int type = std::stoi(tmps);
		if (type <= 0 || type > 3)
		{
			cout << cnt << " Error: Type is out of range.\n";
			result = false;
			exit(1);
		}
		//
		//text
		ifst.getline(tmp, 100, '\n');
		tmps = (tmp);
		if (tmps == "")
		{
			cout << cnt << " Error: Text is a blank string.\n";
			result = false;
			exit(1);
		}
		//
		//for different types
		switch (type)
		{
		case 1:
		{
			//aphorism - author
			ifst.getline(tmp, 100, '\n');
			tmps = (tmp);
			if (tmps == "")
			{
				cout << cnt << " Error: The aphorism's author is a blank string.\n";
				result = false;
				exit(1);
			}
			for (int i = 0; i < tmps.length(); i++)
			{
				if (tmps[i] >= '0' && tmps[i] <= '9')
				{
					cout << cnt << " Error: The aphorism's author contains incorrect characters.\n";
					result = false;
					exit(1);
				}
			}
			break;
		}
		case 2:
		{
			//saying - country
			ifst.getline(tmp, 100, '\n');
			tmps = (tmp);
			if (tmps == "")
			{
				cout << cnt << " Error: The country is a blank string.\n";
				result = false;
				exit(1);
			}
			for (int i = 0; i < tmps.length(); i++)
			{
				if (tmps[i] >= '0' && tmps[i] <= '9')
				{
					cout << cnt << " Error: The saying's country contains incorrect characters.\n";
					result = false;
					exit(1);
				}
			}
			break;
		}
		case 3:
		{
			// riddle - answer
			ifst.getline(tmp, 100, '\n');
			tmps = (tmp);
			if (tmps == "")
			{
				cout << cnt << " Error: The answer is a blank string.\n";
				result = false;
				exit(1);
			}
			for (int i = 0; i < tmps.length(); i++)
			{
				if (tmps[i] >= '0' && tmps[i] <= '9')
				{
					cout << cnt << " Error: The riddle's answer contains incorrect characters.\n";
					result = false;
					exit(1);
				}
			}
			break;
		}
		}
		//
		//rate
		ifst.getline(tmp, 100, '\n');
		tmps = (tmp);
		if (tmps == "")
		{
			cout << cnt << " Error: The rate is a blank string.\n";
			result = false;
			exit(1);
		}
		for (int i = 0; i < tmps.length(); i++)
		{
			if (!(digits.find(tmps[i]) < digits.length()))
			{
				cout << cnt << " Error: The origin contains incorrect characters.\n";
				result = false;
				exit(1);
			}
		}
		int rate = std::stoi(tmps);
		if (rate < 0 || rate > 10)
		{
			cout << cnt << " Error: The rate is out of range.\n";
			result = false;
			exit(1);
		}
		//
		cnt++;
	}
	return result;
}