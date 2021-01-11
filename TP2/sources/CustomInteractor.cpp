#include "CustomInteractor.hpp"
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRendererCollection.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkAutoInit.h> 
#include <vtkInteractorStyleSwitchBase.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>
#include <string.h>
#include "globalVal.hpp"
void	CustomInteractor::OnKeyPress()
{
	std::string key = Interactor->GetKeySym();
    // Event processing
    std::cout << "Tubes have now " << tubes->GetOutput()->GetNumberOfPoints() << " points. " <<endl; 
    if (key=="t")
    {
        if (is_transparent){
            is_transparent = false;
            Actor->GetProperty()->SetOpacity(1);
        } 
        else{
            Actor->GetProperty()->SetOpacity(0.5);
            is_transparent = true;
            }
        
    }
    else if (key=="m")
    {
        if (!is_wireframe){
            is_wireframe = true;
            Actor->GetProperty()->SetRepresentationToWireframe();
        } 
        else{
            Actor->GetProperty()->SetRepresentationToSurface ();
            is_wireframe = false;
        }
    }
    else if (key=="g")
    {
        ActorEdges->SetMapper(MapperEdges);
    }
    RenderWindow_->Render();
    std::cout << "Tubes have now " << tubes->GetOutput()->GetNumberOfPoints() << " points. " <<endl; 
    

}