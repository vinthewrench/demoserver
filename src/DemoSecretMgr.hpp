//
//  DemoSecretMgr.hpp
//  demoserver
//
//  Created by Vincent Moscaritolo on 2/10/22.
//

#ifndef DemoSecretMgr_hpp
#define DemoSecretMgr_hpp

#include <stdio.h>

#include "ServerCmdQueue.hpp"
 
class DemoSecretMgr : public APISecretMgr {

public:
	DemoSecretMgr();
	
	virtual bool apiSecretCreate(string APIkey, string APISecret);
	virtual bool apiSecretDelete(string APIkey);
	virtual bool apiSecretGetSecret(string APIkey, string &APISecret);
	virtual bool apiSecretMustAuthenticate();
	
private:
 
};

#endif /* DemoSecretMgr_hpp */
