#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"base.h"
#include"fila.h"
#include"lprioridade.h"
#include"lusuario.h"


void run_help(){
    system("clear");
    printf("+++ HELP +++\n");
    printf("[usuario:prioridade:comando]\t\tcria nova tarefa\n");
    printf("file nome_arquivo\t\t\tcarrega arquivo de tarefas\n");
    printf("print [fu,fe,ftr,user [nome],users]\timprime\n");
    printf("make\t\t\t\t\tcarrega FU e FTR de FE\n");
    printf("run\t\t\t\t\texecuta UMA tarefa de FTR ou FU\n");
    printf("runall\t\t\t\t\texecuta TODAS as tarefas de FTR e FU\n");
    printf("clear\t\t\t\t\tlimpa a tela\n");
    printf("exit\t\t\t\t\tsai do programa\n");
    printf("+++ end +++\n\n");
}

void run_file(TBase * base, char * cmd) {
    FILE *p = NULL;
    char tmp[120];
    
    if (!(p = fopen(cmd, "r")))
        return;
    
    while (!feof(p)) {
        fscanf(p, "%s", tmp);
        if (check_user_cmd(tmp))
            run_usercmd(base, tmp);
    }
    fclose(p);
}

void run_print(TBase * base, char * cmd) {
    char command[120];
    char arg[120];
    char ex[120];

    sscanf(cmd, "%[^ ] %[^ ] %[^ ] ", ex, command, arg);

    if (!strcmp("ftr", command))
        print_ftr(base);

    else if (!strcmp("fu", command))
        print_fu(base);

    else if (!strcmp("fe", command))
        print_fe(base);

    else if (!strcmp("users", command))
        print_users(base);

    else if (!strcmp("user", command)) {
        TUser * user = finduser(base->users, arg);
        if (user)
            print_user(user);
    }

}

int run_exec(TBase * base) {
    Task * task = NULL;
    if (!emptyq(base->FTR))
        task = pop(base->FTR);
    else if (!emptyp(base->FU))
        task = toptask(base->FU);

    if (task)
        return execute(task);

    return 0;
}

void run_execall(TBase * base) {
    while (!emptyq(base->FTR) || !emptyp(base->FU))
        run_exec(base);
}

void run_prepare(TBase * base) {
    arrange(base);
}

int run_usercmd(TBase * base, char * cmd) {
    int i, j, value = 0;

    char end = '\0';
    char u[120] = "", p[120] = "", c[120] = "";

    for (i = 0, j = 0; cmd[i] != end; i++, j++) {
        if (cmd[i] == ':' && value < 2) {
            value++;
            j = -1;
        } else {
            if (value == 0) {
                u[j] = cmd[i];
                u[j + 1] = end;
            }
            if (value == 1) {
                p[j] = cmd[i];
                p[j + 1] = end;
            }
            if (value == 2) {
                c[j] = cmd[i];
                c[j + 1] = end;
            }
        }
    }

    if (value != 2 || u[0] == '\0' || p[0] == '\0' || c[0] == '\0')
        return 0;

    for (j = 0; p[j] != end; j++) {//somente valores positivos
        if (p[j] == '-' || p[j] < '0' || p[j] > '9') {
            printf("somente prioridade inteira positiva!\n");
            return 0;
        }
    }

    if (!base)
        return 1;

    int priority;

    sscanf(p, "%i", &priority);

    unsigned int pid = newtask(base, u, priority, c);

    return 1;
}

int check_user_cmd(char * cmd) {
    return run_usercmd(NULL, cmd);
}

int command(char * cmd, TBase * base) {
    char command[120];
    char arg[120];

    sscanf(cmd, "%[^ ] %s", command, arg);

    if (!strcmp("file", command))
        run_file(base,arg);

    else if (!strcmp("make", command)) {
        run_prepare(base);
    } else if (!strcmp("run", command)) {
        run_exec(base);
    } else if (!strcmp("runall", command)) {
        run_execall(base);
    } else if (!strcmp("exit", command)) {
        return 0;
    } else if (!strcmp("help", command)) {
        run_help();
    } else if (!strcmp("clear", command)) {
        system("clear");
    } else if (!strcmp("print", command)) {
        run_print(base, cmd);
    } else if (check_user_cmd(cmd))
        run_usercmd(base, cmd);

    else
        printf("comando inexistente\n");
    
    return 1;
}

int main(void) {
    TBase * base = start_base();
    char input[120];
    int loop = 1;
    run_help();
    while (loop) {
        scanf(" %[^\n]s", input);
        loop = command(input, base);
    }

    printf("\n");

    print_users(base);

    print_fe(base);

    print_ftr(base);

    print_fu(base);

    return (0);
}


