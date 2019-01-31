#include "../src/packedForest/src/packedForest.h"

#include <pybind11/pybind11.h>

#include <string>

namespace py = pybind11;

namespace fp
{

PYBIND11_MODULE(pyfp, m)
{
  py::class_<fpForest<double>>(m, "fpForest")
      .def(py::init<>())
      .def("setParameter",
           py::overload_cast<const std::string &, const std::string &>(&fpForest<double>::setParameter),
           "sets a string parameter")
      .def("setParameter",
           py::overload_cast<const std::string &, const int>(&fpForest<double>::setParameter),
           "sets an int parameter")
      .def("setParameter",
           py::overload_cast<const std::string &, const double>(&fpForest<double>::setParameter),
           "sets a float parameter")
      .def("printParameters", &fpForest<double>::printParameters)
      .def("printForestType", &fpForest<double>::printForestType)
      .def("printForestType", &fpForest<double>::setNumberOfThreads)
      .def("growForest", &fpForest<double>::growForest)
      .def("predict", &fpForest<double>::predict)
      .def("testAccuracy", &fpForest<double>::testAccuracy);
}

} // namespace fp