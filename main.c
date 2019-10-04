#include "gui.h"
#include "gui_signal_connect_x.h"
#include "cl_renderer.h"
#include "material_list.h"

// todo: switch off the illumination

void				scene_mandelbulb(t_scene *scene, t_camera *camera);
void				scene_julia(t_scene *scene, t_camera *camera);
void				scene_perforated_cube(t_scene *scene, t_camera *camera);
void				scene_explosion(t_scene *scene, t_camera *camera);
void				scene_csg(t_scene *scene, t_camera *camera);
void				scene_box_default(t_scene *scene, t_camera *camera);

void				scene_moebius(t_scene *scene);
void				scene_spheres(t_scene *scene);

int					main(int argc, char **argv)
{
    t_gui			*gui;

    gui = gui_new(&argc, &argv);
    gui_signal_connect_all(gui);
    gui->renderer = cl_renderer_new(gui->image);
    scene_box_default(gui->renderer->data.scene, gui->renderer->data.camera);
    //scene_moebius(gui->renderer->data.scene);
    scene_spheres(gui->renderer->data.scene);
    cl_renderer_change_tracing_mod(gui->renderer, rt_tracing_rt);
    cl_renderer_change_light_mod(gui->renderer, rt_light_area);
    camera_apply(gui->renderer->data.camera);
    cl_renderer_camera_save(gui->renderer);
    scene_update(gui->renderer->data.scene);
    gui_connect(gui);
    gui_update(gui);
    gui_loop(gui);
    gui_delete(&gui);
    return (0);
}

void				scene_spheres(t_scene *scene)
{
    object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){4., 2., -84.}, 12.);
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_MIRROR);
    scene_edit_param(scene, -1, scene_param_name, "Sphere Mirror");

    object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){-3., 10., -50.}, 12.);
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_GLASS);
    scene_edit_param(scene, -1, scene_param_name, "Sphere Glass");
}

void				scene_moebius(t_scene *scene)
{
    object_build(scene_get_space(scene), object_type_moebius, (RT_F4_API){0., 15., -30.}, 8., 6.);
    scene_edit_param(scene, -1, scene_param_name, "Moebius Ribbon");
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_RED);
}

void				scene_box_default(t_scene *scene, t_camera *camera)
{
    object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){17., 40., -16.}, 3.);
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
    scene_edit_param(scene, -1, scene_param_name, "Light");

    object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 0., -140.}, (RT_F4_API){0., 0., 1.});
    scene_edit_param(scene, -1, scene_param_name, "Plane Back");

    object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){-40., 0., 0.}, (RT_F4_API){-1., 0., 0.});
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_DEEP_BLUE);
    scene_edit_param(scene, -1, scene_param_name, "Plane Left");

    object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){40., 0., 0.}, (RT_F4_API){-1., 0., 0.});
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_NEW_BLUE);
    scene_edit_param(scene, -1, scene_param_name, "Plane Right");

    object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 0., 200.}, (RT_F4_API){0., 0., -1.});
    scene_edit_param(scene, -1, scene_param_name, "Plane Front");

    object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 70., 0.}, (RT_F4_API){0., -1., 0.});
    scene_edit_param(scene, -1, scene_param_name, "Plane Up");

    object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., -25., 0.}, (RT_F4_API){0., 1., 0.});
    scene_edit_param(scene, -1, scene_param_name, "Plane Down");

    camera->position.y = 20;
    camera->position.z = 150;
}

