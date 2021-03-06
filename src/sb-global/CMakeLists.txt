# Copyright (C) 2014-2015 Bastien Oudot and Romain Guillemot
#
# This file is part of Softbloks.
# Softbloks is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Softbloks is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with Softbloks.  If not, see <http://www.gnu.org/licenses/>.

include(WriteCompilerDetectionHeader)

write_compiler_detection_header(
    FILE "${CMAKE_CURRENT_BINARY_DIR}/sb-compilerdetection.h"
    PREFIX SB
    COMPILERS
        GNU
        MSVC
    FEATURES
        cxx_constexpr
        cxx_deleted_functions
        cxx_final
        cxx_nullptr
        cxx_override
        cxx_static_assert
)

configure_file(
    sb-version.h.in
    "${CMAKE_CURRENT_BINARY_DIR}/sb-version.h"
    @ONLY
)

sb_add_header_only_target(sb-global
    sb-any.h
    sb-bitmask.h
    sb-global.h
    sb-globaldefine.h
    "${CMAKE_CURRENT_BINARY_DIR}/sb-compilerdetection.h"
    "${CMAKE_CURRENT_BINARY_DIR}/sb-version.h"
)

target_include_directories(sb-global INTERFACE
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/src> # sb-version.h
)
install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/sb-compilerdetection.h"
        "${CMAKE_CURRENT_BINARY_DIR}/sb-version.h"
    DESTINATION
        ${SB_INSTALL_INCLUDE_DESTINATION}/sb-global
)
