cmake_minimum_required(VERSION 3.8)

project(XTLua_Project)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_library(XTLua SHARED ${SOURCE_FILES})

target_compile_definitions(XTLua PUBLIC "XPLM200=1" "XPLM210=1" "XPLM300=1")

target_include_directories(XTLua PUBLIC "include" "${CMAKE_SOURCE_DIR}/../XPlaneSDK/CHeaders/XPLM" "${CMAKE_SOURCE_DIR}/../LuaSDK/include")

set_target_properties(XTLua PROPERTIES PREFIX "")
set_target_properties(XTLua PROPERTIES SUFFIX ".xpl")

if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
	target_compile_definitions(XTLua PUBLIC "IBM=1")

	target_compile_options(XTLua PUBLIC "/MD")

	find_library(XPLM_SDK "XPLM_64.lib" PATHS "${CMAKE_SOURCE_DIR}/../XPlaneSDK/Libraries/Win")
	find_library(LUA_SDK "lua51.lib" PATHS "${CMAKE_SOURCE_DIR}/../LuaSDK/lib")

	target_link_libraries(XTLua PUBLIC ${XPLM_SDK} ${LUA_SDK})

	set_target_properties(XTLua PROPERTIES OUTPUT_NAME "win")

	install(TARGETS XTLua RUNTIME DESTINATION "${CMAKE_SOURCE_DIR}/../deploy/xtlua/64")
elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
	target_compile_definitions(XTLua PUBLIC "LIN=1")

	target_compile_options(XTLua PUBLIC "-fvisibility=hidden" "-fPIC")
	target_link_options(XTLua PUBLIC "-shared" "-rdynamic" "-nodefaultlibs" "-undefined_warning")

	find_library(LUA_SDK "libluajit.a" PATHS "${CMAKE_SOURCE_DIR}/../LuaSDK/lib")
	target_link_libraries(XTLua PUBLIC ${LUA_SDK})

	set_target_properties(XTLua PROPERTIES OUTPUT_NAME "lin")

	install(TARGETS XTLua LIBRARY DESTINATION "${CMAKE_SOURCE_DIR}/../deploy/xtlua/64")
elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL "Darwin")
	target_compile_definitions(XTLua PUBLIC "APL=1")

	find_library(XPLM_SDK "XPLM.framework" PATHS "${CMAKE_SOURCE_DIR}/../XPlaneSDK/Libraries/Mac")
	find_library(LUA_SDK "libluajit_mac.a" PATHS "${CMAKE_SOURCE_DIR}/../LuaSDK/lib")

	target_link_libraries(XTLua PUBLIC ${XPLM_SDK} ${LUA_SDK})

	set_target_properties(XTLua PROPERTIES OUTPUT_NAME "mac")

	install(TARGETS XTLua LIBRARY DESTINATION "${CMAKE_SOURCE_DIR}/../deploy/xtlua/64")
endif()