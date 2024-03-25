#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added successfully.\n";
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
        } else {
            cout << "Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].description << " - ";
                if (tasks[i].completed) {
                    cout << "Completed\n";
                } else {
                    cout << "Pending\n";
                }
            }
        }
    }

    void markTaskCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed.\n";
        } else {
            cout << "Invalid task index.\n";
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task removed successfully.\n";
        } else {
            cout << "Invalid task index.\n";
        }
    }
};

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    ToDoList myList;
    string choice;
    string taskDesc;
    size_t index;

    do {
        cout << "Menu:\n"
             << "1. Add Task\n"
             << "2. View Tasks\n"
             << "3. Mark Task as Completed\n"
             << "4. Remove Task\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        getline(cin, choice);
        choice = toLower(choice); // Convert to lowercase

        if (choice == "add task") {
            cout << "Enter task description: ";
            getline(cin, taskDesc);
            myList.addTask(taskDesc);
        } else if (choice == "view tasks") {
            myList.viewTasks();
        } else if (choice == "mark task as completed") {
            cout << "Enter task index to mark as completed: ";
            cin >> index;
            myList.markTaskCompleted(index);
        } else if (choice == "remove task") {
            cout << "Enter task index to remove: ";
            cin >> index;
            myList.removeTask(index);
        } else if (choice == "exit") {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining input
    } while (true);

    return 0;
}







