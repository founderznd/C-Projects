/*
 * aufgabe6.cpp
 *
 *  Created on: 2014-4-15
 *      Author: nandi
 */

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main(int argc, char **argv) {

	int fd[2];
	char buf[40];
	pipe(fd);

	pid_t fpid = fork();

	if (fpid < 0)
		cout << "error im fork" << endl;
	else if (fpid == 0) {
		cout << "Kind spielt im Sandkasten" << endl;
		read(fd[0], buf, sizeof(buf));
		cout << "Kind hoert: " << buf << endl;
		cout << "Kind geht nach Hause" << endl;
		sleep(3);
	} else {
		cout << "Vater kocht Essen" << endl;
		sleep(3);
		write(fd[1], "Essen ist fertig!", 20);
		wait(NULL);
		cout << "Kind ist im Hause" << endl;
		cout << "Essen beginnen!" << endl;
	}
	return 0;
}

