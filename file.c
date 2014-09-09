/**
 * 
 */
#include "file.h"

/**
 * 
 * @param  fin  [description]
 * @param  dest [description]
 * @return      [description]
 */
int readString(FILE *fin, char *dest)
{
    if (!fin || !dest)
        return 0;

    char c;
    int i = 0;
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

/**
 * 
 * @param fin [description]
 * @param c   [description]
 */
void ignoreChar(FILE *fin, char c)
{
    if (!fin)
        return;

    char ch;
    while ((ch = fgetc(fin)) != c);
}
