
#include "HookTable.h"

namespace sgg {
void HandleAssert(const char *condition, const char *message, const char *file, int line, const char *owner) {
    reinterpret_cast<bool(__fastcall *)(const char *, const char *, const char *, int, const char*)>(
        HookTable::Instance().HandleAssert)(condition, message, file, line, owner);
}
} // namespace sgg
