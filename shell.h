#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

<<<<<<< HEAD
void prompt1Display(void);
void prompt2Display(void);
=======

void prompt1Display(void);
void prompt2Display(void);

>>>>>>> c33114a6d6596ef5cd0f43a9b6a28df9467ad251
char *read_cmd(void);

#endif

