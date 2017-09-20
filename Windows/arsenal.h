#include "windows.h"
#define WPP_CONTROL_GUIDS \
    WPP_DEFINE_CONTROL_GUID(CtlGuid,(a044090f,3d9d,48cf,b7ee,9fb114702dc1),  \
        WPP_DEFINE_BIT(ERROR)                \
        WPP_DEFINE_BIT(Unusual)              \
        WPP_DEFINE_BIT(Noise)                \
 WPP_DEFINE_BIT(FuncTrace) )
