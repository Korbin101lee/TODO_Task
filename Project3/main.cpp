#include "Include.h"

void tasks()
{
}

int main()
{
	int choice = 0;
	Tasks taskAddInstance;
	std::cout << "Welcome to my project made by Korbin Hillan." << std::endl;
	std::cout << "This program is a To Do list maker." << std::endl;
	std::cout << "Some features is adding in tasks, marking tasks as complete" << std::endl;
	std::cout << "Editing tasks and deleting tasks also searching for the task with the task name\n" << std::endl;
	while (true)
	{
		std::cout << "1: Add Task" << std::endl;
		std::cout << "2: Mark Task As Complete" << std::endl;
		std::cout << "3: Edit Task" << std::endl;
		std::cout << "4: Search Task" << std::endl;
		std::cout << "5: Delete Task" << std::endl;
		std::cout << "6: Display Tasks" << std::endl;
		std::cout << "7 Exit Program" << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			taskAddInstance.taskAdd();
			break;
		case 2:
			taskAddInstance.TaskComplete();
			break;
		case 3:
			taskAddInstance.EditTask();
			break;
		case 4:
			taskAddInstance.SearchTask();
			break;
		case 5:
			taskAddInstance.DeleteTask();
			break;
		case 6:
			taskAddInstance.DisplayTasks();
			break;
		case 7:
			return 0;
			break;
		default:
			std::cout << "Entered a non valid input please enter a number from 1-5" << std::endl;
			break;
		}
	}

	
	std::cin.get();
	return 0;
}