#include <unistd.h>
#include <string.h>

int main()
{
	char *message = "Hello world\n";
	write(STDOUT_FILENO, message, strlen(message));
	return (0);
}
