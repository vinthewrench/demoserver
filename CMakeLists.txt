SET (CMAKE_C_COMPILER             "clang")
SET (CMAKE_CXX_COMPILER            "clang++")


cmake_minimum_required(VERSION 3.0)

project(demoserver)

set(SOURCES
	src/main.cpp
	src/ServerNouns.cpp

	Submodule/FooServer/src/RESTutils.cpp
	Submodule/FooServer/src/ServerCmdQueue.cpp
	Submodule/FooServer/src/TCPClientInfo.cpp
	Submodule/FooServer/src/TCPServer.cpp
	Submodule/FooServer/src/REST/http_parser.c
	Submodule/FooServer/src/REST/REST_URL.cpp
	Submodule/FooServer/src/REST/RESTServerConnection.cpp
	Submodule/FooServer/src/REST/yuarel.c
	Submodule/FooServer/src/Telnet/CmdLineBuffer.cpp
	Submodule/FooServer/src/Telnet/CmdLineBuffer.cpp
	Submodule/FooServer/src/Telnet/CmdLineHelp.cpp
	Submodule/FooServer/src/Telnet/CmdLineMgr.cpp
	Submodule/FooServer/src/Telnet/CmdLineRegistry.cpp
	Submodule/FooServer/src/Telnet/TelnetServerConnection.cpp
	Submodule/FooServer/src/Telnet/libtelnet.c
	Submodule/FooServer/src/hash-library/sha256.cpp
	Submodule/FooServer/src/TimeStamp.cpp
	Submodule/FooServer/src/LogMgr.cpp
	)

add_executable(demoserver ${SOURCES})


set_target_properties(demoserver PROPERTIES
				CXX_STANDARD 17
				CXX_EXTENSIONS OFF
				)
 
set_target_properties(demoserver PROPERTIES
			OUTPUT_NAME "demoserver"
			)

			  
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories(/usr/include)
link_directories(/usr/lib)
target_link_libraries(demoserver  Threads::Threads)

target_include_directories(demoserver
	PRIVATE
	src
	Submodule/FooServer/src
	Submodule/FooServer/src/hash-library
	Submodule/FooServer/src/REST
	Submodule/FooServer/src/Telnet

	)

set(CMAKE_BINARY_DIR "bin")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
