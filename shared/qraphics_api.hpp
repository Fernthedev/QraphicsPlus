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
        static void setRefreshRate(std::optional<float> refreshRate) noexcept {
            auto function = CondDep::Find<void, std::optional<float>>("qraphicsplus", "setRefreshRate");

            if (function) {
                function.value()(refreshRate);
                GlobalNamespace::OVRPlugin::set_systemDisplayFrequency(refreshRate.value());
            } else {
                static float initRefreshRate = GlobalNamespace::OVRPlugin::get_systemDisplayFrequency();

                if (refreshRate) {
                    GlobalNamespace::OVRPlugin::set_systemDisplayFrequency(refreshRate.value());
                } else {
                    GlobalNamespace::OVRPlugin::set_systemDisplayFrequency(initRefreshRate);
                }
            }


        }

        /// Sets the CPU level
        /// If null-opt, it will be set to the Qraphics+ configuration
        static void setCPULevel(std::optional<int> cpuLevel) noexcept {
            auto function = CondDep::Find<void, std::optional<int>>("qraphicsplus", "setCPULevel");

            if (function) {
                function.value()(cpuLevel);
                GlobalNamespace::OVRPlugin::set_cpuLevel(cpuLevel.value());
            } else {
                static int initCPULevel = GlobalNamespace::OVRPlugin::get_cpuLevel();

                if (cpuLevel) {
                    GlobalNamespace::OVRPlugin::set_cpuLevel(cpuLevel.value());
                } else {
                    GlobalNamespace::OVRPlugin::set_cpuLevel(initCPULevel);
                }
            }
        }

        /// Sets the GPU level
        /// If null-opt, it will be set to the Qraphics+ configuration
        static void setGPULevel(std::optional<int> gpuLevel) noexcept {
            auto function = CondDep::Find<void, std::optional<int>>("qraphicsplus", "setGPULevel");

            if (function) {
                function.value()(gpuLevel);
                GlobalNamespace::OVRPlugin::set_gpuLevel(gpuLevel.value());
            } else {
                static int initGPULevel = GlobalNamespace::OVRPlugin::get_gpuLevel();

                if (gpuLevel) {
                    GlobalNamespace::OVRPlugin::set_gpuLevel(gpuLevel.value());
                } else {
                    GlobalNamespace::OVRPlugin::set_gpuLevel(initGPULevel);
                }
            }


        }

    };
}