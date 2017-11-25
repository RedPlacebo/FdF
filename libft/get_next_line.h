#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define BUFF_SIZE 8

int		get_next_line(const int fd, char **line);

#endif
