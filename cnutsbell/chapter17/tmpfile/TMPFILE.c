/* TMPFILE.C: This program uses tmpfile to create a
 * temporary file, then deletes this file with _rmtmp.
 */

#include <stdio.h>

void main( void )
{
   FILE *stream;
   char tempstring[] = "String to be written";
   int  i;

   /* Create temporary files. */
   for( i = 1; i <= 3; i++ )
   {
      if( (stream = tmpfile()) == NULL )
         perror( "Could not open new temporary file\n" );
      else
         printf( "Temporary file %d was created\n", i );
   }

   /* Remove temporary files. */
   printf( "%d temporary files deleted\n", _rmtmp() );
}


