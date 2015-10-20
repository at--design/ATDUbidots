#ifndef ATDUbidots_h
#define ATDUbidots_h


//needs to be included!!!!
#include "HttpClient/HttpClient.h"

class ATDUbidots{
    
public:
    ATDUbidots(String variable_id, String token);
    void connect();
    void sendValue(float data);
    
    
protected:
    String _variable_id;
    String _token;
    
private:
    HttpClient http;
    char resultstr[64];
    
};

#endif