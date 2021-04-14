#include "QraphicsPlus.hpp"
#include "QraphicsPlusConfig.hpp"

#include "GlobalNamespace/BeatmapData.hpp"
#include "GlobalNamespace/FlyingGameHUDRotation.hpp"
#include "GlobalNamespace/FPSCounter.hpp"
#include "GlobalNamespace/FPSCounterUIController.hpp"
#include "GlobalNamespace/GameplayCoreInstaller.hpp"
#include "GlobalNamespace/GameplayCoreSceneSetupData.hpp"
#include "GlobalNamespace/IDifficultyBeatmap.hpp"
#include "UnityEngine/Object.hpp"
#include "UnityEngine/Resources.hpp"
#include "UnityEngine/Transform.hpp"
#include "UnityEngine/Vector3.hpp"

using namespace GlobalNamespace;
using namespace UnityEngine;

Vector3 fpsCounterLocalPositionFlying = { -2.5f, 2.5f, 12.0f };
Vector3 fpsCounterLocalPosition = { -3.2f, 3.2f, 7.0f };

template <typename T>
T GetFirstObjectOfType() {
    auto objects = Resources::FindObjectsOfTypeAll<T>();
    if (objects) {
        return objects->values[0];
    } else {
        return nullptr;
    }
}

MAKE_HOOK_OFFSETLESS(
    GameplayCoreInstaller_InstallBindings,
    void,
    GameplayCoreInstaller* self
) {
    GameplayCoreInstaller_InstallBindings(self);

    if (getQraphicsPlusConfig().Fps.GetValue()) {
        FPSCounterUIController* fpsCounterUI = GetFirstObjectOfType<GlobalNamespace::FPSCounterUIController*>();
        
        if (self->sceneSetupData->difficultyBeatmap->get_beatmapData()->get_spawnRotationEventsCount() > 0) {
            Transform* fpsCounterUITransform = fpsCounterUI->get_transform();

            fpsCounterUITransform->set_localPosition(fpsCounterLocalPositionFlying);
            fpsCounterUITransform->set_parent(GetFirstObjectOfType<GlobalNamespace::FlyingGameHUDRotation*>()->get_transform());
        } else {
            fpsCounterUI->get_transform()->set_localPosition(fpsCounterLocalPosition);

            Object::Instantiate(fpsCounterUI);
        }
    }
}

void QraphicsPlus::Hooks::GameplayCoreInstaller() {
    INSTALL_HOOK_OFFSETLESS(getLogger(), GameplayCoreInstaller_InstallBindings, il2cpp_utils::FindMethodUnsafe("", "GameplayCoreInstaller", "InstallBindings", 0));
}