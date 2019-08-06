#include "open_cl_manager.h"

static void			read_program
					(const char *file_name, char **target, u_long *length)
{
	int				fd;
	char			*buffer;
	u_long			buffer_capacity;
	u_long			buffer_unit;
	u_long			buffer_length;

	fd = open(file_name, O_RDONLY);
	ft_assert(fd != -1, "open_cl : source reading");
	buffer = (char *)malloc(OCL_BUFF_INIT);
	buffer_capacity = OCL_BUFF_INIT;
	buffer_length = 0;
	while ((buffer_unit = read(fd, buffer + buffer_length, 64)) > 0)
	{
		buffer_length += buffer_unit;
		if (buffer_length + 64 > buffer_capacity)
		{
			ft_realloc((void **)&buffer,
					   buffer_capacity, buffer_capacity * OCL_BUFF_MULT);
			buffer_capacity *= OCL_BUFF_MULT;
		}
	}
	*target = buffer;
	*length = buffer_length;
}

void				open_cl_manager_create_program(t_open_cl_manager *open_cl)
{

}
