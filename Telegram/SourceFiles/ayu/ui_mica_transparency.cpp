// Mica Transparency Support for AyuGram
// Add this file to Telegram/SourceFiles/ayu/ui_mica_transparency.cpp
// And include it in the main build system

#include <windows.h>
#include <dwmapi.h>
#include <qt_windows.h>

pragma comment(lib, "dwmapi.lib")
pragma comment(lib, "user32.lib")

namespace Ayu {
namespace Transparency {

// Apply Mica transparency effect to Qt widget
void EnableMicaTransparency(HWND hwnd) {
    if (!hwnd) return;

    // Set the widget to have a transparent background
    BOOL useAlpha = TRUE;
    DwmSetWindowAttribute(
        hwnd,
        DWMWA_USE_IMMERSIVE_DARK_MODE,
        &useAlpha,
        sizeof(useAlpha)
    );

    // For Windows 11+: Enable Mica backdrop
    // Backdrop type 3 = Mica
    int backdropType = 3;
    DwmSetWindowAttribute(
        hwnd,
        38, // DWMWA_SYSTEMBACKDROP_TYPE
        &backdropType,
        sizeof(backdropType)
    );

    // Enable Acrylic blur for Windows 10
    ACCENT_POLICY accent = {ACCENT_ENABLE_BLURBEHIND, 0, 0, 0};
    WINDOWCOMPOSITIONATTRIBDATA data = {
        WCA_ACCENT_POLICY,
        &accent,
        sizeof(accent)
    };
    SetWindowCompositionAttribute(hwnd, &data);
}

void DisableMicaTransparency(HWND hwnd) {
    if (!hwnd) return;
    
    BOOL useAlpha = FALSE;
    DwmSetWindowAttribute(
        hwnd,
        DWMWA_USE_IMMERSIVE_DARK_MODE,
        &useAlpha,
        sizeof(useAlpha)
    );
}

} // namespace Transparency
} // namespace Ayu
