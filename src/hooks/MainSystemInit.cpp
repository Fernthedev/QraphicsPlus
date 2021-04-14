#include "QraphicsPlus.hpp"
#include "QraphicsPlusConfig.hpp"
#include "hooks/MainSystemInit.hpp"

#include "GlobalNamespace/MainSystemInit.hpp"

using namespace GlobalNamespace;

MAKE_HOOK_OFFSETLESS(
    MainSystemInit_Init,
    void,
    MainSystemInit* self
) {
    mainSettingsModel = self->mainSettingsModel;

    MainSystemInit_Init(self);
}

void QraphicsPlus::Hooks::MainSystemInit() {
    INSTALL_HOOK_OFFSETLESS(getLogger(), MainSystemInit_Init, il2cpp_utils::FindMethodUnsafe("", "MainSystemInit", "Init", 0));
}