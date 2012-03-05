// 
// Plod 0.1
// Written by Doug Molineux 3/5/2012
//
// Tries to understand feeds from internet
//
// Uses libcurl
//

#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

// define the max url size, this number COULD probably be around 2000, because
// a URL is usually not recommended to be larger than this, due to the limitation
// of IE 8
#define MAX_URL_SIZE 200

#define MAX_RESPONSE_SIZE 4000

char url[MAX_URL_SIZE];

// create variable that will hold the raw response
CURLcode response;

void getInput() {

	system("clear");

	printf("Plod v0.1 \n\n\tEnter URL:");

	scanf("%s", url);

}

void printResponse() {

	int i = 0;

	char tmp[MAX_RESPONSE_SIZE];

	// sprintf(tmp, "%d", response);

	for(i = 0; i < strlen(tmp); i++) {

		printf("%d", i);

	}

	// printf("%s", tmp);

}
 
int main(void) {
  
	CURL *curl;

	curl = curl_easy_init();

  	if(curl) {

		getInput();
    		
		curl_easy_setopt(curl, CURLOPT_URL, url);
    		
		response = curl_easy_perform(curl);

		printResponse();
    		
		// always cleanup  
    		curl_easy_cleanup(curl);
  	
	}

  	return 0;

}