void				scene_csg(t_scene *scene, t_camera *camera)
{
    object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){0., 12., 60.}, 3.);
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
    scene_edit_param(scene, -1, scene_param_name, "Light");
    object_build(scene_get_space(scene), object_type_light_point, (RT_F4_API){0., 12., 90.});
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
    scene_edit_param(scene, -1, scene_param_name, "Light Point");
    object_build(scene_get_space(scene), object_type_light_ambient, (RT_F4_API){0., 10., 0.}, 3.);

    object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 0., -50.}, (RT_F4_API){0., 0., 1.});
    scene_edit_param(scene, -1, scene_param_name, "Plane Back");
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_WHITE);

    object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){3., 2., 5.}, 5.);
    scene_edit_param(scene, -1, scene_param_name, "Sphere");
    object_build(scene_get_space(scene), object_type_box, (RT_F4_API) {7., 2., 3.}, (RT_F4_API) {5., 5., 5.});
    scene_edit_param(scene, -1, scene_param_name, "Box");

    object_build(scene_get_space(scene), object_type_csg, "Box", "Sphere");
    camera->position.z = 90;
}

void				scene_explosion(t_scene *scene, t_camera *camera)
{
    object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){0., 10., 20.}, 3.);
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
    scene_edit_param(scene, -1, scene_param_name, "Light");
    object_build(scene_get_space(scene), object_type_light_point, (RT_F4_API){0., 10., 30.});
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
    scene_edit_param(scene, -1, scene_param_name, "Light Point");
    object_build(scene_get_space(scene), object_type_light_ambient, (RT_F4_API){0., 10., 0.}, 3.);

    object_build(scene_get_space(scene), object_type_explosion, (RT_F4_API){0., 0., 0.}, 3., 3.);
    camera->position.z = 20;
}

void				scene_perforated_cube(t_scene *scene, t_camera *camera)
{
    object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){0., 10., 20.}, 3.);
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
    scene_edit_param(scene, -1, scene_param_name, "Light");
    object_build(scene_get_space(scene), object_type_light_point, (RT_F4_API){0., 10., 30.});
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
    scene_edit_param(scene, -1, scene_param_name, "Light Point");
    object_build(scene_get_space(scene), object_type_light_ambient, (RT_F4_API){0., 10., 0.}, 3.);

    object_build(scene_get_space(scene), object_type_plane, (RT_F4_API){0., 0., -50.}, (RT_F4_API){0., 0., 1.});
    scene_edit_param(scene, -1, scene_param_name, "Plane Back");
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_BLACK);

    object_build(scene_get_space(scene), object_type_perforated_cube, (RT_F4_API){0., 0., 3.}, 5);
    scene_edit_param(scene, -1, scene_param_name, "Perforated Cube");

    camera->position.z = 10;
}

void                scene_julia(t_scene *scene, t_camera *camera)
{
    object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){0., 10., 20.}, 3.);
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
    scene_edit_param(scene, -1, scene_param_name, "Light");
    object_build(scene_get_space(scene), object_type_light_point, (RT_F4_API){0., 10., 30.});
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
    scene_edit_param(scene, -1, scene_param_name, "Light Point");
    object_build(scene_get_space(scene), object_type_light_ambient, (RT_F4_API){0., 10., 0.}, 3.);

    object_build(scene_get_space(scene), object_type_julia, (RT_F4_API){0., 0., 0.}, 5, (RT_F4_API){0.1, 0.5, 0.8, 0.1});
    scene_edit_param(scene, -1, scene_param_name, "Julia");

    camera->position.z = 10;
}

void                scene_mandelbulb(t_scene *scene, t_camera *camera)
{
    object_build(scene_get_space(scene), object_type_sphere, (RT_F4_API){0., 10., 20.}, 3.);
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
    scene_edit_param(scene, -1, scene_param_name, "Light");

    object_build(scene_get_space(scene), object_type_light_point, (RT_F4_API){0., 10., 30.});
    scene_edit_param(scene, -1, scene_param_material, MATERIAL_LIGHT);
    scene_edit_param(scene, -1, scene_param_name, "Light Point");

    object_build(scene_get_space(scene), object_type_light_ambient, (RT_F4_API){0., 10., 0.}, 3.);

    object_build(scene_get_space(scene), object_type_mandelbulb, (RT_F4_API){0., 0., 0.}, 5, 8.);
    scene_edit_param(scene, -1, scene_param_name, "Mandelbulb");

    camera->position.z = 10;
}
