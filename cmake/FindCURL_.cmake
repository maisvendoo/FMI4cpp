
find_package(CURL REQUIRED)
find_package(OpenSSL COMPONENTS Crypto SSL)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(CURL_
        REQUIRED_VARS CURL_INCLUDE_DIR CURL_LIBRARY)

if (CURL_FOUND)

    if (NOT TARGET curl::curl)
        add_library(curl::curl UNKNOWN IMPORTED)
        set_property(TARGET curl::curl
                APPEND
                PROPERTY INTERFACE_INCLUDE_DIRECTORIES "${CURL_INCLUDE_DIR}")
        set_property(TARGET curl::curl
                APPEND
                PROPERTY IMPORTED_LOCATION "${CURL_LIBRARY}")
        if (OpenSSL_FOUND)
            set(INTERFACE_LINK_LIBRARIES OpenSSL::SSL OpenSSL::Crypto)
        endif()
        set_property(TARGET curl::curl
                APPEND
                PROPERTY INTERFACE_LINK_LIBRARIES
                ${INTERFACE_LINK_LIBRARIES})
    endif()

endif()