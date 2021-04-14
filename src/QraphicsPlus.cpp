#include "QraphicsPlus.hpp"
#include "QraphicsPlusConfig.hpp"
#include "hooks/MainFlowCoordinator.hpp"
#include "hooks/MainSystemInit.hpp"
#include "hooks/OVRPlugin.hpp"

#include "GlobalNamespace/OVRPlugin.hpp"

using namespace GlobalNamespace;
using namespace QuestUI;
using namespace UnityEngine;

DEFINE_TYPE(QraphicsPlus::QraphicsPlusViewController);

// This isn't really ideal, but it works. So, whatever...
std::vector<std::string> refreshRates = {"60 Hz", "72 Hz", "80 Hz", "90 Hz", "120 Hz"};

void QraphicsPlus::Install() {
    custom_types::Register::RegisterTypes<
        QraphicsPlusViewController
    >();
    
    QuestUI::Register::RegisterModSettingsViewController<QraphicsPlusViewController*>(ModInfo{"Qraphics+", VERSION});

    Hooks::FPSCounterUIController();
    Hooks::GameplayCoreInstaller();
    Hooks::MainFlowCoordinator();
    Hooks::MainSystemInit();
    Hooks::MainSettingsModelSO();
    Hooks::OVRPlugin();
    Hooks::ParametricBoxFakeGlowController();
}

void QraphicsPlus::QraphicsPlusViewController::DidActivate(
    bool firstActivation,
    bool addedToHierarchy,
    bool screenSystemEnabling
) {
    if (firstActivation) {
        GameObject* container = BeatSaberUI::CreateScrollableSettingsContainer(get_transform());

        AddConfigValueIncrementFloat(container->get_transform(), getQraphicsPlusConfig().Resolution, 1, 0.1f, 0.5f, 1.5f);
        if (isQuest2) {
            BeatSaberUI::CreateDropdown(container->get_transform(), "Refresh Rate", refreshRates[getQraphicsPlusConfig().RefreshRate.GetValue()], refreshRates,
                [](std::string value) {
                    getQraphicsPlusConfig().RefreshRate.SetValue(std::distance(refreshRates.begin(), std::find(refreshRates.begin(), refreshRates.end(), value)));
                    
                    // Force OVRPlugin to read our config.
                    OVRPlugin::set_systemDisplayFrequency(0);
                    OVRPlugin::set_cpuLevel(0);
                    OVRPlugin::set_gpuLevel(0);
                });
        }
        AddConfigValueIncrementInt(container->get_transform(), getQraphicsPlusConfig().CpuLevel, 1, 0, 2);
        AddConfigValueIncrementInt(container->get_transform(), getQraphicsPlusConfig().GpuLevel, 1, 0, 2);
        AddConfigValueToggle(container->get_transform(), getQraphicsPlusConfig().EnhancedFakeGlow);
        AddConfigValueToggle(container->get_transform(), getQraphicsPlusConfig().BurnMarks);
        AddConfigValueToggle(container->get_transform(), getQraphicsPlusConfig().Smoke);
        AddConfigValueToggle(container->get_transform(), getQraphicsPlusConfig().Fps);
    }
}

void QraphicsPlus::QraphicsPlusViewController::DidDeactivate(
    bool removedFromHierarchy,
    bool screenSystemDisabling
) {
    if (mainSettingsModel && menuTransitionsHelper) {
        mainSettingsModel->Load(true);
        menuTransitionsHelper->RestartGame(nullptr);
    }
}