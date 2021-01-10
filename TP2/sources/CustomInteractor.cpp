#include "CustomInteractor.hpp"
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkAutoInit.h> 
#include <vtkInteractorStyleSwitchBase.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>
#include <string.h>
void	CustomInteractor::OnKeyPress()
{
	std::string key = Interactor->GetKeySym();
    // Here we will insert our event processing (TODO)
    std::cout<<"key = "<<key<<std::endl;
    if (key=="t")
    {
        OutlineActor->GetProperty()->SetOpacity(0.5);
    }
    
    // Now we will refresh the display
    // Assuming your vtkRenderWindow object is named renderWindow_:
    Interactor->GetRenderWindow()->Render();
    vtkInteractorStyle::OnKeyPress();
}