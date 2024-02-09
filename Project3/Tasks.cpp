#define _CRT_SECURE_NO_WARNINGS
#include "Tasks.h"


void Tasks::taskAdd() {

	std::string Name;
	std::string Date;
	std::string Description;

	std::cin.ignore(INT_MAX, '\n');
	std::cout << "\nThe name for the task: ";
	std::getline(std::cin, Name);
	std::cout << std::endl;

	std::cout << "The date you want the task completed by: ";
	std::getline(std::cin, Date);
	std::cout << std::endl;

	std::cout << "Enter a Description for the task you want completed: ";
	std::getline(std::cin, Description);
	std::cout << std::endl;

	std::cout << "Name: " << Name << "\n Date: " << Date << "\n Description: " << Description << std::endl << std::endl;

	list.insertNode(Name, Date, Description);

}

void Tasks::TaskComplete() {
	list.TaskComplete();
}

void Tasks::EditTask() {
	list.EditTask();
}

void Tasks::DeleteTask() {
	list.DeleteTask();
}

void Tasks::SearchTask() {
	list.SearchTask();
}

void Tasks::DisplayTasks() {
	list.displayList();
}