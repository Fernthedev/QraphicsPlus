#include "QraphicsPlus.hpp"
#include "QraphicsPlusConfig.hpp"
#include "hooks/OVRPlugin.hpp"

#include "GlobalNamespace/OVRPlugin.hpp"

#include "conditional-dependencies/shared/main.hpp"
#include "qraphics_api.hpp"

using namespace GlobalNamespace;

std::optional<float> refreshRateAPI;
std::optional<int> cpuLevelAPI;
std::optional<int> gpuLevelAPI;

EXPOSE_API(setRefreshRate, void, std::optional<float> refreshRate) {
    refreshRateAPI = refreshRate;
}

EXPOSE_API(setGPULevel, void, std::optional<int> gpuLevel) {
    gpuLevelAPI = gpuLevel;
}

EXPOSE_API(setCPULevel, void, std::optional<int> cpuLevel) {
    cpuLevelAPI = cpuLevel;
}

MAKE_HOOK_OFFSETLESS(
    OVRPlugin_set_systemDisplayFrequency,
    void,
    OVRPlugin* self,
    float value
) {
    if (isQuest2 == std::nullopt)
        isQuest2 = std::make_optional(value == 90.0f);

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

    if (refreshRateAPI)
        systemDisplayFrequency = refreshRateAPI.value();

    OVRPlugin_set_systemDisplayFrequency(self, systemDisplayFrequency);
}

MAKE_HOOK_OFFSETLESS(
    OVRPlugin_set_cpuLevel,
    void,
    OVRPlugin* self,
    int value
) {
    int level = getQraphicsPlusConfig().CpuLevel.GetValue();

    if (cpuLevelAPI)
        level = cpuLevelAPI.value();

    OVRPlugin_set_cpuLevel(self, level);
}

MAKE_HOOK_OFFSETLESS(
    OVRPlugin_set_gpuLevel,
    void,
    OVRPlugin* self,
    int value
) {
    int level = getQraphicsPlusConfig().GpuLevel.GetValue();

    if (gpuLevelAPI)
        level = gpuLevelAPI.value();

    OVRPlugin_set_gpuLevel(self, level);
}

void QraphicsPlus::Hooks::OVRPlugin() {
    INSTALL_HOOK_OFFSETLESS(getLogger(), OVRPlugin_set_systemDisplayFrequency, il2cpp_utils::FindMethodUnsafe("", "OVRPlugin", "set_systemDisplayFrequency", 1));
    INSTALL_HOOK_OFFSETLESS(getLogger(), OVRPlugin_set_cpuLevel, il2cpp_utils::FindMethodUnsafe("", "OVRPlugin", "set_cpuLevel", 1));
    INSTALL_HOOK_OFFSETLESS(getLogger(), OVRPlugin_set_gpuLevel, il2cpp_utils::FindMethodUnsafe("", "OVRPlugin", "set_gpuLevel", 1));
}