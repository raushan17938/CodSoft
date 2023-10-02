#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        Task task;
        task.description = description;
        task.completed = false;
        tasks.push_back(task);
        cout << "Task added: " << description << endl;
    }

    void viewTasks() {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed)
                cout << "[X] ";
            else
                cout << "[ ] ";
            cout << tasks[i].description << endl;
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed: " << tasks[index - 1].description << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            cout << "Task removed: " << tasks[index - 1].description << endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    TodoList todoList;

    while (true) {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore();  // Clear the newline character from the input buffer

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                string description;
                getline(cin, description);
                todoList.addTask(description);
                break;
            }
            case 2: {
                todoList.viewTasks();
                break;
            }
            case 3: {
                cout << "Enter the task number to mark as completed: ";
                size_t index;
                cin >> index;
                todoList.markTaskAsCompleted(index);
                break;
            }
            case 4: {
                cout << "Enter the task number to remove: ";
                size_t index;
                cin >> index;
                todoList.removeTask(index);
                break;
            }
            case 5: {
                cout << "Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}





























/*


This program provides a simple menu-driven interface for managing tasks in a to-do list. Users can add tasks, view tasks with their statuses, mark tasks as completed, and remove tasks from the list.

*/

