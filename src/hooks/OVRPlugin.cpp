#include "QraphicsPlus.hpp"
#include "QraphicsPlusConfig.hpp"

#include "GlobalNamespace/OVRPlugin.hpp"

using namespace GlobalNamespace;

MAKE_HOOK_OFFSETLESS(
    OVRPlugin_set_systemDisplayFrequency,
    void,
    OVRPlugin* self,
    float value
) {
    float systemDisplayFrequency = 72.0f;

    switch (getQraphicsPlusConfig().RefreshRate.GetValue()) {
    case 1:
        systemDisplayFrequency = 80.0f;
        break;
    case 2:
        systemDisplayFrequency = 90.0f;
        break;
    case 3:
        systemDisplayFrequency = 120.0f;
        break;
    }

    OVRPlugin_set_systemDisplayFrequency(self, systemDisplayFrequency);
}

void QraphicsPlus::Hooks::OVRPlugin() {
    INSTALL_HOOK_OFFSETLESS(getLogger(), OVRPlugin_set_systemDisplayFrequency, il2cpp_utils::FindMethodUnsafe("", "OVRPlugin", "set_systemDisplayFrequency", 1));
}