#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <windows.h> 

// Simplificated xv6 shell.

#define MAXARGS 10

// All commands have at least a type. Have looked at the type, the code
// typically casts the *cmd to some specific cmd type.
struct cmd {
  int type;          //  ' ' (exec), | (pipe), '<' or '>' for redirection
};

struct execcmd {
  int type;              // ' '
  char *argv[MAXARGS];   // arguments to the command to be exec-ed
};

struct redircmd {
  int type;          // < or > 
  struct cmd *cmd;   // the command to be run (e.g., an execcmd)
  char *file;        // the input/output file
  int mode;          // the mode to open the file with
  int fd;            // the file descriptor number to use for the file
};

struct pipecmd {
  int type;          // |
  struct cmd *left;  // left side of pipe
  struct cmd *right; // right side of pipe
};

int fork1(void);  // Fork but exits on failure.
struct cmd *parsecmd(char*);
void echo_(char[]);

// Execute cmd.  Never returns.
void
runcmd(struct cmd *cmd)
{
  int p[2], r;
  struct execcmd *ecmd;
  struct pipecmd *pcmd;
  struct redircmd *rcmd;

  if(cmd == 0)
    exit(0);
  
  switch(cmd->type){
  default:
    fprintf(stderr, "unknown runcmd\n");
    exit(-1);

  case ' ':
    ecmd = (struct execcmd*)cmd;
    if(ecmd->argv[0] == 0)
      exit(0);
    
    execvp(ecmd->argv[0],ecmd->argv);

    break;

  case '>':
  	break;
  case '<':
    rcmd = (struct redircmd*)cmd;

    close(rcmd->fd);
    open(rcmd->file,rcmd->mode);
    
    runcmd(rcmd->cmd);
    break;

//2017.10.10.20.46
//  case '|':
//    pcmd = (struct pipecmd*)cmd;
//    //fprintf(stderr, "pipe not implemented\n");
//    
//    int p[2];
//    pipe(p);
//    if(fork()==0) {
//      close(0);
//      dup(p[0]);
//      close(p[0]);
//      close(p[1]);
//      execvp(ecmd->argv[0],ecmd->argv);
//    } else {
//      close(1);
//      dup(p[1]);
//      execvp(ecmd->argv[0],ecmd->argv);
//      close(p[0]);
//      close(p[1]); 
//   
//    }    
//
//    break;
  }//end switch()
  exit(0);/**/
}//end runcmd()

int
getcmd(char *buf, int nbuf)
{
  
  if (isatty(fileno(stdin)))
    fprintf(stdout, "$ ");
  memset(buf, 0, nbuf);
  fgets(buf, nbuf, stdin);
  if(buf[0] == 0) // EOF
    return -1;
  return 0;
}//end getcmd()

