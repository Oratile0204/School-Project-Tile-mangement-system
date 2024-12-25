// School Project Tile mangement system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Task structure to hold individual task details.
struct Task {
    int id;
    string description;
    string priority;
};

// Function prototypes
void addTask(vector<Task>& tasks);
void displayTasks(const vector<Task>& tasks);
void searchTasksByPriority(const vector<Task>& tasks);
void countTasksByPriority(const vector<Task>& tasks);

int main() {
    vector<Task> tasks; // This Vector is used  to store tasks
    int choice;

    do {
        cout << "\nTask Management System" << endl;
        cout << "1. Add a new task" << endl;
        cout << "2. Display all tasks" << endl;
        cout << "3. Search tasks by priority" << endl;
        cout << "4. Count tasks by priority" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addTask(tasks);
            break;
        case 2:
            displayTasks(tasks);
            break;
        case 3:
            searchTasksByPriority(tasks);
            break;
        case 4:
            countTasksByPriority(tasks);
            break;
        case 5:
            cout << "Exiting Task Management System. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new task
void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "\nEnter Task ID: ";
    cin >> newTask.id;
    cin.ignore(); // Clear the input buffer
    cout << "Enter Task Description: ";
    getline(cin, newTask.description);
    cout << "Enter Task Priority (Low, Medium, High): ";
    cin >> newTask.priority;
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

// Function to display all tasks
void displayTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks to display." << endl;
        return;
    }
    cout << "\nTask List:" << endl;
    for (const auto& task : tasks) {
        cout << "ID: " << task.id << " | Description: " << task.description << " | Priority: " << task.priority << endl;
    }
}

// Function to search tasks by priority
void searchTasksByPriority(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks to search." << endl;
        return;
    }
    string priority;
    cout << "\nEnter priority to search (Low, Medium, High): ";
    cin >> priority;

    cout << "\nTasks with priority '" << priority << "':" << endl;
    bool found = false;
    for (const auto& task : tasks) {
        if (task.priority == priority) {
            cout << "ID: " << task.id << " | Description: " << task.description << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No tasks found with the specified priority." << endl;
    }
}

// Function to set and count tasks by priority
void countTasksByPriority(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks to count." << endl;
        return;
    }
    int low = 0, medium = 0, high = 0;
    for (const auto& task : tasks) {
        if (task.priority == "Low") {
            low++;
        }
        else if (task.priority == "Medium") {
            medium++;
        }
        else if (task.priority == "High") {
            high++;
        }
    }
    cout << "\nTask counts by priority:" << endl;
    cout << "Low: " << low << " | Medium: " << medium << " | High: " << high << endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
