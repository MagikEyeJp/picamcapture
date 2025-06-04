#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "mkepicam/mkepicam.h"

namespace py = pybind11;

namespace mkepicam_py {

PYBIND11_MODULE(mkepicam_pybind, m) {
    using namespace mkepicam;

    py::class_<camera_info>(m, "CameraInfo")
        .def_readonly("width", &camera_info::width)
        .def_readonly("height", &camera_info::height)
        .def_readonly("name", &camera_info::name);

    py::class_<Camera>(m, "Camera", py::nodelete)
        .def("get_camera_info", &Camera::get_camera_info)
        .def("open", &Camera::open)
        .def("close", &Camera::close)
        .def("set_exposure", &Camera::set_exposure)
        .def("set_gain", &Camera::set_gain)
        .def("set_flash", &Camera::set_flash);

    m.def("find_camera", py::overload_cast<const char *>(&find_camera),
          py::return_value_policy::reference);
}

} // namespace mkepicam_py
