#pragma once

#include "GlobalNamespace/OVRPlugin.hpp"
#include "conditional-dependencies/shared/main.hpp"

#include <optional>
#include <functional>
#include <utility>

namespace Qraphics {
    class QraphicsAPI {

        /// Sets the refresh rate of the screen
        /// If null-opt, it will be set to the Qraphics+ configuration
        static void setRefreshRate(int refreshRate) noexcept {
            auto function = CondDep::Find<void, std::optional<int>>("qraphicsplus", "setRefreshRate");

            if (function) {
                function.value()(refreshRate);
            }

            GlobalNamespace::OVRPlugin::set_systemDisplayFrequency(refreshRate);
        }

        /// Sets the CPU level
        /// If null-opt, it will be set to the Qraphics+ configuration
        static void setCPULevel(int cpuLevel) noexcept {
            auto function = CondDep::Find<void, std::optional<int>>("qraphicsplus", "setCPULevel");

            if (function) {
                function.value()(cpuLevel);
            }

            GlobalNamespace::OVRPlugin::set_cpuLevel(cpuLevel);
        }

        /// Sets the GPU level
        /// If null-opt, it will be set to the Qraphics+ configuration
        static void setGPULevel(int gpuLevel) noexcept {
            auto function = CondDep::Find<void, std::optional<int>>("qraphicsplus", "setGPULevel");

            if (function) {
                function.value()(gpuLevel);
            }

            GlobalNamespace::OVRPlugin::set_gpuLevel(gpuLevel);
        }

    };
}