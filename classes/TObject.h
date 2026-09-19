#pragma once
#pragma pack(push, 1)

struct TObject {
    uintptr_t vTable;
    explicit TObject(const uintptr_t vTableAddr) : vTable(vTableAddr) {}
};

static_assert(sizeof(TObject) == 0x04, "TObject size mismatch");

#pragma pack(pop)