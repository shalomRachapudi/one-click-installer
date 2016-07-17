#include "permissions.h"

// gain [back] root privileges
void do_setuid(void)
{
    int status;
    #ifdef _POSIX_SAVED_IDS
      status = seteuid( euid );
    #else
      status = setreuid( ruid, euid );
    #endif
    if ( status < 0 ) {
      cerr << "Couldn't set uid." << endl;
      exit( status );
    }
}

// drop root privileges
void undo_setuid(void)
{
    int status;
    #ifdef _POSIX_SAVED_IDS
      status = seteuid( ociId );
    #else
      status = setreuid( euid, ociId );
    #endif
    if (status < 0 ) {
      cerr << "Couldn't set uid." << endl;
      exit( status );
    }
}
