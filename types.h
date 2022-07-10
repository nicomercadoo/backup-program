#pragma once

/* Constantes */
#define MAX 300
#define PATHS_FILE "paths.txt"
#define PATH_MAX 4096

/* Colores */
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

/* Tipos */
typedef enum {
  LEAVE,
  ARRIVE,
  ADD,
  RM,
  CONFIG,
  HELP,
  NONE
} TSubCommand; //Subcomandos

typedef struct {
  int config_file;
}flag;

typedef struct {
  char *path;
}TConfig;

typedef struct {
  TConfig a[MAX];
  int cant;
} TDataConf;
