#ifndef CUSTOM_INTERACTOR__HPP
#define CUSTOM_INTERACTOR__HPP
#include <vtkInteractorStyleTrackballCamera.h>
class CustomInteractor : public vtkInteractorStyleTrackballCamera
{
public:
    static CustomInteractor* New();
    void OnKeyPress () override;
};


#endif