#pragma once

#include <ncurses.h>

namespace Taskly {
	class Task {
	public:
		Task();
		~Task();
		void generate_task_window(int height, int width, int starty, int startx);
		void destroy_window(WINDOW *local_window);
	};
}