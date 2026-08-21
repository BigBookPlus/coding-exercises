file(GLOB LUOGU_SOURCES CONFIGURE_DEPENDS "*.cpp")

foreach(src ${LUOGU_SOURCES})
    get_filename_component(name ${src} NAME_WE)
    add_executable(${name} ${src})
endforeach()
