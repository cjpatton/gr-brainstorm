# Copyright 2011 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.

########################################################################
# Setup library
########################################################################
include(GrPlatform) #define LIB_SUFFIX

add_library(gnuradio-foo SHARED foo_peak_fv.cc foo_wait_vv.cc
foo_ct_source_f.cc)
target_link_libraries(gnuradio-foo ${Boost_LIBRARIES} ${GRUEL_LIBRARIES} ${GNURADIO_CORE_LIBRARIES})
set_target_properties(gnuradio-foo PROPERTIES DEFINE_SYMBOL "gnuradio_foo_EXPORTS")

########################################################################
# Install built library files
########################################################################
install(TARGETS gnuradio-foo
    LIBRARY DESTINATION lib${LIB_SUFFIX} # .so/.dylib file
    ARCHIVE DESTINATION lib${LIB_SUFFIX} # .lib file
    RUNTIME DESTINATION bin              # .dll file
)

########################################################################
# Build and register unit test
########################################################################
find_package(Boost COMPONENTS unit_test_framework)

include(GrTest)
set(GR_TEST_TARGET_DEPS gnuradio-foo)
#turn each test cpp file into an executable with an int main() function
add_definitions(-DBOOST_TEST_DYN_LINK -DBOOST_TEST_MAIN)

add_executable(qa_foo_peak_fv qa_foo_peak_fv.cc)
target_link_libraries(qa_foo_peak_fv gnuradio-foo ${Boost_LIBRARIES})
GR_ADD_TEST(qa_foo_peak_fv qa_foo_peak_fv)

add_executable(qa_foo_wait_vv qa_foo_wait_vv.cc)
target_link_libraries(qa_foo_wait_vv gnuradio-foo ${Boost_LIBRARIES})
GR_ADD_TEST(qa_foo_wait_vv qa_foo_wait_vv)
