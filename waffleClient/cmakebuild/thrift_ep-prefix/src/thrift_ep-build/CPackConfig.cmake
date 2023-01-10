# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "/tmp/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep;/tmp/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep-build")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENTS_ALL "")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "dev@thrift.apache.org")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/usr/share/cmake-3.22/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "Apache Thrift built using CMake")
set(CPACK_GENERATOR "DEB")
set(CPACK_INSTALL_CMAKE_PROJECTS "/tmp/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep-build;Apache Thrift;ALL;/")
set(CPACK_INSTALL_PREFIX "/tmp/waffle_test/waffleClient/cmakebuild/external/thrift_ep")
set(CPACK_MODULE_PATH ";/tmp/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep/build/cmake")
set(CPACK_NSIS_DISPLAY_NAME "thrift")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "thrift")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OUTPUT_CONFIG_FILE "/tmp/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep-build/CPackConfig.cmake")
set(CPACK_PACKAGE_CONTACT "dev@thrift.apache.org")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/tmp/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep/README.md")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Apache Thrift")
set(CPACK_PACKAGE_FILE_NAME "thrift-0.12.0-Linux")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "thrift")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "thrift")
set(CPACK_PACKAGE_NAME "thrift")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Apache Software Foundation")
set(CPACK_PACKAGE_VERSION "0.12.0")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "2")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_RESOURCE_FILE_LICENSE "/tmp/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep/LICENSE")
set(CPACK_RESOURCE_FILE_README "/usr/share/cmake-3.22/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "/usr/share/cmake-3.22/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_IGNORE_FILES "~$;[.]swp$;/[.]svn/;/[.]git/;.gitignore;/build/;tags;cscope.*")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/tmp/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep-build/CPackSourceConfig.cmake")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "thrift-0.12.0")
set(CPACK_SYSTEM_NAME "Linux")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "Linux")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/tmp/waffle_test/waffleClient/cmakebuild/thrift_ep-prefix/src/thrift_ep-build/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
