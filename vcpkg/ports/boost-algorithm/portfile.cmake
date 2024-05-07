# Automatically generated by scripts/boost/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/algorithm
    REF boost-${VERSION}
    SHA512 d7614816293080982df97725e4994aadf62c0215336b74297d9143cae27d253e666256e0a0759bb2b563396d6cc205fbb6bcc54db383add612efdff2168b4b53
    HEAD_REF master
)

set(FEATURE_OPTIONS "")
boost_configure_and_install(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS ${FEATURE_OPTIONS}
)