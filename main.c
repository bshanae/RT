#include "gui.h"
#include "gui_signal_connect_x.h"
#include "cl_renderer.h"
#include "material_list.h"

void				scene_test_a(t_scene *scene)
{
	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){10., 0., -10.}, 3.);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT, scene_param_end);
	scene_edit_param(scene, -1, scene_param_name, "Light", scene_param_end);
	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 0., -70.}, (RT_F4_API){0., 0., 1.}, plane_limiting_yes);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_WHITE, scene_param_end);
	scene_edit_param(scene, -1, scene_param_name, "Front Plane", scene_param_end);
	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 0., 100.}, (RT_F4_API){0., 0., -1.}, plane_limiting_yes);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_WHITE, scene_param_end);
	scene_edit_param(scene, -1, scene_param_name, "Back Plane", scene_param_end);
	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){30., 0., 0.}, (RT_F4_API){-1., 0., 0.}, plane_limiting_yes);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_RED, scene_param_end);
	scene_edit_param(scene, -1, scene_param_name, "Right Plane", scene_param_end);
	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){-30., 0., 0.}, (RT_F4_API){1., 0., 0.}, plane_limiting_yes);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_GREEN, scene_param_end);
	scene_edit_param(scene, -1, scene_param_name, "Left Plane", scene_param_end);
	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 50., 0.}, (RT_F4_API){0., -1., 0.}, plane_limiting_yes);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_WHITE, scene_param_end);
	scene_edit_param(scene, -1, scene_param_name, "Upper Plane", scene_param_end);
	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., -50., 0.}, (RT_F4_API){0., 1., 0.}, plane_limiting_yes);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_WHITE, scene_param_end);
	scene_edit_param(scene, -1, scene_param_name, "Lower Plane", scene_param_end);
	object_build(scene_get_space(scene), object_type_box, (RT_F4_API){0., 0., 0.}, (RT_F4_API){5., 5., 5.});
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_WHITE, scene_param_end);
	scene_edit_param(scene, -1, scene_param_name, "Box", scene_param_end);
}

int					main(int argc, char **argv)
{
	t_gui			*gui;


	gui = gui_new(&argc, &argv);
	gui_signal_connect_all(gui);
	gui->renderer = cl_renderer_new(gui->image);
	scene_test_a(gui->renderer->data.scene);
	gui->renderer->data.camera->position.x = -20;
	gui->renderer->data.camera->rotation.y = -1.6;
	camera_apply(gui->renderer->data.camera);
	cl_renderer_camera_save(gui->renderer);
	rt_assert_critical(scene_is_valid_content(gui->renderer->data.scene),
		"Main : Scene is not valid");
    scene_update(gui->renderer->data.scene);
	gui_update(gui);
	gui_loop(gui);
	gui_delete(&gui);
	return (0);
}
