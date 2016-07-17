#ifndef PERMISSIONS_H
#define PERMISSIONS_H

#include <unistd.h>
#include <sys/types.h>
#include <iostream>

#ifdef MAIN_FILE
int ociId;	// contains the uid of oneclickinstaller 
uid_t euid;	// effective uid of OCIhelper which is 0
uid_t ruid;	// real uid of OCIhelper which is also 0
#else
extern int ociId;
extern uid_t euid;
extern uid_t ruid;
#endif

using namespace std;

void do_setuid( void );		// gain [back] root privileges
void undo_setuid( void );  	//drop root privileges 
#endif 
