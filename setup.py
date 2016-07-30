#!/usr/bin/env python

from distutils.core import setup
from distutils.extension import Extension

setup(name="IO class",
    ext_modules=[
    Extension("IO", ["IO.cpp"],
    libraries = ["boost_python"])
    ])
