#include <stdio.h>
#include <time.h>

#define ACCESS_PATH "access.txt"
/***
* This is the path where the access file is located.
* When you submit the program make sure this path match to: "c:\\temp\\access.txt"
***/

#define LOG_PATH "log.txt"
/***
* This is the path where the log file is located.
* Open this file and append new records into it.
* When you submit the program make sure this path match to: "c:\\temp\\log.txt"
***/

void readAccess(char *path);
/***
* Handle function: get's the path of the access file, and print all users information.
* You may change it according to your needs.
***/

void getDateTime(int *day, int *month, int *year, int *hours, int *mins);
/***
* Handle function: Returns by referfance the current date and time
***/



void readAccess(char *path)
{
	FILE *fp;
	int status, pulse;
	char temp[100], name[21], code[9], date_s[11], date_e[11], time_s[6], time_e[6];

	fp = fopen( path, "r");
	if (!fp)
	{
		printf("File not found!\n");
		return;
	}

	//header
	fgets(temp, 100, fp);
	puts(temp);

	while (fscanf(fp, "%20s %8s %1d %10s %10s %5s %5s %5d", name, code, &status, date_s, date_e, time_s, time_e, &pulse) != EOF)
	{
		printf("%-20s %-8s %-1d %-10s %-10s %-5s %-5s %-5d\n", name, code, status, date_s, date_e, time_s, time_e, pulse);
	}

	fclose(fp);
	return;
}


void getDateTime(int *day, int *month, int *year, int *hours, int *mins)
{
	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime( &rawtime);

	*day = timeinfo->tm_mday;
	*month = timeinfo->tm_mon + 1;
	*year = timeinfo->tm_year + 1900;
	*hours = timeinfo->tm_hour;
	*mins = timeinfo->tm_min;
}
