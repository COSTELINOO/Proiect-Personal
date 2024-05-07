# Automatically generated by scripts/boost/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/stacktrace
    REF boost-${VERSION}
    SHA512 aa5c7ffd3ecc7d737399159aaa1dd675fe0da5621d4229a268c0413196e4f9172c151c8cc211df238d801dc6f7ac47efc8a453462c62c81c5c739b5c4b6c111f
    HEAD_REF master
    PATCHES
        fix_config-check.diff
)

set(FEATURE_OPTIONS "")
include("${CMAKE_CURRENT_LIST_DIR}/features.cmake")
boost_configure_and_install(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS ${FEATURE_OPTIONS}
)