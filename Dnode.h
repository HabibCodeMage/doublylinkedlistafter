#pragma once
#ifndef DNODE_H
#define DNODE_H
#include<string>
using namespace std;
class doublylinked;
class Dnode
{
private:
	
	Dnode* prev;
	Dnode* next;
	string elem;
	friend class doublylinked;
};
#endif // !



