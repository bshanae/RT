#include "gui.h"
#include "gui_signal_connect_x.h"
#include "cl_renderer.h"
#include "material_list.h"

void				scene_cornell_box_walls(t_scene *scene);
void				scene_cornell_box_objects(t_scene *scene, t_camera *camera);

void				scene_spheres(t_scene *scene, t_camera *camera);

void				scene_textures(t_scene *scene, t_camera *camera);

int					main(int argc, char **argv)
{
	t_gui			*gui;

	gui = gui_new(&argc, &argv);
	gui_signal_connect_all(gui);
	gui->renderer = cl_renderer_new(gui->image);
	scene_cornell_box_objects(gui->renderer->data.scene, gui->renderer->data.camera);
	scene_cornell_box_walls(gui->renderer->data.scene);
	cl_renderer_change_tracing_mod(gui->renderer, rt_tracing_rt);
	cl_renderer_change_light_mod(gui->renderer, rt_light_area);
	cl_renderer_change_background(gui->renderer, rt_background_none);
	camera_apply(gui->renderer->data.camera);
	cl_renderer_camera_save(gui->renderer);
    scene_update(gui->renderer->data.scene);
    gui_connect(gui);
	gui_update(gui);
	gui_loop(gui);
	gui_delete(&gui);
	return (0);
}

void				scene_spheres(t_scene *scene, t_camera *camera)
{
	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){0., 50., 76.}, 3.);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){0., 0., -60.}, 10.);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_PINK);
	scene_edit_param(scene, -1, scene_param_name, "Sphere Center");

	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){20., 0., -60.}, 7.);
	scene_edit_param(scene, -1, scene_param_texture, "Sine");
	scene_edit_param(scene, -1, scene_param_name, "Sphere Right");

	object_build(scene_get_space(scene), object_type_limited, (RT_F4_API){20., 0., -60.}, 7.);
	scene_edit_param(scene, -1, scene_param_texture, "Sine");
	scene_edit_param(scene, -1, scene_param_name, "Sphere Right");
	camera->position.z = 150;
}

void				scene_textures(t_scene *scene, t_camera *camera)
{
	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){0., 50., 76.}, 3.);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
	scene_edit_param(scene, -1, scene_param_name, "Light");
	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., -20., 0.}, (RT_F4_API){0., 1., 0.});
	scene_edit_param(scene, -1, scene_param_texture, "Checkerboard");
	scene_edit_param(scene, -1, scene_param_name, "Plane");
	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){0., 17., -41.}, 15.);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_GLASS);
	scene_edit_param(scene, -1, scene_param_name, "Sphere Glass");
	object_build(scene_get_space(scene), object_type_cone, (RT_F4_API){35., 25., -110.}, (RT_F4_API){35., -15., -110.}, 15.);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_RED);
	scene_edit_param(scene, -1, scene_param_name, "Cone");
	object_build(scene_get_space(scene), object_type_cylinder, (RT_F4_API){-5., 45., -165.}, (RT_F4_API){10., -10., -164.}, 10.);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_GREEN);
	scene_edit_param(scene, -1, scene_param_name, "Cylinder");
	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){-35., 3., -110.}, 15.);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_BLUE);
	scene_edit_param(scene, -1, scene_param_name, "Sphere");
	camera->position.x = 37;
	camera->position.y = 20;
	camera->position.z = 167;

	// rotation 0. 0.15 0.
}

void				scene_cornell_box_objects(t_scene *scene, t_camera *camera)
{
	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){17., 40., -16.}, 3.);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
	scene_edit_param(scene, -1, scene_param_name, "Light");
	object_build(scene_get_space(scene), object_type_paraboloid, (RT_F4_API){0., 12., -38.}, (RT_F4_API){0., -1., 0.}, 5.);
	scene_edit_param(scene, -1, scene_param_name, "Sphere");
	camera->position.y = 20;
	camera->position.z = 170;
}

void				scene_cornell_box_walls(t_scene *scene)
{
	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 0., -140.}, (RT_F4_API){0., 0., 1.}, rt_limit_yes);
	scene_edit_param(scene, -1, scene_param_name, "Plane Back");
	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){-40., 0., 0.}, (RT_F4_API){1., 0., 0.}, rt_limit_yes);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_RED);
	scene_edit_param(scene, -1, scene_param_name, "Plane Left");
	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){40., 0., 0.}, (RT_F4_API){-1., 0., 0.}, rt_limit_yes);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_BLUE);
	scene_edit_param(scene, -1, scene_param_name, "Plane Right");
	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 0., 200.}, (RT_F4_API){0., 0., -1.}, rt_limit_yes);
	scene_edit_param(scene, -1, scene_param_name, "Plane Front");
	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 70., 0.}, (RT_F4_API){0., -1., 0.}, rt_limit_yes);
	scene_edit_param(scene, -1, scene_param_name, "Plane Up");
	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., -25., 0.}, (RT_F4_API){0., 1., 0.}, rt_limit_yes);
	scene_edit_param(scene, -1, scene_param_name, "Plane Down");
}
