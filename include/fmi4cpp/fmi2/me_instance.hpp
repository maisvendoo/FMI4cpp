/*
 * The MIT License
 *
 * Copyright 2017-2018 Norwegian University of Technology
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef FMI4CPP_FMI2MODELEXCHANGEINSTANCE_HPP
#define FMI4CPP_FMI2MODELEXCHANGEINSTANCE_HPP

#include <fmi4cpp/fmi2/me_library.hpp>
#include <fmi4cpp/fmi2/xml/me_model_description.hpp>
#include <fmi4cpp/fmu_instance_base.hpp>
#include <fmi4cpp/fmu_resource.hpp>

#include <memory>
#include <vector>

namespace fmi4cpp::fmi2
{

class me_instance : public fmu_instance_base<me_library, me_model_description>
{

public:
    fmi2EventInfo eventInfo_;

    me_instance(fmi2Component c,
        const std::shared_ptr<fmu_resource>& resource,
        const std::shared_ptr<me_library>& library,
        const std::shared_ptr<const me_model_description>& modelDescription);


    bool enter_event_mode();

    bool enter_continuous_time_mode();

    bool set_time(double time);

    bool set_continuous_states(const std::vector<fmi2Real>& x);

    bool get_derivatives(std::vector<fmi2Real>& derivatives);

    bool get_event_indicators(std::vector<fmi2Real>& eventIndicators);

    bool get_continuous_states(std::vector<fmi2Real>& x);

    bool get_nominals_of_continuous_states(std::vector<fmi2Real>& x_nominal);

    bool completed_integrator_step(fmi2Boolean noSetFMUStatePriorToCurrentPoint,
        fmi2Boolean& enterEventMode, fmi2Boolean& terminateSimulation);

    bool new_discrete_states();

    [[nodiscard]] fmi4cpp::status last_status() const override;
};

} // namespace fmi4cpp::fmi2

#endif //FMI4CPP_FMI2MODELEXCHANGEINSTANCE_HPP
