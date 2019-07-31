#include <json.h>
#include <fcntl.h>
#include <zconf.h>
#include "stdio.h"

#define ERROR(x) {printf(x); exit(2);}

char		*read_data(const char *file_name)
{
	int 	fd;
	int 	file_length;
	char 	c;
	char 	*file_content;

	file_length = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ERROR("Can't open the file\n")
	while (read(fd, &c, 1))
		file_length++;
	file_content = (char *)malloc(file_length + 1);
	close(fd);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ERROR("Can't open the file\n")
	read(fd, file_content, file_length);
	file_content[file_length] = '\0';
	close(fd);
	return (file_content);
}

/*
 * 	json_type_null		0
 * 	json_type_boolean,	1
	json_type_double,	2
	json_type_int,		3
	json_type_object,	4
	json_type_array,	5
	json_type_string,	6
 */

void		json_parse(json_object *j_object)
{
	json_type		type;

	json_object_object_foreach(j_object, key, val)
	{
		type = json_object_get_type(val);
		if (type == json_type_object)
		{
			printf("%s\n", key);
			json_parse(val);
		}
		else if (type == json_type_string)
			printf("%s : %s\n", key, json_object_get_string(val));
		else if (type == json_type_int)
			printf("%s : %d\n", key, json_object_get_int(val));
		else if (type == json_type_double)
			printf("%s : %f\n", key, json_object_get_double(val));
	}
}

int 		main()
{
	json_object		*j_object;

	char 			*file_content;

	file_content = read_data("../test.json");
	j_object = json_tokener_parse(file_content);
	json_parse(j_object);
	return (0);
}
