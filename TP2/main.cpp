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
#include "sources/CustomInteractor.hpp"

VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);
VTK_MODULE_INIT(vtkRenderingOpenGL2);
vtkStandardNewMacro(CustomInteractor);
using namespace std;
int main(int argc, char const *argv[])
{
	// Quezstion 9 
	vtkPoints *pointSet_ = NULL;
	pointSet_ = vtkPoints::New();
	//vtkNew<vtkPoints> pointSet_;
	// Question 10 
	pointSet_->InsertNextPoint( 1, 0, 0 );
	pointSet_->InsertNextPoint( 0, 1, 0 );
	pointSet_->InsertNextPoint( 0, 0, 1 );
	pointSet_->InsertNextPoint( 0, 0, 0 );
	pointSet_->InsertNextPoint( 0, 0, -1 );
	//(pointSet_)->Print(std::cout);
	// Question 11 
	vtkIdList *IDList_ = NULL;	
	IDList_ = vtkIdList::New();
	IDList_->InsertNextId(0);
	IDList_->InsertNextId(1);
	IDList_->InsertNextId(2);
	IDList_->InsertNextId(3);
	//(IDList_)->Print(std::cout);
	// Question 12
	vtkUnstructuredGrid* grid_ = NULL;
	grid_ = vtkUnstructuredGrid::New();
	grid_->SetPoints(pointSet_);
	grid_->InsertNextCell(VTK_TETRA,IDList_);
	// Question 13 
	vtkIdList *IDList2_ = NULL;	
	IDList2_ = vtkIdList::New();
	IDList2_->InsertNextId(0);
	IDList2_->InsertNextId(1);
	IDList2_->InsertNextId(2);
	IDList2_->InsertNextId(4);
	grid_->InsertNextCell(VTK_TETRA,IDList2_);
	//(grid_)->Print(std::cout);
	// Question 14
	vtkRenderWindow* RenderWindow_ = NULL;
	RenderWindow_ = vtkRenderWindow::New();
	RenderWindow_->SetWindowName("Triangulation");
	RenderWindow_->SetSize(800, 800);
	// Question 15
	//vtkNew<vtkRenderer> Renderer;
	vtkRenderer* Renderer_ = NULL;
	Renderer_ = vtkRenderer::New();
	vtkDataSetMapper* Mapper = NULL;
	Mapper = vtkDataSetMapper::New();
	vtkActor* Actor = NULL;
	Actor = vtkActor::New();
	
	
	Mapper->SetInputData(grid_);
	Actor->SetMapper(Mapper);
	Renderer_->AddActor(Actor);
	RenderWindow_->AddRenderer(Renderer_);
	

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
	return 0;
}
