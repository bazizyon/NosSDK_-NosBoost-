#pragma once
#include <cstdlib>
#include <thread>

#include "TObject.h"
#pragma pack(push, 1)

template<class T>
struct TList : TObject {
    T* list;
    uint32_t count;
    uint32_t capacity;

    [[nodiscard]] TList() : TList(1)
    {}
    [[nodiscard]] explicit TList(const uint32_t Capacity) : TObject(0x47A634), count(0), capacity(Capacity) {
        list = static_cast<T*>(malloc(capacity * sizeof(T)));
    }
    void clear() {
        count = 0;

    }
    void push_back(T item) {
        if (capacity <= count) {
            reserve();
        }
        list[count] = item;
        count += 1;
    }
    void pop_back() {
        if (count <= 0) {
            return;
        }
        count -= 1;
    }
    void remove(T item) {
        bubble_up(item);
        pop_back();
    }
    void reserve() {
        capacity *= 2;

        T* newList = static_cast<T*>(malloc(capacity * sizeof(T)));

        for (int i = 0; i < count; i++) {
            newList[i] = list[i];
        }
        list = newList;
    }
    void move_up(T item) {
        if (!list || count <= 1) return;
        for (uint32_t i = 0; i < count - 1; i++) {
            if (list[i] == item) {
                std::swap(list[i], list[i + 1]);
                return;
            }
        }
    }
    void move_down(T item) {
        if (!list || count <= 1) return;
        for (uint32_t i = 1; i < count; i++) {
            if (list[i] == item) {
                std::swap(list[i], list[i - 1]);
                return;
            }
        }
    }
    void bubble_up(T item) {
        if (!list || count <= 1) {
            return;
        }

        for (uint32_t i = 0; i < count; i++) {
            if (list[i] == item) {
                T tmp = list[i];

                for (uint32_t j = i; j < count - 1; j++) {
                    list[j] = list[j + 1];
                }

                list[count - 1] = tmp;
                return;
            }
        }
    }
    [[nodiscard]] int32_t index_of(T item) const {
        if (!list) return -1;

        for (uint32_t i = 0; i < count; i++) {
            if (list[i] == item) {
                return static_cast<int32_t>(i);
            }
        }
        return -1;
    }
    void move_to_index(T item, uint32_t targetIndex) {
        if (!list || count <= 1) return;

        int32_t currentIndex = index_of(item);
        if (currentIndex < 0) return;

        if (targetIndex >= count) {
            targetIndex = count - 1;
        }

        if (static_cast<uint32_t>(currentIndex) == targetIndex) return;

        T temp = list[currentIndex];

        if (currentIndex < static_cast<int32_t>(targetIndex)) {
            // shift left
            for (uint32_t i = currentIndex; i < targetIndex; i++) {
                list[i] = list[i + 1];
            }
        } else {
            // shift right
            for (int32_t i = currentIndex; i > static_cast<int32_t>(targetIndex); i--) {
                list[i] = list[i - 1];
            }
        }

        list[targetIndex] = temp;
    }
};

static_assert(sizeof(TList<uint32_t>) == 0x10, "TList does not have a size of 0x10");

#pragma pack(pop)
