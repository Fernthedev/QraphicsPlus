#include "QraphicsPlus.hpp"
#include "QraphicsPlusConfig.hpp"

#include "GlobalNamespace/FPSCounter.hpp"
#include "GlobalNamespace/FPSCounterUIController.hpp"

using namespace GlobalNamespace;

MAKE_HOOK_OFFSETLESS(
    FPSCounterUIController_Awake,
    void,
    FPSCounterUIController* self
) {
    FPSCounterUIController_Awake(self);

    if (getQraphicsPlusConfig().Fps.GetValue()) {
        self->fpsCounter->set_enabled(true);
    }
}

void QraphicsPlus::Hooks::FPSCounterUIController() {
    INSTALL_HOOK_OFFSETLESS(getLogger(), FPSCounterUIController_Awake, il2cpp_utils::FindMethodUnsafe("", "FPSCounterUIController", "Awake", 0));
}