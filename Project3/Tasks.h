#pragma once
#include "Include.h"
class Tasks
{
public:

	Linkedlist list; // Declare a Linkedlist object as a member of the Tasks class

	void taskAdd();
	void TaskComplete();
	void EditTask();
	void DeleteTask();
	void SearchTask();
	void DisplayTasks();
};