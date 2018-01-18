#include <iostream>
#include <Taskly/view.hpp>
#include <Taskly/task.hpp>

int main(int argc, char* argv[]) {
	Taskly::Task taskWindow;
	taskWindow.generate_task_window(1, 1, 1, 1);
	return 1;
}