/*
*Student name Jian Ma
*Student id 1001532967
*course CSE3320-001
*project 01
*/

/*
*source code create by professor David Levine
*update by Jian Ma
*date 09-09-2018
*version 0.1
*/

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <curses.h>
#include <sys/stat.h>

int main(void)
{
	pid_t child;
	DIR *d;
	struct dirent *de;
	int i, c, k;
	char s[256], cmd[256],file[256][1024],dir[256][2048];
	time_t t;
	int num;

	while (1)
	{
		t = time(NULL);
	        printf("TIme: %s\n", ctime(&t));

	        getcwd(s, 200);
	        printf("\nCurrent Directory: %s \n", s);

		d = opendir(".");
		c = 0;

		printf("Files:\n");

		while ((de = readdir(d)))			//	Printing out Files
		{
                        if (((de -> d_type) & DT_REG))
                        {
                                printf("( %d Directory: %s) \n", c++, de->d_name);
			 	strcpy(file[c], de -> d_name);
                        }

		}
		closedir(d);


		d = opendir(".");
		c = 0;

		printf("\nDirectories:\n");

		while ((de = readdir(d)))			//	Printing out Directories
		{
                        if ((de -> d_type) & DT_DIR)
                        {
                                 printf("(%d File: %s) \n", c++, de->d_name);
		      		 strcpy(dir[c], de -> d_name);
                        }

		}
		closedir(d);

		d = opendir(".");
		c = 0;

		printf("\nOperations:\n");

		printf("enter q for quit\nenter e for edit\nenter r for run\nenter c for change\nenter f for remove file\nenter D for display dirctory\nenter s for sort dirctory\nenter a for create directory\n");

		printf("----------------------------------------------\n");
		c = getchar();

		strcpy(cmd, "");

		switch (c)
		{
			case 'q' :	exit(0);			

			case 'e' :	printf("which file you want to edit with?: ");		
					scanf("%d", &num);
					strcpy(s,file[num]);

					strcpy(cmd, "pico ");
					strcat(cmd, s);
					system(cmd);
					break;

			case 'r' : printf("plese enter the program you want to enter(if you want to run this program please enter ./ sign):\n");
				      	scanf("%s",cmd);
				      	system(cmd);
		             		break;

			case 'c':	printf("Which dircotry you want to Change?: ");
					scanf("%d", &num);
					strcpy(cmd, dir[num]);
					chdir(cmd);
					break;

			case 'f' : printf("Which dirctory you want to remove?\n");
				        scanf("%s", cmd);
				        rmdir(cmd);
				        break;

			case 'a':	printf("please enter the directory name\n");
					scanf("%s", cmd);
					mkdir(cmd, d);
					break;
			case 'd' :       break;

		}

	}
}



