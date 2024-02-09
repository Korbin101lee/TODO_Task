#include "Include.h"

void Linkedlist::insertNode(std::string Name, std::string Date, std::string Description) {
	//Create the newNode allocated on the heap.
	Node* newNode = new Node(Name, Date, Description, "No", "");

	//if the node is empty set the head to the newNode;
	if (head == nullptr)
	{
		head = newNode;
		return;
	}
	//creating pointer temp and setting it to the address of head
	Node* temp = head;
	//going through the whole linked list till the head is null(end of list)
	while (temp->next != nullptr) {
		temp = temp->next;//move the pointer to point to the next address in the linked list
	}

	//Insert a node at the end of the list.
	temp->next = newNode;
}

void Linkedlist::TaskComplete() {
	Node* current = head;
	if (head == nullptr) {
		std::cout << "\nList is Empty\n" << std::endl;
		return;
	}
	std::string Name;
	char buffer[80];

	auto time = std::chrono::system_clock::now();
	std::time_t currentTime = std::chrono::system_clock::to_time_t(time);
	ctime_s(buffer, sizeof(buffer), &currentTime);

	std::cin.ignore(INT_MAX, '\n');
	std::cout << "Enter the name of the task completed: ";
	std::getline(std::cin, Name);
	std::cout << std::endl;

	while (current != nullptr) {
		if (current->name == Name) {
			current->TaskComplete = "Yes";
			current->TaskCompletedBy = buffer;
			std::cout << "The task: " << Name << " Marked Completed on: " << buffer << std::endl;
			break;
		}
		current = current->next;
	}
}

void Linkedlist::EditTask() {
	Node* current = head;
	std::string SearchName;
	std::string NewTaskName;
	std::string NewTaskCompleteDate;
	std::string NewTaskDescription;

	char buffer[80];
	auto time = std::chrono::system_clock::now();
	std::time_t currentTime = std::chrono::system_clock::to_time_t(time);
	ctime_s(buffer, sizeof(buffer), &currentTime);

	int Completed = 0;
	if (head == nullptr) {
		std::cout << "\nList is Empty\n" << std::endl;
		return;
	}
	std::cin.ignore(INT_MAX, '\n');
	std::cout << "Enter the Current Name of the Task" << std::endl;
	std::getline(std::cin, SearchName);
	std::cout << std::endl;

	while (current != nullptr) {
		if (current->name == SearchName) {
			std::cout << "Edit Task Name :" << std::endl;
			std::getline(std::cin, NewTaskName);
			std::cout << "New Task Complete Date: " << std::endl;
			std::getline(std::cin, NewTaskCompleteDate);
			std::cout << "New Task Description: " << std::endl;
			std::getline(std::cin, NewTaskDescription);
			std::cout << "Enter 1 if task Completed or 2 if not" << std::endl;
			std::cin >> Completed;
			if (Completed == 1) {
				current->TaskComplete = "Yes";
				current->TaskCompletedBy = buffer;
			}
			else if (Completed == 2) {
				current->TaskComplete = "No";
				current->TaskCompletedBy = "";
			}
			current->name = NewTaskName;
			current->dateToComplete = NewTaskCompleteDate;
			current->description = NewTaskDescription;

			std::cout << std::endl;
			std::cout << "Name: " << current->name;
			std::cout << "   Date to Complete: " << current->dateToComplete;
			std::cout << "   Completed: " << current->TaskComplete;
			std::cout << "   Date Completed: " << current->TaskCompletedBy << std::endl;
			std::cout << "Description: " << current->description << std::endl;
			std::cout << std::endl;
		}
		current = current->next;
	}

}

void Linkedlist::SearchTask() {
	Node* current = head;
	std::string SearchName;
	if (head == nullptr) {
		std::cout << "\nList is Empty\n" << std::endl;
		return;
	}
	std::cin.ignore(INT_MAX, '\n');
	std::cout << "Enter the Name of the Task" << std::endl;
	std::getline(std::cin, SearchName);
	std::cout << std::endl;
	while (current != nullptr) {
		if (current->name == SearchName) {
			std::cout << "Name: " << current->name;
			std::cout << "   Date to Complete: " << current->dateToComplete;
			std::cout << "   Completed: " << current->TaskComplete;
			std::cout << "   Date Completed: " << current->TaskCompletedBy << std::endl;
			std::cout << "Description: " << current->description << std::endl;
			std::cout << std::endl;
			break;
		}
		current = current->next;
	}
}

void Linkedlist::DeleteTask() {
	Node* current = head;
	Node* prev = nullptr;
	std::string DeleteName;
	if (head == nullptr) {
		std::cout << "\nList is Empty\n" << std::endl;
		return;
	}
	std::cin.ignore(INT_MAX, '\n');
	std::cout << "Enter the Name of the Task" << std::endl;
	std::getline(std::cin, DeleteName);
	
	while (current != nullptr && current->name != DeleteName) {
		prev = current;
		current = current->next;
	}
	if (current != nullptr) {
		if (prev == nullptr) {
			head = current->next;
		}
		else {
			prev->next = current->next;
		}
		delete current;
		std::cout << "Task with name: " << DeleteName << "Was Delete" << std::endl;
	}
	

}

void Linkedlist::displayList() {
	Node* current = head;
	if (head == nullptr) {
		std::cout << "\nList is Empty\n" << std::endl;
		return;
	}
	std::cout << std::endl;
	while (current != nullptr) {
		std::cout << "Name: " << current->name;
		std::cout << "   Date to Complete: " << current->dateToComplete;
		std::cout << "   Completed: " << current->TaskComplete;
		std::cout << "   Date Completed: " << current->TaskCompletedBy << std::endl;
		std::cout << "Description: " << current->description << std::endl;

		current = current->next;
		std::cout << std::endl;
	}
}
