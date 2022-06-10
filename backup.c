#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

/* Variables y Estructuras */
typedef enum{
  LEAVE,
  ARRIVE,
  ADD,
  RM,
  SET,
  HELP
} subc; //Def del tipo arg

// FILE *f

/* Acciones */
void leave();
void arrive();
void add();
void rm();
void set();
void help();
// void execute_subcommand();

/* Funciones */
subc which_subcommand(char *param);


int main(int argc, char const *argv[])
{
  char arg[20] = "";
  subc sub_command;
  // printf("%s\n", argv[1]);

  if (argc >= 1)
  {
    strcpy(arg, argv[1]);
    sub_command = which_subcommand(arg);
    switch (sub_command)
    {
    case LEAVE:   leave();  break;
    case ARRIVE:  arrive(); break;
    case ADD:     add();    break;
    case RM:      rm();     break;
    case SET:     set();    break;
    case HELP:    help();   break;
    default:                break;
    }
  }
  else
  {
    puts("Falstan argumentos\n");
  }
  
  
  return 0;
}

/* Definicion de Funciones */
// arg whichArg(char *argv[])
subc which_subcommand(char *param){
  if (strcmp(param, "leave") == 0)  return LEAVE ;
  if (strcmp(param, "arrive") == 0) return ARRIVE;
  if (strcmp(param, "add") == 0)    return ADD;
  if (strcmp(param, "rm") == 0)     return RM;
  if (strcmp(param, "set") == 0)    return SET;
  if (strcmp(param, "help") == 0)   return HELP;
}  

void execute_subcommand (subc sub_command){
  
}

