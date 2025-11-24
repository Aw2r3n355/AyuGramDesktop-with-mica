#pragma once

#ifdef Q_OS_WIN
#include <windows.h>

namespace Ayu {
namespace Transparency {

// Enable Mica transparency effect (Windows 11+) with Acrylic fallback (Windows 10)
void EnableMicaTransparency(HWND hwnd);

// Disable Mica transparency effect
void DisableMicaTransparency(HWND hwnd);

} // namespace Transparency
} // namespace Ayu

#else
// Stub for non-Windows platforms
namespace Ayu {
namespace Transparency {
inline void EnableMicaTransparency(void*) {}
inline void DisableMicaTransparency(void*) {}
} // namespace Transparency
} // namespace Ayu
#endif
