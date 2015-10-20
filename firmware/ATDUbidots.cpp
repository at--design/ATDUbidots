#include "ATDUbidots.h"

http_header_t headers[3];

http_request_t request;
http_response_t response;



ATDUbidots::ATDUbidots(String variable_id, String token){
    _token = token;
    _variable_id = variable_id;
    http_header_t headersTemp[] = {
        //{ "Host", "things.ubidots.com" },     // Declare the host here if your Spark has DNS problems
        { "Content-Type", "application/json" },
        { "X-Auth-Token" , _token },
        { NULL, NULL } // NOTE: Always terminate headers will NULL
    };
    
    memcpy(headers, headersTemp, 3 * sizeof(http_header_t));
}

void ATDUbidots::connect(){
    request.port = 80;
    request.hostname = "things.ubidots.com";
    request.path = "/api/v1.6/variables/"+_variable_id+"/values";
}

void ATDUbidots::sendValue(float data){
    
    sprintf(resultstr, "{\"value\":%.4f}", data);
    request.body = resultstr;
    http.post(request, response, headers);
}