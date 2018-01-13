#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#define VERSION_NUMBER "0.1.0"

char* create_new_note(char* note_name) {
	printf("Generating new list");
	FILE *f_name = fopen(note_name, "a");

	return "Note created successfully";
}

int main(int argc, char* argv[]) {
	int choice;
	while((choice = getopt (argc, argv, "hnucd:")) != -1) {
		switch(choice) {
			case 'h':
				printf("Taskkly version: %s", VERSION_NUMBER);
				printf("\nUsage:");
				printf("taskly command [options] [list_name]");
				printf("-h	Displays the help options");
				printf("-n	Create a new task list");
				printf("-u	Update existing list");
				printf("-c	Complete a task");
				printf("-l	List all existing task lists");
				printf("-d	Delete an existing task or task list");
			case 'n':
				create_new_note(optarg);
			case 'u':
//				update_task_list(optarg);
			case 'c':
//				complete_task(optarg);
			case 'd':
				break;
//				delete_task();
		}
	}
}
