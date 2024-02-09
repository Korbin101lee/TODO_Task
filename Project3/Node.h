#pragma once
#include "Include.h"

//a node to the linked list
class Node {
public:
	std::string name;
	std::string dateToComplete;
	std::string description;
	std::string TaskComplete;
	std::string TaskCompletedBy;
	Node* next;

	Node()
	{
		name = "";
		dateToComplete = "";
		description = "";

		next = NULL;
	}

	// Parameterised Constructor 
	Node(std::string Name, std::string Date, std::string Description, std::string TaskComplete, std::string TaskCompletedBy)
	{
		this->name = Name;
		this->dateToComplete = Date;
		this->description = Description;
		this->TaskComplete = TaskComplete;
		this->TaskCompletedBy = TaskCompletedBy;
		this->next = NULL;
	}
};

class Linkedlist {
	Node* head;

public:
	// Default constructor
	Linkedlist() { 
	head = nullptr;
	}

	//Function to insert a node at the end of the linked list
	void insertNode(std::string Name, std::string Date, std::string Description);
	void displayList();
	void TaskComplete();
	void SearchTask();
	void EditTask();
	void DeleteTask();
};