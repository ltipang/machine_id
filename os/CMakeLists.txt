IF(UNIX OR OPENSSL_FOUND)
	IF(UNIX)
	#linux/cpu_info.cpp
		add_library(os OBJECT
		    linux/dmi_info.cpp
		    linux/network.cpp
		    linux/os_linux.cpp) 
	ELSE(UNIX)
	    #windows and openssl
  	    add_library(os OBJECT 
  	    windows/cpu_info.cpp
  	    windows/dmi_info.cpp  
     	windows/isvm/Native.cpp
        windows/isvm/BIOSReader.cpp
  	    windows/os_win.cpp
  	    windows/network.cpp)
	ENDIF(UNIX)
	target_include_directories(os PUBLIC ${OPENSSL_INCLUDE_DIR})
ELSE(UNIX OR OPENSSL_FOUND)
#windows no openssl
    add_library(os OBJECT
        windows/cpu_info.cpp
        windows/dmi_info.cpp 
        windows/isvm/Native.cpp
        windows/isvm/BIOSReader.cpp
        windows/os_win.cpp
        windows/network.cpp)
ENDIF(UNIX OR OPENSSL_FOUND)

if(CODE_COVERAGE AND UNIX)
	  target_compile_options(os PUBLIC -O0 -g --coverage)
endif(CODE_COVERAGE AND UNIX)