#include <Taskly/task.hpp>
#include <iostream>

namespace Taskly {
	Task::Task() {}

	Task::~Task() {}

	void Task::generate_task_window(int height, int width, int startx, int starty) {
		std::cout << "Get money." << std::endl;
	}
}