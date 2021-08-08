from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext
from pybind11 import get_cmake_dir

import sys

__version__ = "0.0.1"

ext_modules = [
    Pybind11Extension("cerel",
        ["main.cpp"],
        define_macros = [('VERSION_INFO', __version__)],
        ),
]

setup(
    name="cerel",
    version=__version__,
    author="Mithlesh kumar",
    author_email="mithlesh.kumarsingh96@gmail.com",
    # url="https://github.com/pybind/python_example",
    description="A test project using pybind11",
    long_description="",
    ext_modules=ext_modules,
    # extras_require={"test": "pytest"},
    # Currently, build_ext only provides an optional "highest supported C++
    # level" feature, but in the future it may provide more features.
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
)
