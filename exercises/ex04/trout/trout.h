#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/un.h>
#include <stdarg.h>
#include <syslog.h>

#define MAXLINE 4096
#define BUFSIZE 1500




typedef struct rec {                /* outgoing UDP data */
  u_short seq;          /* sequence number */
} Rec;

typedef struct timeval Timeval;
typedef struct sockaddr Sockaddr;

/* the following are a few definitions from Stevens' unp.h */

typedef	void Sigfunc(int);        /* for signal handlers */

#define max(a,b) ((a) > (b) ? (a) : (b))

/* I commented out functions one by one while compiling, and these 3 were the ones that gave me any warnings or errors when removed */

char *Sock_ntop_host(const struct sockaddr *sa, socklen_t salen);
void *Calloc(size_t n, size_t size);
struct addrinfo *Host_serv(const char *host, const char *serv,
			   int family, int socktype);


/* variables we might want to configure */
int max_ttl;// = 30;
int nprobes;// = 2;

/* other global variables */

int seq;// = 0;

char recvbuf[BUFSIZE];
char sendbuf[BUFSIZE];
Rec *rec;// = (Rec *) sendbuf;

int sendfd, recvfd;
int pipefd[2];              /* the pipe for the alarm handler */

Sockaddr *sasend;    /* socket addresses for various purposes */
Sockaddr *sarecv;
Sockaddr *salast;
Sockaddr *sabind;

socklen_t salen;                    /* length of a socket address */
int datalen;// = sizeof (Rec);         /* length of the data in a datagram */

u_short sport;                      /* source UDP port # */
u_short dport;// = 32768 + 668;        /* destination port -- hopefully unused */
                                    /* 668 = the neighbor of the beast */
Timeval sendtv[1];
Timeval recvtv[1];
Timeval difftv[1];
