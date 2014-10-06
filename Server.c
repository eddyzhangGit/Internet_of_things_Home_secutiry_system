
function sendSMSStatus()
{
    //  putting "\"" simply allows the quotation mark to stay within the string
    //ie; local json = " { \"ala\" : "\wariya\" } means the json looks like --> {"ala":"wariya"}
    //ABOUT SENDHUB API --> 500 API Requests allowed per month
    // --> to find group ID, type,
    //https://api.sendhub.com/v1/groups/?username=6479229265&api_key=Your911464e291ee9739fc9e45e08714824477cd593a
    local json = "{\"contacts\": [\"+14166556473\" ],   \"text\":\"INTRUDER\"}";
    local req = http.post("https://api.sendhub.com/v1/messages/?username=6479229265&api_key=911464e291ee9739fc9e45e08714824477cd593a", 
        { "Content-Type" : "application/json" }, json );
          
    local res = req.sendsync();
    if(res.statuscode != 201) {
        server.log("Error sending SMS");
    }
    else
    {
        server.log("Sent SMS Door State");
    }
} 

device.on("senddata", function(data) {
  // Set URL to your web service

  local url = "http://rocky-earth-5231.herokuapp.com/";

 
  // Set Content-Type header to json
  local headers = { "Content-Type": "application/json" };
 
  // encode data and log
  local body = http.jsonencode(data);
  server.log(body);
  
  // send data to your web service
  http.post(url, headers, body).sendsync();
  
  //sending the text to my phone
  sendSMSStatus();
}); 


//--------------------------------------------------------------------------------------------------------
//Send SMS Door Status Message
//--------------------------------------------------------------------------------------------------------  
