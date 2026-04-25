# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/CODE/C++/RAYLIB/SWARM SURGE/_deps/raylib-src"
  "E:/CODE/C++/RAYLIB/SWARM SURGE/_deps/raylib-build"
  "E:/CODE/C++/RAYLIB/SWARM SURGE/_deps/raylib-subbuild/raylib-populate-prefix"
  "E:/CODE/C++/RAYLIB/SWARM SURGE/_deps/raylib-subbuild/raylib-populate-prefix/tmp"
  "E:/CODE/C++/RAYLIB/SWARM SURGE/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp"
  "E:/CODE/C++/RAYLIB/SWARM SURGE/_deps/raylib-subbuild/raylib-populate-prefix/src"
  "E:/CODE/C++/RAYLIB/SWARM SURGE/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/CODE/C++/RAYLIB/SWARM SURGE/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/CODE/C++/RAYLIB/SWARM SURGE/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
