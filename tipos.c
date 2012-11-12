typedef struct user{
  char id[80];
  int grant;
  struct scheduler * waiting;
  struct queue * done;
  struct user * next;
}TUser;

typedef struct scheduler{
  int priority;
  struct queue * tasks;
  struct scheduler * next;
}TScheduler, PriorityList;

typedef struct task{
  TUser * owner;
  unsigned int pid;
  int priority;
  char cmd[80];
}Task;

typedef struct node{
  Task * info;
  struct node * next;
}TNode;

typedef struct queue{
  TNode * begin;
  TNode * end;
}TQueue;

typedef struct base{
  unsigned int pid;		//id para o prox processo
  TUser * users;		//LISTA de usuarios
  TQueue * fu;			//FILA de processos inicias
  TScheduler * scheduler;	//LISTA do escalonador
}TBase;