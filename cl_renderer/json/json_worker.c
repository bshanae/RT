#include "jsmn.h"
#include "json_parse.h"

void				work_object(void *data, char *json, jsmntok_t *tokens)
{
	char			*type;

	type = get_string_in_object(json, tokens, "type");
	if (!type)
		return ;
	if (ft_strequ(type, "camera"))
		parse_camera(data, json, tokens);
	else if (ft_strequ(type, "sphere"))
		parse_sphere(data, json, tokens);
	else if (ft_strequ(type, "plane"))
		parse_plane(data, json, tokens);
	else if (ft_strequ(type, "cone"))
		parse_cone(data, json, tokens);
	else if (ft_strequ(type, "cylinder"))
		parse_cylinder(data, json, tokens);
	else if (ft_strequ(type, "box"))
		parse_box(data, json, tokens);
	else if (ft_strequ(type, "paraboloid"))
		parse_paraboloid(data, json, tokens);
	else if (ft_strequ(type, "moebius"))
		parse_moebius(data, json, tokens);
	else if (ft_strequ(type, "torus"))
		parse_torus(data, json, tokens);
	else if (ft_strequ(type, "mandelbulb"))
		parse_mandelbulb(data, json, tokens);
	else if (ft_strequ(type, "julia"))
		parse_julia(data, json, tokens);
	else if (ft_strequ(type, "light ambient"))
		parse_ambient(data, json, tokens);
	else if (ft_strequ(type, "light point"))
		parse_point(data, json, tokens);
	else if (ft_strequ(type, "light direct"))
		parse_direct(data, json, tokens);
	else if (ft_strequ(type, "explosion"))
		parse_direct(data, json, tokens);
	else if (ft_strequ(type, "perforated cube"))
		parse_direct(data, json, tokens);
	else if (ft_strequ(type, "settings"))
		parse_settings(data, json, tokens);
	free(type);
}

void				work_tokens(void *data, char *json, jsmntok_t *tokens)
{
	int				qt;
	const int		len = tokens[0].size;

	tokens++;
	qt = 0;
	while (qt < len)
	{
		work_object(data, json, tokens);
		tokens = next_item(tokens);
		qt++;
	}
}

void 				static_load_error()
{
	ft_printf("{red}JSON Parser : Couldn't parse file\n");
}

void				load_scene(void *data, const char *path)
{
	char			*json;
	int				res;
	jsmn_parser		parser;
	jsmntok_t		*tokens;

	if (!data || !path)
		return (static_load_error());
	json = read_file(path);
	if (!json)
		return (static_load_error());
	jsmn_init(&parser);
	res = jsmn_parse(&parser, json, strlen(json), NULL, 1);
	if (res <= 0)
		return (static_load_error());
	tokens = rt_malloc(sizeof(jsmntok_t) * res);
	jsmn_init(&parser);
	jsmn_parse(&parser, json, strlen(json), tokens, res);
	// default_settings();
	work_tokens(data, json, tokens);
	free(tokens);
	free(json);
}
