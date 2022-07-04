#pragma once

#define MAX 300
#define PATHS_FILE "paths.txt"

typedef enum {
  LEAVE,
  ARRIVE,
  ADD,
  RM,
  CONFIG,
  HELP,
  NONE
} subc; //Subcomandos

typedef struct {
  int config_file;
}flag;

typedef struct {
  char *path;
}TConfig;

typedef struct {
  TConfig a[MAX];
  int cant;
} TData;
