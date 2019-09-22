#include "gui.h"
#include "gui_signal_connect_x.h"
#include "cl_renderer.h"
#include "material_list.h"

void				scene_test_rt(t_scene *scene);
void				scene_test_limited(t_scene *scene);
void				scene_test_illumination(t_scene *scene);
void				scene_test_rm(t_scene *scene);
void				scene_test_box(t_scene *scene);
void				scene_test_csg(t_scene *scene);

int					main(int argc, char **argv)
{
	t_gui			*gui;

	gui = gui_new(&argc, &argv);
	gui_signal_connect_all(gui);
	gui->renderer = cl_renderer_new(gui->image);
	scene_test_box(gui->renderer->data.scene);
	gui->renderer->data.camera->position.z = 180;
	gui->renderer->data.camera->position.y = 15;
	cl_renderer_change_tracing_mod(gui->renderer, rt_tracing_mod_rt);
	camera_apply(gui->renderer->data.camera);
	cl_renderer_camera_save(gui->renderer);
    scene_update(gui->renderer->data.scene);
	gui_update(gui);
	gui_loop(gui);
	gui_delete(&gui);
	return (0);
}

void				scene_test_box(t_scene *scene)
{
	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){0., 0., 20.}, 3.);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
	scene_edit_param(scene, -1, scene_param_name, "Light");

	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){0., 0., 10.}, 3.);
	scene_edit_param(scene, -1, scene_param_name, "Sphere");

	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., -50., 0.}, (RT_F4_API){0., 1., 0.});
	scene_edit_param(scene, -1, scene_param_name, "Plane Lower");

	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 50., 0.}, (RT_F4_API){0., -1., 0.});
	scene_edit_param(scene, -1, scene_param_name, "Plane Upper");

	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){50., 0., 0.}, (RT_F4_API){-1., 0., 0.});
	scene_edit_param(scene, -1, scene_param_name, "Plane Right");

	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){-50., 0., 0.}, (RT_F4_API){1., 0., 0.});
	scene_edit_param(scene, -1, scene_param_name, "Plane Left");

	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 0., -50.}, (RT_F4_API){0., 0., 1.});
	scene_edit_param(scene, -1, scene_param_name, "Plane Front");

	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 0., 200.}, (RT_F4_API){0., 0., -1.});
	scene_edit_param(scene, -1, scene_param_name, "Plane Back");

	object_build(scene_get_space(scene), object_type_cone, (RT_F4_API){-10., -10., 0.}, (RT_F4_API){-10., 10., 0.}, 2.);
	scene_edit_param(scene, -1, scene_param_name, "Cone");

	object_build(scene_get_space(scene), object_type_cylinder, (RT_F4_API){-20., -10., 0.}, (RT_F4_API){-20., 10., 0.}, 2.);
	scene_edit_param(scene, -1, scene_param_name, "Cylinder");
}

void				scene_test_rt(t_scene *scene)
{
	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){0., 0., 0.}, 3.);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
	scene_edit_param(scene, -1, scene_param_name, "Light");

	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., -50., 0.}, (RT_F4_API){0., 1., 0.});
	scene_edit_param(scene, -1, scene_param_name, "Plane A");

	object_build(scene_get_space(scene), object_type_cone, (RT_F4_API){-10., -10., 0.}, (RT_F4_API){-10., 10., 0.}, 2.);
	scene_edit_param(scene, -1, scene_param_name, "Cone");

	object_build(scene_get_space(scene), object_type_cylinder, (RT_F4_API){-20., -10., 0.}, (RT_F4_API){-20., 10., 0.}, 2.);
	scene_edit_param(scene, -1, scene_param_name, "Cylinder");

	object_build(scene_get_space(scene), object_type_box, (RT_F4_API){10., 0., 0.}, (RT_F4_API){5., 10., 5.});
	scene_edit_param(scene, -1, scene_param_name, "Box");

	object_build(scene_get_space(scene), object_type_paraboloid, (RT_F4_API){20., 0., 0.}, (RT_F4_API){0., 1., 0.}, 2.);
	scene_edit_param(scene, -1, scene_param_name, "Paraboloid");

	object_build(scene_get_space(scene), object_type_moebius, (RT_F4_API){30., 0., 0.}, 2., 2.);
	scene_edit_param(scene, -1, scene_param_name, "Moebius");

	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){0., 0., 10.}, 3.);
	scene_edit_param(scene, -1, scene_param_name, "Sphere");

	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 0., 10.}, (RT_F4_API){0., 1., 0.});
	scene_edit_param(scene, -1, scene_param_name, "Plane B");

	object_build(scene_get_space(scene), object_type_limited, "Light", "Plane A");
	scene_edit_param(scene, -1, scene_param_name, "Limited");
}

