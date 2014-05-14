/* 
 * \file Name: mycron.c
 * Created:  Led Zhang 05/14/2014
 * Modified: Led Zhang 05/14/2014 21:48>
 * 
 * \brief
 * 
 * \details
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
    FILE *file;
    struct tm *t1;
    time_t t;
    char buf[100];
    int line = 1;
    int c = 0;
    
    memset(buf, 0, sizeof(buf));
    
    if((file = fopen("test.plist","a+")) < 0)
    {
        perror("failed to open test.plist");
        exit(-1);
    }
    printf("OK");
    
    while((c = getc(file)) != EOF) // count the line number
        if (c == '\n')
            line++;
    
    while(1)
    {
        time(&t);
        printf("&t is: %i",t);
        t1 = localtime(&t);
        printf("localtime(&t) is: %s",t1);
        
        sprintf(buf, "%d, %d-%d-%d %d:%d:%d\n", line++, t1->tm_year + 1900,\
                t1->tm_mon + 1, t1->tm_mday, t1->tm_mday, t1->tm_hour,\
                t1->tm_min, t1->tm_sec);
        fwrite(buf, sizeof(char), strlen(buf), file);
        fflush(file);

        sleep(1);
    }
    return 0;
}
/* 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2, or (at your option) any later
 * version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 * 
 * Had you not received a copy of the GNU General Public License yet, write
 * to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
