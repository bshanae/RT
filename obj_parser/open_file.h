#ifndef OPEN_FILE_H
# define OPEN_FILE_H

# include "objpar.h"
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>

void*				open_file(const char* p_file_name, size_t* p_file_size);

#endif
