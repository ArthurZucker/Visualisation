#include <iostream>
#include <vtkPoints.h>
#include <vtkIdList.h>
#include <vtkPointSet.h>
#include <vtkUnstructuredGrid.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkAutoInit.h> 
#include <vtkInteractorStyleSwitchBase.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkFeatureEdges.h>
#include <vtkGeometryFilter.h>
#include <vtkPolyDataNormals.h>
#include <vtkTubeFilter.h>
#include <vtkPolyDataMapper.h>
#include "sources/CustomInteractor.hpp"
#include "sources/globalVal.hpp"
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);
VTK_MODULE_INIT(vtkRenderingOpenGL2);
vtkStandardNewMacro(CustomInteractor);
using namespace std;
// global values used with Custom Interactor
vtkActor* Actor = NULL;
vtkActor* ActorEdges = NULL;
vtkDataSetMapper* MapperEdges = NULL;
vtkTubeFilter* tubes = NULL;
vtkRenderWindow* RenderWindow_ = NULL;
int main(int argc, char const *argv[])
{
	// Quezstion 9 
	vtkPoints *pointSet_ = NULL;
	pointSet_ = vtkPoints::New();
	//vtkNew<vtkPoints> pointSet_;
	// Question 10 
	vtkIdType id0 = pointSet_->InsertNextPoint( 0, 0, 1 );
	vtkIdType id1 = pointSet_->InsertNextPoint( 0, 1, 0 );
	vtkIdType id2 = pointSet_->InsertNextPoint( 1, 0, 0 );
	vtkIdType id3 = pointSet_->InsertNextPoint( 0, 0, 0 );
	vtkIdType id4 = pointSet_->InsertNextPoint( 0, 0, -1 );
	//(pointSet_)->Print(std::cout);
	// Question 11 
	vtkIdList *IDList_ = NULL;	
	IDList_ = vtkIdList::New();
	IDList_->InsertNextId(id0);
	IDList_->InsertNextId(id1);
	IDList_->InsertNextId(id2);
	IDList_->InsertNextId(id3);
	//(IDList_)->Print(std::cout);
	// Question 12
	vtkUnstructuredGrid* grid_ = NULL;
	grid_ = vtkUnstructuredGrid::New();
	grid_->SetPoints(pointSet_);
	grid_->InsertNextCell(VTK_TETRA,IDList_);
	// Question 13 
	vtkIdList *IDList2_ = NULL;	
	IDList2_ = vtkIdList::New();
	IDList2_->InsertNextId(id1);
	IDList2_->InsertNextId(id2);
	IDList2_->InsertNextId(id3);
	IDList2_->InsertNextId(id4);
	grid_->InsertNextCell(VTK_TETRA,IDList2_);
	//(grid_)->Print(std::cout);
	// Question 14
	
	RenderWindow_ = vtkRenderWindow::New();
	RenderWindow_->SetWindowName("Triangulation");
	RenderWindow_->SetSize(800, 800);
	// Question 15
	//vtkNew<vtkRenderer> Renderer;
	vtkRenderer* Renderer_ = NULL;
	Renderer_ = vtkRenderer::New();
	vtkDataSetMapper* Mapper = NULL;
	Mapper = vtkDataSetMapper::New();
	Actor = vtkActor::New();
	
	
	Mapper->SetInputData(grid_);
	Actor->SetMapper(Mapper);
	//Renderer_->AddActor(Actor);
	
	

	// Question 16
	vtkRenderWindowInteractor* Interactor = NULL;
	Interactor = vtkRenderWindowInteractor::New();
	Interactor->SetRenderWindow(RenderWindow_);
	

	// Question 17 
	vtkInteractorStyleTrackballCamera* InteractorStyle = NULL;
	InteractorStyle = vtkInteractorStyleTrackballCamera::New();
	Interactor->SetInteractorStyle(InteractorStyle);
	// This allows for a way more intuitive camera control

	// Question 18 
	// It is obvious that we need to use inheritance, create a new
	// class which will inherit from vtkInteractor class

	// Question 19 
	CustomInteractor* CustomInteractorStyle = NULL;
	CustomInteractorStyle = CustomInteractor::New();
	Interactor->SetInteractorStyle(CustomInteractorStyle);

	
	// Question 23
	vtkGeometryFilter* filter = NULL;
	filter = vtkGeometryFilter::New();
	vtkPolyDataNormals* normals = NULL;
	normals = vtkPolyDataNormals::New();
	vtkFeatureEdges* edges = NULL;
	edges = vtkFeatureEdges::New();
	tubes = vtkTubeFilter::New();
	MapperEdges = vtkDataSetMapper::New();
	ActorEdges = vtkActor::New();
	vtkPolyDataMapper* polyMapper = NULL;
	polyMapper = vtkPolyDataMapper::New();


	filter->SetInputData(grid_);
	normals->SetInputConnection(filter->GetOutputPort());
	
	edges->AddInputConnection(0,normals->GetOutputPort());
	edges->SetInputConnection(0,filter->GetOutputPort());
	tubes->SetInputConnection(edges->GetOutputPort());
	tubes->SetRadius(0.025);
	tubes->SetNumberOfSides(10);
	polyMapper->SetInputConnection(tubes->GetOutputPort());
	MapperEdges->SetInputConnection(tubes->GetOutputPort());
	
	Renderer_->AddActor(ActorEdges);
	Renderer_->AddActor(Actor);
	RenderWindow_->AddRenderer(Renderer_);
	RenderWindow_->Render();	
	Interactor->Start();
	// Memory clear
	(*pointSet_).Delete();
	(*IDList_).Delete();
	(*grid_).Delete();
	(*IDList2_).Delete();
	(*RenderWindow_).Delete();
	(*Renderer_).Delete();
	(*Mapper).Delete();
	(*Actor).Delete();
	(*Interactor).Delete();
	(*InteractorStyle).Delete();
	(*filter).Delete();
	(*normals).Delete();
	(*edges).Delete();
	(*tubes).Delete();
	(*MapperEdges).Delete();
	(*ActorEdges).Delete();
	(*polyMapper).Delete();
	return 0;
}
