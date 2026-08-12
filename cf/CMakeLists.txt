file(GLOB CF_SOURCES CONFIGURE_DEPENDS "*.cpp")

foreach(src ${CF_SOURCES})
    get_filename_component(name ${src} NAME_WE)
    add_executable(${name} ${src})
endforeach()
