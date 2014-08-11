#include "file.h"

int32_t readString(FILE *fin, char *dest)
{
    if (!fin || !dest)
        return 0;

    char c;
    int32_t i = 0;
    //To "
    while ((c = fgetc(fin)) != EOF) {
        if ('"'==c)
            break;
    }
    while ((c = fgetc(fin)) != EOF) {
        if ('"'==c) {
            break;
        } else {
            *(dest+i) = c;
            i ++;
        }
    }

    *(dest+i) = 0;
    //Return the len of string read
    return i;
}

void ignoreChar(FILE *fin, char c)
{
    if (!fin)
        return;

    char ch;
    while ((ch = fgetc(fin)) != c);
}
