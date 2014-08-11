#ifndef FILE_H
#define FILE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "datastruct.h"

#define READ_BUFFER_LEN 80

int32_t readString(FILE *fin, char *dest);
void ignoreChar(FILE *fin, char c);

#endif
