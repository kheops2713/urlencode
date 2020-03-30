#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>

int main(int argc, char **argv)
{
  ssize_t urllen;
  char *output = NULL, toprocess[4096], *call;
  CURL *curl;

  call = basename(argv[0]);

  if (argc < 2) {
    urllen = fread (toprocess, 1, 4095, stdin);
  } else {
    strncpy (toprocess, argv[1], 4095);
    toprocess[4095] = '\0';
    urllen = strlen(toprocess);
  }

  curl = curl_easy_init();
  if (curl)
  {
    if (strncmp(call, "urlencode", 9) == 0) {
      output = curl_easy_escape (curl, toprocess, urllen);
    } else if (strncmp(call, "urldecode", 9) == 0) {
      output = curl_easy_unescape (curl, toprocess, urllen, NULL);
    }
    if (output)
    {
      printf ("%s", output);
      curl_free (output);
    }

    curl_easy_cleanup(curl);
  }
 
  return 0;
}
