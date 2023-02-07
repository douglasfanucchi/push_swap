#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int argc, char **argv, char **envp)
{
	char	permutations[24][4] = {
		'0', '1', '2', '3',
		'0', '1', '3', '2',
		'0', '2', '1', '3',
		'0', '2', '3', '1',
		'0', '3', '1', '2',
		'0', '3', '2', '1',
		'1', '0', '2', '3',
		'1', '0', '3', '2',
		'1', '2', '0', '3',
		'1', '2', '3', '0',
		'1', '3', '0', '2',
		'1', '3', '2', '0',
		'2', '0', '1', '3',
		'2', '0', '3', '1',
		'2', '1', '0', '3',
		'2', '1', '3', '0',
		'2', '3', '0', '1',
		'2', '3', '1', '0',
		'3', '0', '1', '2',
		'3', '0', '2', '1',
		'3', '1', '0', '2',
		'3', '1', '2', '0',
		'3', '2', '0', '1',
		'3', '2', '1', '0',
	};

	int fd = open("out", O_CREAT | O_RDWR | O_APPEND);

	for(int i = 0; i < 24; i++)
	{
		char **args = calloc(sizeof(char *), 6);
		args[0] = calloc(sizeof(char), 255);
		args[1] = calloc(sizeof(char), 255);
		args[2] = calloc(sizeof(char), 255);
		args[3] = calloc(sizeof(char), 255);
		args[4] = calloc(sizeof(char), 255);
		args[5] = calloc(sizeof(char), 255);
		strcpy(args[0], "push_swap");
		*args[1] = permutations[i][0];
		*args[2] = permutations[i][1];
		*args[3] = permutations[i][2];
		*args[4] = permutations[i][3];
		args[5] = NULL;
		int saida[2];
		pipe(saida);
		pid_t pid = fork();
		if (pid == 0)
		{
			dup2(saida[1], 1);
			execve("./push_swap", args, envp);
		}
		close(saida[1]);
		waitpid(pid, NULL, 0);
		pid = fork();
		if (pid == 0)
		{
			args[0] = strcpy(args[0], "checker_linux");
			dup2(saida[0], 0);
			execve("./checker_linux", args, envp);
		}
		waitpid(pid, NULL, 0);
	}
}
