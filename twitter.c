/*****************************
John's bad ass command line twitter client

make sure to allways add -lcurl to gcc when compiling

***************************** */


#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

void curl_request( char *username, char *password)
{
  CURL *curl;
  CURLcode res;
  char user_pwd[255];
  char response[255];
  
  curl = curl_easy_init();
  
  if (curl){

    strcat(username, ":");
    strcpy(user_pwd, strcat(username, password));

    curl_easy_setopt(curl, CURLOPT_URL, "http://twitter.com/statuses/friends_timeline.xml");
    curl_easy_setopt(curl, CURLOPT_USERPWD, user_pwd);
    //    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, write_data);
    res = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
  }
 
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  printf stream;
}

int main()
{
  char username[255];
  char password[20];
  //  char response[4000];
  printf ( "Twitter Client in C \n");
  printf ( "Username:" );
  fgets( username, 20, stdin );
  printf ("Password:");
  fgets( password, 20, stdin );
  printf ("this is the output: %s\n", username);

  //test = curl_request(username, password);
  curl_request(username, password);
  //   printf ("hi there %s \n", response);
  return 0;
}
