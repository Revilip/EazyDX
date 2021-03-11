#ifndef EAZYDX_H
#define EAZYDX_H
#include <windows.h>
#include "EdImage.h"
#include "EdSprite.h"

typedef void (*EdRenderFunction)();
typedef void (*EdOtherFunction)(HWND,UINT,WPARAM,LPARAM);

bool EdInitialize();
void EdMainLoop();
void EdSetRenderFunction(EdRenderFunction);
void EdSetOtherFunction(EdOtherFunction);

#endif // EAZYDX_H
