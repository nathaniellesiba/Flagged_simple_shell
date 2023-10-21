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


void prompt1Display(void);
void prompt2Display(void);
int tsexit(info_t *info);
char *read_cmd(void);
int tswoke(info_t *info);
int tsdelmt(char c, char *delim);
void print_env(info_t *info);
char *getenv(info_t *info, const char *name);
void print_env(void);
char* starts_with(const char *str, const char *prefix);
int setenv_builtin(int argc, char *argv[]);
int unsetenv_builtin(int argc, char *argv[]);
int main(int argc, char *argv[]);
void print_environment(void);
void signal_hndl(int sig);
int cmd_checker(char **cmd, char *input, int c, char **argv);
int builtin_hndl(char **cmd, int er)




#endif
