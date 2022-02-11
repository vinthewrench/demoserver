//
//  DemoSecretMgr.cpp
//  demoserver
//
//  Created by Vincent Moscaritolo on 2/10/22.
//

#include "DemoSecretMgr.hpp"

#include "LogMgr.hpp"

DemoSecretMgr::DemoSecretMgr(){
	 
}

bool DemoSecretMgr::apiSecretCreate(string APIkey, string APISecret){
 
	// this is not called in the demo.
	return false;
	
}

bool DemoSecretMgr::apiSecretDelete(string APIkey){
	// this is not called in the demo.
	return false;
}

bool DemoSecretMgr::apiSecretGetSecret(string APIkey, string &APISecret){
	
// given the APIkey return the proper APISecret
//  we are hardcoding it.
	
	if(APIkey == "test"){
		APISecret = "12345678";
		return true;
	}
	return false;
	
}

bool DemoSecretMgr::apiSecretMustAuthenticate(){	
	return true;
}
