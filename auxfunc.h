#pragma once

#include "types.h"

void sort_file (char *fname);
void load_on_array (unsigned n, unsigned m, char a[n][m], FILE **file);
void selection_sort (int n, int m, char strings[n][m]);
void load_on_file (unsigned n, unsigned m, char a[n][m], FILE **file);