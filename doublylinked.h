#pragma once
#ifndef DOUBLYLINKED_H
#define DOUBLYLINKED_H
#include<iostream>
using namespace std;
#include"Dnode.h"
class doublylinked
{
private:
	Dnode* header;
	Dnode* trailer;
	Dnode* cursor;
public:
	doublylinked()
	{
		header = new Dnode;
		trailer = new Dnode;
		header->next = trailer;
		trailer->prev = header;
		header->prev = trailer;
		trailer->next =header;
		cursor=header;
	}
	bool empty()
	{
		return(header->next == trailer);
	}
	void addfront(const string& e)
	{
		addnodebefore(header->next,e);
		/*Dnode* temp = new Dnode;
		temp->elem = e;
		header->next->prev = temp;
		temp->next = header->next;
		temp->prev = header;
		header->next = temp;*/
	}
	void addnodebefore(Dnode* v, const string e)
	{
	
		Dnode* temp = new Dnode;
		temp->elem = e;
		v->prev->next = temp;
		temp->prev = v->prev;
		temp->next = v;
		v->prev = temp;
	}
	void deletenode(const string& e)
	{
		if (empty()) { cout << "empty linked list\n"; return; }
		Dnode* head = header->next;
		while (head->next!=NULL && _stricmp(head->elem.c_str(),e.c_str())!=0)
		{
			head=head->next;
		}
		if (head)
		{
			head->prev->next = head->next;
			head->next->prev = head->prev;
			delete head;
		}
		else
		{
			cout << "No element found\n";
		}
	}
	void advancecursor()
	{
		if (cursor==header)
		{
			cursor = header->next->next;
		}
		else if (cursor == trailer)
		{
			cursor = header->next->next;
		}
		else
		{
			cursor = cursor->next;
		}
	}
	string getatfront()
	{
		
		if (!(empty()))
		{
			if (cursor == header ) 
			{
				advancecursor();
			}
			return cursor->next->elem;
		}
	}
	void addend(const string& e)
	{

		Dnode* temp = new Dnode;
		temp->elem = e;
		trailer->prev->next = temp;
		temp->prev = trailer->prev;
		temp->next = trailer;
		trailer->prev = temp;
	}
	void print()
	{
		Dnode* head = header->next;
		while (head->next!=header)
		{
			cout << head->elem << endl;
			head = head->next;
		}
	}

	~doublylinked()
	{
		Dnode* head = header->next;
		while (head->next!= header)
		{
			Dnode* temp=head;
			head = head->next;
			delete temp;
			
		}
		delete header;
		delete trailer;
	}

};
#endif // !DOUBLYLINKED_H


