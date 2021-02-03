#ifndef CUSTOM_INTERACTOR__HPP
#define CUSTOM_INTERACTOR__HPP
#include <vtkInteractorStyleTrackballCamera.h>
class CustomInteractor : public vtkInteractorStyleTrackballCamera
{
public:
    bool is_transparent = false;
    bool is_wireframe = false;
    static CustomInteractor* New();
    void OnKeyPress () override;
};


#endif