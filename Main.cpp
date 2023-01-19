#define GAC_HEADER_USE_NAMESPACE
#include "UI/Source/HelloGacUI.h"

using namespace vl::collections;
using namespace vl::stream;

void GuiMain()
{
    {
        FileStream fileStream(L"HelloGacUI.bin", FileStream::ReadOnly);
        GetResourceManager()->LoadResourceOrPending(fileStream);
    }
    hellogacui::MainWindow window;
    window.MoveToScreenCenter();
    GetApplication()->Run(&window);
}