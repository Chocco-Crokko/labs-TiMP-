#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 1024

int main()
{
	int res = 0, count = 0;
	char cur_str[MAX_STRING];
	char *out_str, *temp;
	FILE * file;
	file = fopen("file.txt", "r");
	if (file)
	{
		while (fgets(cur_str, MAX_STRING, file))
		{
			if (out_str = strstr(cur_str, "\\func"))
			{
				out_str += strlen("\\func ");
				if (temp = strstr(out_str, "*/"))
					*temp = '\0';
				if (!strstr(out_str, "\n"))
					strcat(out_str, "\n");
				printf("%d. %s", ++count, out_str);
			}
		}
		fclose(file);
	}
	else
		res = 1;
	return res;
}