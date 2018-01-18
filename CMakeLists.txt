cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
project(Taskly VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)
enable_testing()
find_package(Curses REQUIRED)

add_library(${PROJECT_NAME}Lib
	src/view.cpp
)

target_link_libraries(${PROJECT_NAME}Lib
	${CURSES_LIBRARIES}
)

target_include_directories(${PROJECT_NAME}Lib PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
	PRIVATE src/
)

add_executable(${PROJECT_NAME}
	src/app.cpp
)

target_link_libraries(${PROJECT_NAME}
	${PROJECT_NAME}Lib
)

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Config
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT ${PROJECT_NAME}Config DESTINATION share/${PROJECT_NAME}/cmake)

export(TARGETS ${PROJECT_NAME} FILE ${PROJECT_NAME}Config.cmake)