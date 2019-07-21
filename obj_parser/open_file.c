#include "open_file.h"

void*				open_file(const char* p_file_name, size_t* p_file_size)
{
	FILE* p_file;
	void* p_file_data;
	size_t size;
	int err;

#if defined(_MSC_VER)
	fopen_s(&p_file, p_file_name, "rb");
#else
	p_file = fopen(p_file_name, "rb+");
#endif
	assert(p_file != NULL);
	fseek(p_file, 0L, SEEK_END);
	size = ftell(p_file);
	rewind(p_file);
	p_file_data = malloc(size);
#if defined(_MSC_VER)
	fread_s(p_file_data, size, size, 1, p_file);
#else
	fread(p_file_data, size, 1, p_file);
#endif
	err = ferror(p_file);
	assert(err == 0);
	fclose(p_file);
	*p_file_size = size;
	return p_file_data;
}