void				scene_test_limited(t_scene *scene)
{
	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){0., 0., 0.}, 3.);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
	scene_edit_param(scene, -1, scene_param_name, "Light");

	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){0., 0., 10.}, 3.);
	scene_edit_param(scene, -1, scene_param_name, "Sphere");
	scene_edit_param(scene, -1, scene_param_texture, "Planet");

//	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 0., 0.}, (RT_F4_API){0., 1., 0.});
//	scene_edit_param(scene, -1, scene_param_name, "Plane A");

	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., -50., 0.}, (RT_F4_API){0., 1., 0.});
	scene_edit_param(scene, -1, scene_param_name, "Plane B");

	object_build(scene_get_space(scene), object_type_cone, (RT_F4_API){-10., -10., 0.}, (RT_F4_API){-10., 10., 0.}, 2.);
	scene_edit_param(scene, -1, scene_param_name, "Cone");

	object_build(scene_get_space(scene), object_type_cylinder, (RT_F4_API){-20., -10., 0.}, (RT_F4_API){-20., 10., 0.}, 2.);
	scene_edit_param(scene, -1, scene_param_name, "Cylinder");

	object_build(scene_get_space(scene), object_type_box, (RT_F4_API) {10., 0., 0.}, (RT_F4_API) {5., 5., 5.});
	scene_edit_param(scene, -1, scene_param_name, "Box");

//	object_build(scene_get_space(scene), object_type_limited, "Cylinder", "Plane A");
//	scene_edit_param(scene, -1, scene_param_name, "Limited");
}

void				scene_test_illumination(t_scene *scene)
{
	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){0., 0., 0.}, 3.);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
	scene_edit_param(scene, -1, scene_param_name, "Light");

	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 0., 0.}, (RT_F4_API){0., 1., 0.});
	scene_edit_param(scene, -1, scene_param_name, "Plane A");
}

void				scene_test_rm(t_scene *scene)
{
	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API) {-5., 0., 0.}, 3.);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
	scene_edit_param(scene, -1, scene_param_name, "Light");

//	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 0., 0.}, (RT_F4_API){1., 0., 0.});
//	scene_edit_param(scene, -1, scene_param_name, "Plane A");
//
//	object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 0., 10.}, (RT_F4_API){0., 1., 0.});
//	scene_edit_param(scene, -1, scene_param_name, "Plane B");
//
	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API) {4., 0., 0.}, 3.);
	scene_edit_param(scene, -1, scene_param_name, "Sphere");
//
//	object_build(scene_get_space(scene), object_type_limited, "Light", "Plane A");
//	scene_edit_param(scene, -1, scene_param_name, "Limited");
//
	object_build(scene_get_space(scene), object_type_box, (RT_F4_API) {10., 0., 0.}, (RT_F4_API) {5., 5., 5.});
	scene_edit_param(scene, -1, scene_param_name, "Box");
//
//	object_build(scene_get_space(scene), object_type_torus, (RT_F4_API){10., 0., 0.}, 1., 1.);
//	scene_edit_param(scene, -1, scene_param_name, "Torus");
//
//	object_build(scene_get_space(scene), object_type_mandelbulb, (RT_F4_API){10., 0., 0.}, 8, 8.);
//
//	object_build(scene_get_space(scene), object_type_julia, (RT_F4_API){10., 0., 0.}, 8, (RT_F4_API){10., 0., 0.});
//
//	object_build(scene_get_space(scene), object_type_explosion, (RT_F4_API){0., 0., 0.}, 3., 3.);
//
//	object_build(scene_get_space(scene), object_type_perforated_cube, (RT_F4_API){10., 0., 0.}, 8);
//
	object_build(scene_get_space(scene), object_type_csg, "Sphere", "Box");
}

void				scene_test_csg(t_scene *scene)
{
	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API) {-5., 0., 0.}, 3.);
	scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
	scene_edit_param(scene, -1, scene_param_name, "Light");

	object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API) {4., 0., 0.}, 3.);
	scene_edit_param(scene, -1, scene_param_name, "Sphere");

	object_build(scene_get_space(scene), object_type_box, (RT_F4_API) {10., 0., 0.}, (RT_F4_API) {5., 5., 5.});
	scene_edit_param(scene, -1, scene_param_name, "Box");

	object_build(scene_get_space(scene), object_type_csg, "Sphere", "Box");
}