#define MAX 300
#define PATHS_FILE "paths.txt"

//Colors
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

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
