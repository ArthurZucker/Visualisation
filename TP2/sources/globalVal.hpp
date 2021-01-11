#ifndef GLOBAL_VAL__HPP
#define GLOBAL_VAL__HPP
#include <vtkActor.h>
#include <vtkTubeFilter.h>
extern  vtkActor* Actor;
extern  vtkActor* ActorEdges;
extern vtkDataSetMapper* MapperEdges;
extern vtkTubeFilter* tubes;
extern vtkRenderWindow* RenderWindow_ ;
#endif