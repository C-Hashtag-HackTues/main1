#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void) {
	CURL* curl;
	FILE* fp;
	int result;


	fp = fopen("pollution.txt", "wb");


	curl = curl_easy_init();

	curl_easy_setopt(curl, CURLOPT_URL, "https://api.waqi.info/feed/sofia/?token=cb3d111a5e1e1d9a4c3212afd1b47bbe498e34ea");
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
	curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);


	result = curl_easy_perform(curl);

	if (result == CURLE_OK)
		printf("Download OK.\n");
	else
		printf("Error: %s\n", curl_easy_strerror(result));
	fclose(fp);

	curl_easy_cleanup(curl);



}