int
main(void)
{
  static char buf[100];
  int fd, r;
//  int count=0;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
  // Read and run input commands.
  while(getcmd(buf, sizeof(buf)) >= 0){
	echo_(buf);
    
	if(buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' '){
      // Clumsy but will have to do for now.
      // Chdir has no effect on the parent if run in the child.
      buf[strlen(buf)-1] = 0;  // chop \n
      if(chdir(buf+3) < 0)
        fprintf(stderr, "cannot cd %s\n", buf+3);
      continue;
    }
//2017.10.11.08.48
//    if(fork1() == 0)
//      runcmd(parsecmd(buf));
////2017.10.11.08.45
////    wait(&r);
//    count=0;
	if(buf[0] == 'n' && buf[1] == 'o' &&
		buf[2] == 't' && buf[3] == 'e' && 
		buf[4] == 'p' && buf[5] == 'a' &&
		buf[6] == 'd'){
      // Clumsy but will have to do for now.
      // Chdir has no effect on the parent if run in the child.
//      buf[strlen(buf)-1] = 0;  // chop \n
//      if(chdir(buf+3) < 0)
//        fprintf(stderr, "cannot cd %s\n", buf+3);
//      continue;

//		STARTUPINFO si;
//		PROCESS_INFORMATION pi;
		ZeroMemory(&si,sizeof(si));
		si.cb=sizeof(si);
		ZeroMemory(&pi,sizeof(pi));

		if(!CreateProcess("C:/Windows/notepad.exe",
			"notepad.exe D:/readme.txt",0,0,0,0,0,0,&si,&pi)){
			//Could not start process;
			//Now 'pi.hProcess' contains the process HANDLE, which you can use to wait for it like this:
			printf("There are some problem(s)\n");
			WaitForSingleObject(pi.hProcess,INFINITE);
		}
    }//end if()
//    C:/Program Files (x86)/MiKTeX 2.9/miktex/bin/pdflatex.exe
		if(buf[0] == 'p' && buf[1] == 'd' &&
			buf[2] == 'f' && buf[3] == 'l' && 
			buf[4] == 'a' && buf[5] == 't' &&
			buf[6] == 'e' && buf[7] == 'x'){
			ZeroMemory(&si,sizeof(si));
			si.cb=sizeof(si);
			ZeroMemory(&pi,sizeof(pi));
//		if(!CreateProcess(L"C:/WINDOWS/notepad.exe",L"notepad.exe c:/readme.txt",0,0,0,0,0,0,&si,&pi))
			if(!CreateProcess("C:/Program Files (x86)/MiKTeX 2.9/miktex/bin/pdflatex.exe","pdflatex.exe D:/hola.tex",0,0,0,0,0,0,&si,&pi)){
				//Could not start process;
				//Now 'pi.hProcess' contains the process HANDLE, which you can use to wait for it like this:
				printf("There are some problem(s)\n");
			WaitForSingleObject(pi.hProcess,INFINITE);
		}		
		}
  }//end while()
  exit(0);
}//end main()

//int
//fork1(void)
//{
//  int pid;
//  
//  pid = fork();
//  if(pid == -1)
//    perror("fork");
//  return pid;
//}
void
echo_(char buf[])
{
	int count=0;
	while(buf[count++]!=0);count--;
//  	printf("\nPrimer NULL esta en count=%d\n",count);
//  	printf("r\tbuf[r]\n");
//  	for(r=0;r<count;r++){
//  		printf("%d\t%c\n",r,buf[r]);
//	}
	/*al momento buf[count]==0 deberia ser true*/
	count--;
	while((buf[count]==' ')||(buf[count]=='\n')){
		count--;
	}/*al salir de este while puede suceder que buf[count] sea ';' en cuyo caso no se hace echo*/
//	printf("count=%d\n",count);
//	printf("\"%c\"\t\"%c\"\t\"%c\"\n",buf[count?count-1:count],buf[count],buf[count+1]);
	if(buf[count]!=';'){
	  printf("%s",buf);
	}
}//end echo_

struct cmd*
execcmd(void)
{
  struct execcmd *cmd;

  cmd = (struct execcmd *)malloc(sizeof(*cmd));
  memset(cmd, 0, sizeof(*cmd));
  cmd->type = ' ';
  return (struct cmd*)cmd;
}

struct cmd*
redircmd(struct cmd *subcmd, char *file, int type)
{
  struct redircmd *cmd;

  cmd = (struct redircmd *)malloc(sizeof(*cmd));
  memset(cmd, 0, sizeof(*cmd));
  cmd->type = type;
  cmd->cmd = subcmd;
  cmd->file = file;
  cmd->mode = (type == '<') ?  O_RDONLY : O_WRONLY|O_CREAT|O_TRUNC;
  cmd->fd = (type == '<') ? 0 : 1;
  return (struct cmd*)cmd;
}

struct cmd*
pipecmd(struct cmd *left, struct cmd *right)
{
  struct pipecmd *cmd;

  cmd = (struct pipecmd *)malloc(sizeof(*cmd));
  memset(cmd, 0, sizeof(*cmd));
  cmd->type = '|';
  cmd->left = left;
  cmd->right = right;
  return (struct cmd*)cmd;
}

