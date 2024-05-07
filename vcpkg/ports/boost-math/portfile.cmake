# Automatically generated by scripts/boost/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/math
    REF boost-${VERSION}
    SHA512 5f5aec5c7c2de137fc8b69e33a3f0aa6c18b63292a66508cb68c86d3c1c27455f73432218e90cbd47e919e0be84a6d25af39aa1c4b9a223c013a948c029b7251
    HEAD_REF master
    PATCHES
        build-old-libs.patch
        opt-random.diff
)

set(FEATURE_OPTIONS "")
boost_configure_and_install(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS ${FEATURE_OPTIONS}
)