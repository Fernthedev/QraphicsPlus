#include "QraphicsPlus.hpp"
#include "QraphicsPlusConfig.hpp"
#include "hooks/OVRPlugin.hpp"

#include "GlobalNamespace/OVRPlugin.hpp"

using namespace GlobalNamespace;

MAKE_HOOK_OFFSETLESS(
    OVRPlugin_set_systemDisplayFrequency,
    void,
    OVRPlugin* self,
    float value
) {
    isQuest2 = value == 90.0f;

    float systemDisplayFrequency = 60.0f;

    switch (getQraphicsPlusConfig().RefreshRate.GetValue()) {
    case 1:
        systemDisplayFrequency = 72.0f;
        break;
    case 2:
        systemDisplayFrequency = 80.0f;
        break;
    case 3:
        systemDisplayFrequency = 90.0f;
        break;
    case 4:
        systemDisplayFrequency = 120.0f;
        break;
    }

    OVRPlugin_set_systemDisplayFrequency(self, systemDisplayFrequency);
}

MAKE_HOOK_OFFSETLESS(
    OVRPlugin_set_cpuLevel,
    void,
    OVRPlugin* self,
    int value
) {
    OVRPlugin_set_cpuLevel(self, getQraphicsPlusConfig().CpuLevel.GetValue());
}

MAKE_HOOK_OFFSETLESS(
    OVRPlugin_set_gpuLevel,
    void,
    OVRPlugin* self,
    int value
) {
    OVRPlugin_set_gpuLevel(self, getQraphicsPlusConfig().GpuLevel.GetValue());
}

void QraphicsPlus::Hooks::OVRPlugin() {
    INSTALL_HOOK_OFFSETLESS(getLogger(), OVRPlugin_set_systemDisplayFrequency, il2cpp_utils::FindMethodUnsafe("", "OVRPlugin", "set_systemDisplayFrequency", 1));
    INSTALL_HOOK_OFFSETLESS(getLogger(), OVRPlugin_set_cpuLevel, il2cpp_utils::FindMethodUnsafe("", "OVRPlugin", "set_cpuLevel", 1));
    INSTALL_HOOK_OFFSETLESS(getLogger(), OVRPlugin_set_gpuLevel, il2cpp_utils::FindMethodUnsafe("", "OVRPlugin", "set_gpuLevel", 1));
}