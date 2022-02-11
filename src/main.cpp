//
//  main.cpp
//  demoServer
//
//  Created by Vincent Moscaritolo on 2/10/22.
//

#include <iostream>
#include "LogMgr.hpp"

#include "REST/RESTServerConnection.hpp"
#include "ServerNouns.hpp"


 
#define SHOULD_AUTHENTICATE 0

#if SHOULD_AUTHENTICATE
#include "DemoSecretMgr.hpp"
#endif


int main(int argc, const char * argv[]) {

 // 	LogMgr::shared()->_logFlags = LogMgr::LogLevelDebug;

	int restPort = 9000;
	
#if SHOULD_AUTHENTICATE
	// create a authentication  manager
	auto apiSecrets = new DemoSecretMgr();
	// create the server command processor
	auto cmdQueue = new ServerCmdQueue(apiSecrets);
#else
	// create the server command processor
	auto cmdQueue = new ServerCmdQueue(NULL);
#endif
	
	registerServerNouns();

	TCPServer rest_server(cmdQueue);
	rest_server.begin(restPort, true, [=](){
		return new RESTServerConnection();
	});

	
	// run the main loop.
	while(true) {

		sleep(2);
	}

	
	return 0;
}