// Parsing

char whitespace[] = " \t\r\n\v";
char symbols[] = "<|>";

int
gettoken(char **ps, char *es, char **q, char **eq)
{
  char *s;
  int ret;
  
  s = *ps;
  while(s < es && strchr(whitespace, *s))
    s++;
  if(q)
    *q = s;
  ret = *s;
  switch(*s){
  case 0:
    break;
  case '|':
  case '<':
    s++;
    break;
  case '>':
    s++;
    break;
  default:
    ret = 'a';
    while(s < es && !strchr(whitespace, *s) && !strchr(symbols, *s))
      s++;
    break;
  }
  if(eq)
    *eq = s;
  
  while(s < es && strchr(whitespace, *s))
    s++;
  *ps = s;
  return ret;
}

int
peek(char **ps, char *es, char *toks)
{
  char *s;
  
  s = *ps;
  while(s < es && strchr(whitespace, *s))
    s++;
  *ps = s;
  return *s && strchr(toks, *s);
}

struct cmd *parseline(char**, char*);
struct cmd *parsepipe(char**, char*);
struct cmd *parseexec(char**, char*);

// make a copy of the characters in the input buffer, starting from s through es.
// null-terminate the copy to make it a string.
char 
*mkcopy(char *s, char *es)
{
  int n = es - s;
  char *c = (char*)malloc(n+1);
  assert(c);
  strncpy(c, s, n);
  c[n] = 0;
  return c;
}

struct cmd*
parsecmd(char *s)
{
  char *es;
  struct cmd *cmd;

  es = s + strlen(s);
  cmd = parseline(&s, es);
  peek(&s, es, "");
  if(s != es){
    fprintf(stderr, "leftovers: %s\n", s);
    exit(-1);
  }
  return cmd;
}

struct cmd*
parseline(char **ps, char *es)
{
  struct cmd *cmd;
  cmd = parsepipe(ps, es);
  return cmd;
}

struct cmd*
parsepipe(char **ps, char *es)
{
  struct cmd *cmd;

  cmd = parseexec(ps, es);
  if(peek(ps, es, "|")){
    gettoken(ps, es, 0, 0);
    cmd = pipecmd(cmd, parsepipe(ps, es));
  }
  return cmd;
}

struct cmd*
parseredirs(struct cmd *cmd, char **ps, char *es)
{
  int tok;
  char *q, *eq;

  while(peek(ps, es, "<>")){
    tok = gettoken(ps, es, 0, 0);
    if(gettoken(ps, es, &q, &eq) != 'a') {
      fprintf(stderr, "missing file for redirection\n");
      exit(-1);
    }
    switch(tok){
    case '<':
      cmd = redircmd(cmd, mkcopy(q, eq), '<');
      break;
    case '>':
      cmd = redircmd(cmd, mkcopy(q, eq), '>');
      break;
    }
  }
  return cmd;
}

struct cmd*
parseexec(char **ps, char *es)
{
  char *q, *eq;
  int tok, argc;
  struct execcmd *cmd;
  struct cmd *ret;
  
  ret = execcmd();
  cmd = (struct execcmd*)ret;

  argc = 0;
  ret = parseredirs(ret, ps, es);
  while(!peek(ps, es, "|")){
    if((tok=gettoken(ps, es, &q, &eq)) == 0)
      break;
    if(tok != 'a') {
      fprintf(stderr, "syntax error\n");
      exit(-1);
    }
    cmd->argv[argc] = mkcopy(q, eq);
    argc++;
    if(argc >= MAXARGS) {
      fprintf(stderr, "too many args\n");
      exit(-1);
    }
    ret = parseredirs(ret, ps, es);
  }
  cmd->argv[argc] = 0;
  return ret;
}
