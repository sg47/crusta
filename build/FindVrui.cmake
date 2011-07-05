#
# Provides
#   VRUI_FOUND
#   VRUI_CFLAGS
#   VRUI_LINKFLAGS
#   VRUI_PLUGINFILEEXT
#   VRUI_PLUGINCFLAGS
#   VRUI_PLUGINLINKFLAGS
#   VRUI_PLUGINHOSTLINKFLAGS
#

# Find the Vrui makeinclude
if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    find_file( VRUI_MAKEINCLUDE Vrui.debug.makeinclude
               PATHS $ENV{VRUI_MAKEINCLUDE} /opt /usr/local /usr
               PATH_SUFFIXES Vrui-2.1/share)
    if( NOT VRUI_MAKEINCLUDE )
        message( WARNING "Debug build type but debug Vrui not found; using non-debug version" )
    endif()
endif()

if( NOT VRUI_MAKEINCLUDE )
    find_file( VRUI_MAKEINCLUDE Vrui.makeinclude
               PATHS $ENV{VRUI_MAKEINCLUDE} /opt /usr/local /usr
               PATH_SUFFIXES Vrui-2.1/share)
endif()

# Macro to extract the content from the makeinclude
macro( EXTRACT_FLAG variable name makeinclude )
    # Get the string corresponding to name
    file( STRINGS ${makeinclude} ${variable}
          LIMIT_COUNT 1
          REGEX "^${name} =.*" )

    # Remove the name and leading whitespace
    string( REGEX REPLACE "^${name} =[ \t]*" "" ${variable} ${${variable}} )

    # Remove trailing whitespace
    if ( ${variable} )
        string( REGEX REPLACE "[ \t]+$"          "" ${variable} ${${variable}} )
    endif()
#message( STATUS "E ${variable}=" ${${variable}} )
endmacro()

macro( STRIP_FLAG variable )
    # Remove -ffriend-injection and -flat_namespace
    if( ${variable} )
        string(REPLACE "-ffriend-injection" "" ${variable} ${${variable}} )
    endif()
    if( ${variable} )
        string(REPLACE "-flat_namespace"    "" ${variable} ${${variable}} )
    endif()
#message( STATUS "S ${variable}=" ${${variable}} )
endmacro()

macro( EXPAND_FLAG variable name value)
    # Replace
    if( ${variable} )
        string( REPLACE "$(${name})" "${value}" ${variable} ${${variable}} )
    endif()
#message( STATUS "X ${variable}=" ${${variable}} )
endmacro()


if( VRUI_MAKEINCLUDE )
    set( VRUI_FOUND TRUE )

    if( NOT VRUI_INCLUDEDIR )
        extract_flag( VRUI_INCLUDEDIR "VRUI_INCLUDEDIR" ${VRUI_MAKEINCLUDE} )
    endif()
    if( NOT VRUI_LIBDIR )
        extract_flag( VRUI_LIBDIR "VRUI_LIBDIR" ${VRUI_MAKEINCLUDE} )
    endif()

    extract_flag( VRUI_CFLAGS              "VRUI_CFLAGS"              ${VRUI_MAKEINCLUDE} )
    strip_flag(   VRUI_CFLAGS                                                               )
    expand_flag(  VRUI_CFLAGS              "VRUI_INCLUDEDIR"          ${VRUI_INCLUDEDIR}  )

    extract_flag( VRUI_LINKFLAGS           "VRUI_LINKFLAGS"           ${VRUI_MAKEINCLUDE} )
    strip_flag(   VRUI_LINKFLAGS                                                            )
    expand_flag(  VRUI_LINKFLAGS           "VRUI_LIBDIR"              ${VRUI_LIBDIR}       )

    extract_flag( VRUI_PLUGINFILEEXT       "VRUI_PLUGINFILEEXT"       ${VRUI_MAKEINCLUDE} )
    extract_flag( VRUI_PLUGINCFLAGS        "VRUI_PLUGINCFLAGS"        ${VRUI_MAKEINCLUDE} )
    extract_flag( VRUI_PLUGINLINKFLAGS     "VRUI_PLUGINLINKFLAGS"     ${VRUI_MAKEINCLUDE} )
    extract_flag( VRUI_PLUGINHOSTLINKFLAGS "VRUI_PLUGINHOSTLINKFLAGS" ${VRUI_MAKEINCLUDE} )
else()
    set( VRUI_FOUND FALSE )
endif()

if( VRUI_FOUND )
    if( NOT Vrui_FIND_QUIETLY )
        message( STATUS "Found Vrui (via " ${VRUI_MAKEINCLUDE} ")" )
    endif()
else()
    if( Vrui_FIND_REQUIRED )
        message( FATAL_ERROR "Required package Vrui NOT FOUND; please specify the path to the Vrui.makeinclude in the VRUI_MAKEINCLUDE variable" )
    endif()
endif()

