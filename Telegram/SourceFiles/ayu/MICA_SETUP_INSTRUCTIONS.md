# Mica Transparency Setup for AyuGram

## Quick Setup (Самый быстрый способ)

Эти файлы добавляют поддержку Mica прозрачности для Windows 11+ с fallback на Acrylic для Windows 10.

### Файлы добавлены:
- `ui_mica_transparency.h` - Заголовочный файл
- `ui_mica_transparency.cpp` - Реализация Windows API вызовов

### Способ 1: Минимальное редактирование (РЕКОМЕНДУЕТСЯ)

**Шаг 1:** Отредактируй `Telegram/SourceFiles/window/main_window.cpp`

В начале файла (после других #include), добавь:
```cpp
#include "ayu/ui_mica_transparency.h"
```

**Шаг 2:** Найди функцию `MainWindow::init()` (примерно строка 800+)

После строки `refreshTitleWidget();` добавь:
```cpp
#ifdef Q_OS_WIN
    Ayu::Transparency::EnableMicaTransparency((HWND)winId());
#endif
```

### Способ 2: Через CMakeLists.txt

Отредактируй `Telegram/CMakeLists.txt`

Найди секцию где перечислены источники (SOURCES) и добавь:
```cmake
Telegram/SourceFiles/ayu/ui_mica_transparency.cpp
Telegram/SourceFiles/ayu/ui_mica_transparency.h
```

Когда компилируешь, CMake автоматически подключит файлы.

### Способ 3: Без изменений (Самый быстрый)

1. Просто скомпилируй проект как есть
2. Файлы будут доступны для использования
3. Позже можешь добавить вызовы `EnableMicaTransparency()` где нужно

## Как это работает

- `EnableMicaTransparency(HWND)` - Включает Mica эффект на Windows 11+, Acrylic на Windows 10
- `DisableMicaTransparency(HWND)` - Отключает эффект
- На других платформах функции - stub (пусты)

## Компиляция

```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

## Тестирование

1. Скомпилированный AyuGram получит поддержку Mica
2. При запуске окно будет прозрачным
3. Mica for Everyone автоматически применит эффект

## Заметки

- Прозрачность работает только на Windows
- Функции безопасны для вызова на всех платформах (использованы #ifdef)
- Требует обновленные DWM (Desktop Window Manager)
