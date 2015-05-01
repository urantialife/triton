#include "core.h"
#include "driver.h"
#include "model.h"

#include <boost/python.hpp>
#include <boost/numpy.hpp>

namespace bp = boost::python;
namespace np = boost::numpy;

BOOST_PYTHON_MODULE(_isaac)
{
  Py_Initialize();
  np::initialize();

  // specify that this module is actually a package
  bp::object package = bp::scope();
  package.attr("__path__") = "_isaac";

  export_driver();
  export_model();
  export_core();
}