# Ray Tracer

This ray tracer is the final project of the graphic branch at School 21 (Ecole 42).

  <img src="https://sun9-58.userapi.com/c858032/v858032547/c033f/nsIpjWCjI3Y.jpg">

## Introduction

Ray tracing - is a way to create (render) 3D pictures with realistic lights and shadows. Ray tracing technique used in computer games, cartoons, graphic editors and etc.  

[Algorithm description](https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-ray-tracing/implementing-the-raytracing-algorithm "algorithm") </br>
[About ray tracing on wiki](https://en.wikipedia.org/wiki/Ray_tracing_(graphics) "Ray tracing (graphics)")

## Features

### Renderer
* Path tracing + area light
* Ray marching
* Interpolated background
* Illumination
* Reflection
* Transparency
* Texture on basic objects
* Disruptions: perlin noise, sinewave and checkerboard texture

### Objects
* Basic objects: sphere, plane, cylinder, cone
* Box
* Limited objects: half-sphere, half-box and etc.
* Negative objects (CSG)
* Torus
* Paraboloid
* Moebius ribbon
* Explosion
* 3D fractals: mandelbulb, julia, perforated cube

### Camera
* Filters: cartoon effect, sepia
* Stereoscopy
* Motion blur
* Focus (depth of field)

### Interface
* Scenes handle in JSON
* It's possible to make screenshots
* Camera management
* Editing, creating and deleting objects
* Renderer management: tracing type, lightning mod and etc.

### Our own algorithms:
* [Illumination](https://github.com/belchenkovova/21_ray_tracer/blob/master/cl_renderer/cl_source/cl_illumination "illumination source")
* [Calculation of limited objects](https://github.com/belchenkovova/21_ray_tracer/blob/master/cl_renderer/cl_source/cl_object_limited "limited object intersection source")

### Technical environment
* Parallel computing on GPU (OpenCl)
* The interface is written using GTK

## Compilation
```bash
$> make
$>./RT
```
Make sure that you have gtk+3, pkg-config and glade. If not use homebrew for installation:
```bash
$> brew install gtk+3
$> brew install pkg-config
$> brew install glade
```

## Resourses
* [Physically Based Rendering](https://www.pbrt.org/ "PBRT Book") - describes both the mathematical theory behind a modern photorealistic rendering system as well as its practical implementation</br>
* [Scratchapixel](https://www.scratchapixel.com/ "scratchapixel") - amazing tutorials (from basic lightning to Monte Carlo Methods)</br>
* [Inigo Quilez](https://www.iquilezles.org/www/index.htm "inigo Quilez") - articles, tutorials, code, and presentations related to maths, fractals, demoscene and computer graphics</br>
* [Shadertoy](https://www.shadertoy.com/user/iq "shadertoy") - is a cross-browser online community and tool for creating and sharing shaders through WebGL</br>
* [Fractal forums](http://www.fractalforums.com/ "fractal forum") - crazy place, where magic and fractals lives

## More images

**Hypercomplex fractal** - is a three-dimensional [fractal](http://bugman123.com/Hypercomplex/ "fractal").

<p align="center">
  <img src="https://sun9-49.userapi.com/c858036/v858036068/e3acb/kqalQPVhXCw.jpg" width="48%" align="left"/>
  <img src="https://sun9-65.userapi.com/c858036/v858036068/e3ad5/Qt99h4jCl34.jpg" width="48%"/>
</p>

**Path tracing** - improved ray tracing algorithm. The basic idea is to simulate the path of a ray of light. As a result, objects cast not only shadow, but also color. Example: on a white wall, we will see a little bit of red if a red object is standing nearby. </br>

<p align="center">
  <img src="https://sun9-27.userapi.com/c858228/v858228068/e8297/lybbvCrZVCg.jpg" width="48%" align="left"/>
  <img src="https://sun9-4.userapi.com/c858228/v858228068/e828d/_JzTW0Fs8Xo.jpg" width="48%"/>
</p>

**Raymarching** is a technique a bit like traditional raytracing where the surface function is not easy to solve (or impossible without numeric iterative methods). In raytracing you just look up the ray intersection, whereas in ray marching you march forward (or back and forth) until you find the intersection, have enough samples or whatever it is your trying to solve. 

<p align="center">
  <img src="https://sun9-10.userapi.com/c858228/v858228068/e83b0/3cvDKmMibpM.jpg" width="48%" align="left"/>
  <img src="https://sun9-42.userapi.com/c858228/v858228068/e83ba/eK_9cH5sCVw.jpg" width="48%"/>
</p>

## Authors
[Vladimir Belchenko](https://github.com/belchenkovova "belchenkovova") </br>
[Elena Orlova](https://github.com/elenaorlova "elenaorlova") </br>
[Alexey Prigorovsky](https://github.com/Lyahasik "Lyahasik")
