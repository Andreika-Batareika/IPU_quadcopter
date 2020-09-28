#ifndef MSG_H
#define MSG_H
// C library headers
#include <stdio.h>
#include <string.h>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

class MSG
{
public:
    MSG();

    void readport();

    void writeport();

};

#endif // MSG_H
