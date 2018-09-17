/*
 * core.c
 *
 *  Created on: May 31, 2015
 *      Author: gijs
 */

#include "core.h"

char* slotsFilePath;
#define MAX_LENGTH 1048576

int copyFile(char *srcFile, char *destinationFile) {
	char ch;
	FILE *source, *target;

	source = fopen(srcFile, "r");

	if (source == NULL) {
		syslog(LOG_INFO, "could not open source file: %s", srcFile);
		return 1;
	}

	target = fopen(destinationFile, "w");

	if (target == NULL) {
		fclose(source);
		syslog(LOG_INFO, "could not create destination file: %s", destinationFile);
		return 1;
	}

	while ((ch = fgetc(source)) != EOF)
		fputc(ch, target);

	syslog(LOG_INFO, "File copied from %s to %s.", srcFile, destinationFile);

	fclose(source);
	fclose(target);

	return 0;

}

char* getTokenValue(char* token) {
	if (token == NULL)
		return "";
	if (strcmp(token, "(null)") == 0 && strcmp(token, "\n") == 0)
		return "";
	return token;
}

int get_device_tree_overlay_count() {
	syslog(LOG_INFO, "%s", "get device tree overlay count");
	FILE *fh = fopen("/sys/devices/bone_capemgr.9/slots", "r");

	if (fh == NULL) {
		printf("failed to openfile\n");
		exit(1);
	}
	int nrOfOverlays = 0;
	char buf[1024];
	while (fgets(buf, sizeof buf, fh) != NULL) {
		nrOfOverlays++;
	}
	return nrOfOverlays;
}

int device_tree_overlay_equal(overlay* ol1, overlay* ol2) {
	syslog(LOG_INFO, "device tree overlay equal. %s-%s %s-%s", ol1->part_number, ol1->version,
			ol2->part_number, ol2->version);
	int equals = 0;
	if (ol1 == NULL || ol2 == NULL) {
		syslog(LOG_INFO, "%s",
				"Can't compare. Either ol1 or ol2 or both are NULL");
		return 0;
	}

	if (strcmp(ol1->part_number, ol2->part_number) == 0
			&& strcmp(ol1->version, ol2->version) == 0)
		equals = 1;
	return equals;
}

int unload_device_tree_overlay(int slot_nr) {
	pid_t pID = fork();
	if (pID == 0) {               // child
	   char cmd[100] = "echo ";
	   char nr[5];
	   sprintf(nr, "-%d", slot_nr);
	   strcat(cmd, nr);
	   strcat(cmd, " > ");
	   strcat(cmd, slotsFilePath);
	   char *name[] = {
	        "/bin/bash",
	        "-c",
			cmd,
	        NULL
	    };
	   chdir("/lib/firmware/");
	   execvp(name[0], name);
   }

	return 0;
}

int init_bbc_lib() {
	openlog("BBCLib", LOG_PID | LOG_CONS | LOG_NDELAY | LOG_NOWAIT, LOG_LOCAL0);
	syslog(LOG_INFO, "%s", "Starting BBCLib");
	slotsFilePath = "/sys/devices/bone_capemgr.9/slots";
	return 0;
}

