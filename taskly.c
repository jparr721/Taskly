#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>



void handle_flags(int in_length, char* input[]) {
	int choice;
	while((choice = getopt (argc, argv, "hnucd:")) != -1)
		switch(input[i]) {
			case '-h':
				printf("Usage:");
				printf("taskly command [options] [list_name]");
				printf("-h	Displays the help options");
				printf("-n	Create a new task list");
				printf("-u	Update existing list");
				printf("-c	Complete a task");
				printf("-d	Delete an existing task or task list");
			case 'n':
				create_new_note(optarg);
			case 'u':
				update_task_list(optarg);
			case 'c':
				complete_task(optarg);
			case 'd':
				delete_task
		}
	}
}

int main(int argc, char* argv[]) {
	handle_flags(argc, argv[]);
}
