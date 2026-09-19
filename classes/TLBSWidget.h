#pragma once
#include <cstring>

#include "Cursor.h"
#include "Rect.h"
#include "TLBSWidgetList.h"
#include "TObject.h"
#pragma pack(push, 1)

struct TLBSWidget : TObject {
    uint32_t someFlags;             // 0x04 TODO: interactability/input event handling flag
    TLBSWidget* parent;             // 0x08
    TLBSWidget* someChild;          // 0x0C is the last focused for root but random for others
    Rect rect;                      // 0X10
    bool isVisible;                 // 0X18
    bool isInteractable;            // 0x19
    bool isLastInteracted;          // 0x1A
    bool dontBringFront;            // 0x1B obj are rendered in list order, bringFront = don't bubble me up
    char pad_1c[2];                 // 0x1C always 0
    Cursor cursor;                  // 0x1E
    bool useDefaultCursor;          // 0x1F
    TLBSWidgetList* childrenList;   // 0x20

    explicit TLBSWidget(const uintptr_t vTable)
        : TObject(vTable)
        , someFlags(1)
        , parent(nullptr)
        , someChild(nullptr)
        , rect({0, 0, 50, 50})
        , isVisible(true)
        , isInteractable(true)
        , isLastInteracted(false)
        , dontBringFront(false)
        , cursor(Cursor::Nostale)
        , useDefaultCursor(false)
        , childrenList(new TLBSWidgetList())
    {
        std::memset(pad_1c, 0, 2);
    }

    void BubbleUp() {
        if (!parent || !parent->childrenList) {
            return;
        }
        parent->childrenList->bubble_up(this);
    }
    void MoveTo(const int16_t x, const int16_t y) {
        const int16_t incX = x - rect.left;
        const int16_t incY = y - rect.top;
        rect.left += incX;
        rect.right += incX;
        rect.top += incY;
        rect.bottom += incY;
    }
    void MoveUp() {
        if (!parent || !parent->childrenList) {
            return;
        }
        parent->childrenList->move_up(this);
    }
    void MoveDown() {
        if (!parent || !parent->childrenList) {
            return;
        }
        parent->childrenList->move_down(this);
    }
    void ToggleVisibilityRecursively(const bool visibility) {
        isVisible = visibility;
        if (childrenList && childrenList->list) {
            for (uint32_t i = 0; i < childrenList->count; i++) {
                TLBSWidget* child = childrenList->list[i];
                child->ToggleVisibilityRecursively(visibility);
            }
        }
    }

    static constexpr auto ClassName = "TLBSWidget";
    static constexpr uint32_t ExpectedSize = 0x24;
    static constexpr uint32_t Version = 1;
};
static_assert(sizeof(TLBSWidget) == TLBSWidget::ExpectedSize, "TLBSWidget size mismatch (see TLBSWidget::ExpectedSize)");

#pragma pack(pop)
