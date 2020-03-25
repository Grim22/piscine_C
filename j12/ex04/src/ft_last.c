#include "header.h"
#include <stdio.h>

int main()
{
	struct utmp utmp;
	int fd;

	fd = open("/var/log/wtmp", O_RDONLY);
	printf("%d\n", fd);
	printf("%s\n", utmp.ut_user);
	printf("%s\n", utmp.ut_id);
}
